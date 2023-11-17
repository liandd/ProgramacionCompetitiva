/*
 * Neighbors - GNY Regional 2021 - Fred Pickel
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

//#define DEBUG
//#define FIND_ALL
//#define ONE_SHOT

typedef unsigned short WORD;
typedef unsigned char BYTE;
char inbuf[256];

int nVals;
int  initCnt;
/*
 * this is a standard recursive sudoku solver with two additions
 * 1. An initial scan of the sum constraints to see if they restrict the
 *		available values in each box (check_constraints)
 * 2. at each recursive search step, once we have set a value in a row & col
 *		and used sudoku constrints to remove available values in the row, col and 3x3 box
 *		scan through the sum constraints to see if they further restrict the
 *		available values in each box (check_constraints)
 */

int constraints[32][16];

WORD valid_masks[17] = 
	{0, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80,
		0x0100, 0x0200, 0x0400, 0x0800, 0x1000, 0x2000, 0x4000, 0x8000};
WORD allMasks[17] = 
{
	0, 0x0001, 0x0003, 0x0007, 0x000f,
		0x001f, 0x003f, 0x007f, 0x00ff,
		0x01ff, 0x03ff, 0x07ff, 0x0fff,
		0x1fff, 0x3fff, 0x7fff, 0xffff,
};

#define ALL_MASK	(allMasks[nVals])

/* flags for whether difference is neighbor or not */
WORD nbrDiff[17] =
{
	0, 0x0002, 0x0005, 0x000a, 0x0014, 0x0028, 0x0050, 0x00a0, 0x0140,
		0x0280,  0x0500, 0x0a00, 0x1400, 0x2800, 0x005000, 0xa000, 0x4000
}; 

WORD nonnbrDiff[17] =
{
	0, 0xfffc, 0xfff8, 0xfff1, 0xffe3, 0xffc7, 0xff8f, 0xff1f, 0xfe3f,
		0xfc7f, 0xf8ff, 0xf1ff, 0xe3ff, 0xc7ff, 0x8fff, 0x1fff, 0x3fff
}; 

/*
 * depth first search stack struct for sudoku
 */
typedef struct _search_state_
{
	WORD avail_mask[16][16];	// which values (valid_masks) can still be used in thsi box
	BYTE row_avail_counts[19][16];	// for each row, counts of how many boxes in the row have each value available
	BYTE col_avail_counts[16][16];	// for each col, counts of how many boxes in the col have each value available
	BYTE val_set[16][16];	// if non-zero, this box is set t the current value in the current search
} SEARCH_STATE;

SEARCH_STATE states[256];

/*
 * intialize the search stack to no values chosen and all values available
 * in all boxes
 */
void search_init()
{
	SEARCH_STATE *pss = &(states[0]);
	int i, j;
	for(i = 0; i < nVals; i++) {
		for(j = 0; j < nVals ; j++) {
			pss->avail_mask[i][j] = ALL_MASK;
			pss->val_set[i][j] = 0;
			pss->row_avail_counts[i][j] = nVals;
			pss->col_avail_counts[i][j] = nVals;
		}
	}
}

/*
 * convert string of 0, or 1 to array of 0 or 1
 */
int scan_convert(int *prow, int n, const char *s)
{
	int i;

	for(i = 0; i < n; i++, s++){
		switch(*s){
		case '0': *prow++ = 0; break;
		case '1': *prow++ = 1; break;
		default: return(i);
		}
	}
	return(i);
}

// read constraints from stdin
int scan_constraints()
{
	int i, j, n;
	for(i = 0, j = 0; i < nVals; i++) {
		if(fgets(&(inbuf[0]), 255, stdin) == NULL)
		{
			fprintf(stderr, "Read of row %d constraints failed\n", i+1);
			return -21;
		}
		n = scan_convert(&(constraints[j][0]), nVals - 1, &(inbuf[0]));
		if(n != nVals-1){
			fprintf(stderr, "Scan of row %d constraints failed got %d wanted %d: %s", i+1, n, nVals - 1, &(inbuf[0]));
			return(-22);
		}
		j++;
		if(i < nVals-1) {
			if(fgets(&(inbuf[0]), 255, stdin) == NULL)
			{
				fprintf(stderr, "Read of constraints between %d and %d failed\n", i+1, i+2);
				return -23;
			}
			n = scan_convert(&(constraints[j][0]), nVals, &(inbuf[0]));
			if(n != nVals) {
				fprintf(stderr, "Scan of constraints between %d and %d faile got %d wanted %d: %s\n", i+1, i+2, n, nVals, &(inbuf[0]));
				return -24;
			}
			j++;
		}
	}
	return 0;
}

/*
 * determine if any values available in the current box (baseMask) can
 * be excluded by applying constraint with the available values in the neighboring box (chkMask)
 * return mask of values to be REMOVED
 */
WORD checkConstraint(int constraint, WORD baseMask, WORD chkMask)
{
	WORD *pTest, result = 0;
	int i;
	if(constraint == 0) {
		pTest = &(nonnbrDiff[0]);
	} else if(constraint == 1) {
		pTest = &(nbrDiff[0]);
	}
	// if a val is avail but cannot match nbr flag as not useable
	for(i = 1; i <= nVals ; i++) {
		if(((valid_masks[i] & baseMask) != 0) && ((pTest[i] & chkMask) == 0)) {
			result |= valid_masks[i];
		}
	}
	return result;
}

/*
 * for each box, check if constraints with respect to neighboring boxes eliminate
 * any available values
 * return -1 if some box has no remaining available values
 */
int check_constraints(SEARCH_STATE *pss)
{
	int i, row, col, baseConsRow, scan_count, change_count = 1;
	WORD baseMask, chkMask, resultMask, totResult;
	scan_count = 0;
	// scan all constraints until no more changes
	while(change_count > 0) {
		scan_count++;
		change_count = 0;
		baseConsRow = 0;
		for(row = 0; row < nVals ; row++) {
			for(col = 0 ; col < nVals ; col++) {
				if(pss->val_set[row][col] == 0) {	// if we have not already set this box in search see if it can change
					baseMask = pss->avail_mask[row][col];
					totResult = 0;	// all changes to baseMask
					if(col != 0) {	// if not first col check constraint with box to left
						chkMask = pss->avail_mask[row][col-1];
						resultMask = checkConstraint(constraints[baseConsRow][col-1], baseMask, chkMask);
						if(resultMask != 0) {
							baseMask &= ~resultMask;
							change_count++;
							totResult |= resultMask;
						}
					}
					if(col < (nVals - 1)) {
						// do col to right
						chkMask = pss->avail_mask[row][col+1];
						resultMask = checkConstraint(constraints[baseConsRow][col], baseMask, chkMask);
						if(resultMask != 0) {
							baseMask &= ~resultMask;
							change_count++;
							totResult |= resultMask;
						}
					}
					if(row != 0) {	// if not top row, check constraint with row above
						chkMask = pss->avail_mask[row-1][col];
						resultMask = checkConstraint(constraints[baseConsRow-1][col], baseMask, chkMask);
						if(resultMask != 0) {
							baseMask &= ~resultMask;
							change_count++;
							totResult |= resultMask;
						}
					}
					if(row != (nVals - 1)) {	// if not bottom row, check constraint with box below
						chkMask = pss->avail_mask[row+1][col];
						resultMask = checkConstraint(constraints[baseConsRow+1][col], baseMask, chkMask);
						if(resultMask != 0) {
							baseMask &= ~resultMask;
							change_count++;
							totResult |= resultMask;
						}
					}
					if(baseMask == 0) {	// not already set and no values available for box
						return -1;
					}
					pss->avail_mask[row][col] = baseMask; 
					if(totResult != 0) {	// adjust counts for boxes in same row, col or 3x3 box
						for(i = 1; i <= nVals ; i++) {
							if(valid_masks[i] & totResult) {
								pss->col_avail_counts[col][i-1]--;
								pss->row_avail_counts[row][i-1]--;
							}
						}
					}
				}
			}
			baseConsRow += 2;
		}
	}
	return 0;
}

/*
 * depth first search step choice info
 */
#define STYP_ROW	1	// depth first search on boxes with a value available in a given row
#define STYP_COL	2	// depth first search on boxes with a value available in a given col
#define STYP_BOX	3	// depth first search on boxes with a value available in a given 3x3 box
typedef struct _solve_data_ {
	int solve_type;	//STYP_?
	int solve_val;	// value to be set 1-9
	int solve_row;	// row for row scan (0-8) or box row (0-2) for box unused for col
	int solve_col;	// col for col scan (0-8) or box col (0-2) for box unused for row
	int solve_cnt;	// number of boxes in set with val available
	int solve_index;	// which of solve_cnt boxes we are trying (init 0)
	int test_row;	// actual row and col to set to val
	int test_col;
} SOLVE_DATA;

/*
 * choose how to branch for the next sudoku depth first search step
 * choose the branching with the smallest number of children in the tree
 * either the sammlest number of values still available in a box (row & col)
 * or the smallest number of boxes in a row, col or 3x3 sub-box with a particular value available
 * on return *psd has the information on the branch choice
 */
int GetSolveStep(SEARCH_STATE *pss, SOLVE_DATA *psd)
{
	int i, j;
	psd->solve_cnt = nVals+1;
	for(i = 0; i < nVals; i++) {
		for(j = 0; j < nVals; j++) {
			if(pss->row_avail_counts[i][j] < psd->solve_cnt) {
				psd->solve_cnt = pss->row_avail_counts[i][j];
				psd->solve_type = STYP_ROW;
				psd->solve_row = i;
				psd->solve_val = j+1;
			}
		}
	}
	for(i = 0; i < nVals; i++) {
		for(j = 0; j < nVals; j++) {
			if(pss->col_avail_counts[i][j] < psd->solve_cnt) {
				psd->solve_cnt = pss->col_avail_counts[i][j];
				psd->solve_type = STYP_COL;
				psd->solve_col = i;
				psd->solve_val = j+1;
			}
		}
	}
	if(psd->solve_cnt == 0) {	// if some value has no choices left, fail
		return -1;
	} else {
		return 0;
	}
}

/*
 * after we have made a branch choice, we have to try each of the branches
 * at the search node bay scanning through boxes in the selected row, col or 3x3 box
 * or values within a selected box, thsi routine steps to the next choice
 * for first try, start with 0, else start with location after previous try
 * and scan to the next available box or value
 */
int FindNextTest(SEARCH_STATE *pss, SOLVE_DATA *psd)
{
	int i, j, starti, startj;
	WORD mask = valid_masks[psd->solve_val];
	if(psd->solve_index >= psd->solve_cnt) {
		return -1;
	}
	switch(psd->solve_type) {
	case STYP_ROW:
		if(psd->solve_index == 0) {
			startj = 0;
		} else {
			startj = psd->test_col+1;
		}
		i = psd->solve_row;
		for(j = startj ; j < nVals ; j++) {
			if(pss->avail_mask[i][j] & mask) {
				psd->test_col = j;
				psd->test_row = i;
				psd->solve_index++;
				return 0;
			}
		}
		return -1;
	case STYP_COL:
		if(psd->solve_index == 0) {
			starti = 0;
		} else {
			starti = psd->test_row+1;
		}
		j = psd->solve_col;
		for(i = starti ; i < nVals ; i++) {
			if(pss->avail_mask[i][j] & mask) {
				psd->test_col = j;
				psd->test_row = i;
				psd->solve_index++;
				return 0;
			}
		}
		return -1;
	default:
		fprintf(stderr, "bad solve type %d\n", psd->solve_type);
		return -1;
	}
}

/*
 * apply a choice to set a box at row, col,to value
 * then clear all other avail masks at row, col and
 * apply sudoku constraints to decrement counts
 * for other boxes in row, col and 3x3 box not already set,
 * remove val from avail_masks and decrement counts
 */
int ApplyChoice(SEARCH_STATE *pss, int row, int col, int val)
{
	int i, j;
	WORD mask = valid_masks[val];
	if(pss->val_set[row][col] != 0) {
		fprintf(stderr, "ApplyChoice: row %d col %d val %d already set to %d\n", row, col, val, pss->val_set[row][col]);
		return -1;
	}
	pss->val_set[row][col] = val;
	// remove val from other avails in row, col and box
	for(j = 0; j < nVals ; j++) {
		if(pss->avail_mask[row][j] & mask) {	// reduce counts
			pss->col_avail_counts[j][val-1]--;
		}
		pss->avail_mask[row][j] &= ~mask;
	}
	for(i = 0; i < nVals ; i++) {
		if(pss->avail_mask[i][col] & mask) {
			pss->row_avail_counts[i][val-1]--;
		}
		pss->avail_mask[i][col] &= ~mask;
	}
	//for each other value at row/col, decrement ist counts
	for(i = 1; i <= nVals ; i++) {
		if((i != val) && ((pss->avail_mask[row][col] & valid_masks[i]) != 0)){
			pss->col_avail_counts[col][i-1]--;
			pss->row_avail_counts[row][i-1]--;
		}
	}
	pss->avail_mask[row][col] = mask;	// no one can use it but we need to tell neighbors that other vals not avail
	pss->row_avail_counts[row][val-1] = 64;	// never choose the row and val again
	pss->col_avail_counts[col][val-1] = 64;	// never choose the col and val again
	return 0;
}

#ifdef DEBUG
// This is a hack used to find an error
// it tests the sample solution against the current avail_masks
// to see if it could still be found
// this will fail during search when you go down the wrong path
// but should work on the solution path
int soln[7][7] =
{
	{3, 5, 6, 1, 2, 7, 4},
	{2, 7, 5, 4, 6, 1, 3},
	{4, 6, 1, 3, 7, 5, 2},
	{7, 2, 4, 5, 3, 6, 1},
	{6, 4, 3, 7, 1, 2, 5},
	{5, 1, 2, 6, 4, 3, 7},
	{1, 3, 7, 2, 5, 4, 6}

};

int check_soln(SEARCH_STATE *pss)
{
	int i, j, ret = 0;
	for(i = 0; i < nVals; i++) {
		for(j = 0; j < nVals ; j++) {
			if((pss->avail_mask[i][j] & valid_masks[soln[i][j]]) == 0) {
				printf("mismatch at row %d col %d\n", i, j);
				ret = -1;
			}
		}
	}
	return ret;
}
#endif

int solnCnt = 0;

void PrintSoln(SEARCH_STATE *pss)
{
	int i, j;
	printf("%d\n", solnCnt);
	for(i = 0; i < nVals ; i++) {
		for(j = 0; j < nVals ; j++) {
			printf("%d ", pss->val_set[i][j]);
		}
		printf("\n");
	}
}

/*
 * sudoku recursive step
 * at given level, copy current state to next slot, 
 * pick a branch row col or 3x3 box and value
 * if we are down the last choice (depth = 80) just set the (only remaining) choice and return 0
 * for each branch. set the value at the row & col to the appropriate value
 * and update avail counts to reflect sudoku constraints
 * then chack sum constraints
 * if any box has no more available values, go on to the next choice on the branch
 * else call Solve recursively
 * If the recursive call returns -1, go on to the next choice on the branch
 *  and if you run out of boxes return -1
 * if recursive call returns 0, copy soln (val_set from next slot to current and return 0
 * so when top level returns, val_set is the soln
 */
int Solve(int level)
{
	SEARCH_STATE *pssnxt, *pss = &(states[level]);
	SOLVE_DATA sd;
	int i, j;
	if(GetSolveStep(pss, &sd) != 0) {	// find row, col or 3x3 box) + value to scan
		return -1;
	}
#ifdef DEBUG
	printf("level %d solve type %d row %d col %d val %d cnt %d\n", level,
		sd.solve_type, sd.solve_row, sd.solve_col, sd.solve_val, sd.solve_cnt);
#endif
	sd.solve_index = 0;
	while(FindNextTest(pss, &sd) == 0) {	// for each candidate in chosen row, col or 3x3 box, get row& col to set
		if(level == nVals*nVals - initCnt - 1) {	// if this is the last box to fill in we are done, set it and return 0 (success)
			pss->val_set[sd.test_row][sd.test_col] = sd.solve_val;
#ifdef FIND_ALL
			solnCnt++;
			PrintSoln(pss);
			return -1;
#else
			return 0;
#endif
		} else {	// else copy current to next and try each possiblility
			pssnxt = &(states[level+1]);
			*pssnxt = *pss;
#ifdef DEBUG
			fprintf(stderr, "try row %d col %d val %d\n", sd.test_row, sd.test_col, sd.solve_val);
#endif
			if(ApplyChoice(pssnxt, sd.test_row, sd.test_col, sd.solve_val) == 0) { // set this value choice
#ifdef DEBUG
				check_soln(pssnxt);
#endif
				if(check_constraints(pssnxt) == 0) {	// if not killed by constraints	
#ifdef DEBUG
					check_soln(pssnxt);
#endif
					if(Solve(level+1) == 0) {	// call solve recursively, if success, copy val_set
						for(i = 0; i < nVals; i++) {
							for(j = 0; j < nVals ; j++) {
								pss->val_set[i][j] = pssnxt->val_set[i][j];
							}
						}
						return 0;
					}
				}
#ifdef DEBUG
			} else {
				fprintf(stderr, "Apply Choice failed at level %d \n", level);
#endif
			}
		}
	}
	return -1;
}

int main()
{
	int ret, i, row, col, val;
#ifndef FIND_ALL
	int j;
#endif
#ifdef ONE_SHOT
	int nprob, curprob, index;
	if(fgets(&(inbuf[0]), 255, stdin) == NULL)
	{
		fprintf(stderr, "Read failed on problem count\n");
		return -1;
	}
	if(sscanf(&(inbuf[0]), "%d", &nprob) != 1)
	{
		fprintf(stderr, "Scan failed on problem count\n");
		return -2;
	}
	for(curprob = 1; curprob <= nprob ; curprob++)
	{
		if(fgets(&(inbuf[0]), 255, stdin) == NULL)
		{
			fprintf(stderr, "Read failed on problem %d header\n", curprob);
			return -3;
		}
		// get prob num degree
		if(sscanf(&(inbuf[0]), "%d %d", &index, &i) != 2)
		{
			fprintf(stderr, "scan failed on problem header problem index %d\n",
				curprob);
			return -4;
		}
		if(index != curprob)
		{
			fprintf(stderr, "problem index %d not = expected problem %d\n",
				index, curprob);
			return -5;
		}
#endif
		if(fgets(&(inbuf[0]), 255, stdin) == NULL)
		{
			fprintf(stderr, "Read failed on initCnt\n");
			return -6;
		}
		// get initCnt and nVals
		if(sscanf(&(inbuf[0]), "%d %d", &nVals, &initCnt) != 2)
		{
			fprintf(stderr, "scan failed on nVals + initCnt\n");
			return -7;
		}
		if((nVals < 4) || (nVals > 16)) {
			fprintf(stderr, "nVals  %d not in range 4 .. 16\n",
				nVals);
			return -8;
		}
		if((initCnt < 0) || (initCnt > (nVals*nVals))) {
			fprintf(stderr, "init val cnt %d not in range 0 .. %d1\n",
				initCnt, nVals*nVals);
			return -8;
		}
		search_init();	// init first atate
		if((ret = scan_constraints()) != 0) {	// read constriants
			return ret;
		}
		if(check_constraints(&(states[0])) != 0) { // apply constraints to first state
			fprintf(stderr, "init check constraints failed\n");
			return -8;
		}
		for(i = 0; i < initCnt ; i++) {
			if(fgets(&(inbuf[0]), 255, stdin) == NULL)
			{
				fprintf(stderr, "Read failed on init val %d\n", i+1);
				return -9;
			}
			// get prob num degree
			if(sscanf(&(inbuf[0]), "%d %d %d", &row, &col, &val) != 3)
			{
				fprintf(stderr, "scan failed on init val %d\n", i+1);
				return -10;
			}
			if((row < 1) || (row > nVals) || (col < 1) || (col > nVals) || (val < 1) || (val > nVals)) {
				fprintf(stderr, "init val %d row %d col %d or val %d not in range 1 .. %d\n",
					i+1, row, col, val, nVals);
				return -11;
			}
			if(ApplyChoice(&(states[0]), row-1, col-1, val) != 0) {
				fprintf(stderr, "init val %d error adding row %d col %d or val %d\n",
					i+1, row, col, val);
				return -12;
			}
			if(check_constraints(&(states[0])) != 0) { // apply constraints to first state
				fprintf(stderr, "check constraints failed after init val %d\n",
					i+1);
				return -13;
			}
		}
#ifdef DEBUG
		if(check_soln(&(states[0])) != 0) {
			fprintf(stderr, "problem index %d after init check constraints no match\n",
				index);
			return -18;
		}
#endif
		solnCnt = 0;
#ifdef FIND_ALL
#ifdef ONE_SHOT
		printf("%d\n", index);
#endif
		Solve(0); 	// call solve
		if(solnCnt == 0) {
			fprintf(stderr, "no solution\n");
			return -39;
		}
#else
		if(Solve(0) != 0) {
			printf("no solutions\n");
			return -21;
		}
		// if it works, print out soln
#ifdef ONE_SHOT
		printf("%d\n", index);
#endif
		for(i = 0; i < nVals ; i++) {
			for(j = 0; j < nVals ; j++) {
				printf("%d ", states[0].val_set[i][j]);
			}
			printf("\n");
		}
#endif
#ifdef ONE_SHOT
	}
#endif
	return 0;
}

