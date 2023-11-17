/*
 * Checker Slide
 * Author: Fred Pickel
 * ICPC GNYR 2021 Regional Contest
 * 
 * This is basically a breadth first search problem with big data
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
//#define DEBUG
//#define TEST
//#define	SHOWS

typedef unsigned int DWORD;
typedef unsigned char BYTE;

#define MIN_CARD 4
#define MAX_CARD 20
char inbuf[256];

typedef struct _slide_pos_
{
	DWORD level;
	DWORD qNext;
	DWORD pathPrev;
} SLIDEPOS, *PSLIDEPOS;

typedef struct _pos_loc_
{
	BYTE chks[4];
} POS_LOC;

#define	POS_CNT (36*36*36*36)

/* This is absolutely terrible. */
#define FLAG (0xffffffff)

SLIDEPOS posTbl[POS_CNT];

int AddrToPos(DWORD addr, POS_LOC *ppos)
{
	ppos->chks[3] = (BYTE)(addr %36);
	addr = addr/36;
	ppos->chks[2] = (BYTE)(addr %36);
	addr = addr/36;
	ppos->chks[1] = (BYTE)(addr %36);
	addr = addr/36;
	ppos->chks[0] = (BYTE)(addr %36);
	return 0;
}

int GetAddr(POS_LOC pos, DWORD *pAddr)
{
	DWORD res;
	int i, j;
	BYTE t;

	// sort in decreasing order
	for(j = 2; j >= 0; j--) {
		for(i = 0; i <= j; i++) {
			if(pos.chks[i] < pos.chks[i+1]) {
				t = pos.chks[i];
				pos.chks[i] = pos.chks[i+1];
				pos.chks[i+1] = t;
			} else if(pos.chks[i] == pos.chks[i+1]){ // invalid
				return -11;
			}
		}
	}
	res = pos.chks[0];
	res = res*36 + pos.chks[1];
	res = res*36 + pos.chks[2];
	res = res*36 + pos.chks[3];
	*pAddr = res;
	return 0;
}


int StrToAddr(const char *str, DWORD *pAddr)
{
	int i, rowcol[8];
	POS_LOC pos;
	if(sscanf(str, "%d %d %d %d %d %d %d %d",
		&rowcol[0], &rowcol[1], &rowcol[2], &rowcol[3], 
		&rowcol[4], &rowcol[5], &rowcol[6], &rowcol[7]) != 8) {
		fprintf(stderr, "Bad scan of input data\n");
		return -21;
	}
	for(i = 0; i < 4; i++) {
		pos.chks[i] = 6*rowcol[2*i] + rowcol[2*i+1];
	}
	return GetAddr(pos, pAddr);
}

int AddrToStr(DWORD addr, char *pres)
{
	int i, rowcol[8];
	for(i = 7; i >= 0 ; i--) {
		rowcol[i] = addr % 6;
		addr /= 6;
	}
	sprintf(pres, "%d%d%d%d%d%d%d%d",
		rowcol[0], rowcol[1], rowcol[2], rowcol[3], 
		rowcol[4], rowcol[5], rowcol[6], rowcol[7]);
	return 0;
}

DWORD startAddr, endAddr, qHead, qTail, maxLevel;
int nSolnSteps, bSolution;

int GenMoves(DWORD curAddr)
{
	POS_LOC pos, newpos;
	BYTE rowcol[8], bd[6][6], val, currow, curcol, row, col;
	int i, j, ret;
	DWORD addr, level;
	level = posTbl[curAddr].level + 1;
	AddrToPos(curAddr, &pos);

	memset(&(bd[0][0]), '\0', sizeof(bd));

	for(i = 0; i < 4; i++) {
		val = pos.chks[i];
		rowcol[2*i+1] = val %6;
		rowcol[2*i] = val/6;
		bd[val/6][val %6] = 1;
	}
	// now find moves up to 4 per piece
	for(i = 0; i < 4; i++) {
		currow = rowcol[2*i];
		curcol = rowcol[2*i+1];
		// up?
		if((currow > 0) && (bd[currow - 1][curcol] == 0)){
			newpos = pos;
			col = curcol;
			row = 0;
			for(j = currow - 1; j >= 0 ; j--) {
				if(bd[j][col] != 0) {
					row  = j+1;
					break;
				}
			}
			newpos.chks[i] = row*6 + col;
			if((ret = GetAddr(newpos, &addr)) != 0) {
				return -31;
			}
			if(endAddr == addr) {	// found it
				posTbl[addr].pathPrev = curAddr;
				return level;
			}
			if(posTbl[addr].level == FLAG) {	// not already seen
				posTbl[qTail].qNext = addr;
				qTail = addr;
				posTbl[addr].level = level;
				posTbl[addr].pathPrev = curAddr;
			}
		}
		// down?
		if((currow < 5) && (bd[currow + 1][curcol] == 0)){
			newpos = pos;
			col = curcol;
			row = 5;
			for(j = currow + 1; j <= 5 ; j++) {
				if(bd[j][col] != 0) {
					row  = j-1;
					break;
				}
			}
			newpos.chks[i] = row*6 + col;
			if((ret = GetAddr(newpos, &addr)) != 0) {
				return -32;
			}
			if(endAddr == addr) {	// found it
				posTbl[addr].pathPrev = curAddr;
				return level;
			}
			if(posTbl[addr].level == FLAG) {	// not already seen
				posTbl[qTail].qNext = addr;
				qTail = addr;
				posTbl[addr].level = level;
				posTbl[addr].pathPrev = curAddr;
			}
		}
		// left?
		if((curcol > 0) && (bd[currow][curcol-1] == 0)){
			newpos = pos;
			col = 0;
			row = currow;
			for(j = curcol - 1; j >= 0 ; j--) {
				if(bd[row][j] != 0) {
					col  = j+1;
					break;
				}
			}
			newpos.chks[i] = row*6 + col;
			if((ret = GetAddr(newpos, &addr)) != 0) {
				return -33;
			}
			if(endAddr == addr) {	// found it
				posTbl[addr].pathPrev = curAddr;
				return level;
			}
			if(posTbl[addr].level == FLAG) {	// not already seen
				posTbl[qTail].qNext = addr;
				qTail = addr;
				posTbl[addr].level = level;
				posTbl[addr].pathPrev = curAddr;
			}
		}
		// rt?
		if((curcol < 5) && (bd[currow][curcol + 1] == 0)){
			newpos = pos;
			col = 5;
			row = currow;
			for(j = curcol + 1; j <= 5 ; j++) {
				if(bd[row][j] != 0) {
					col  = j-1;
					break;
				}
			}
			newpos.chks[i] = row*6 + col;
			if((ret = GetAddr(newpos, &addr)) != 0) {
				return -34;
			}
			if(endAddr == addr) {	// found it
				posTbl[addr].pathPrev = curAddr;
				return level;
			}
			if(posTbl[addr].level == FLAG) {	// not already seen
				posTbl[qTail].qNext = addr;
				qTail = addr;
				posTbl[addr].level = level;
				posTbl[addr].pathPrev = curAddr;
			}
		}
	}
	return 0;
}


int Solve()
{
	DWORD curAddr;
	int lev;
	DWORD newlev;
	memset(&(posTbl[0]), 0xff, POS_CNT*sizeof(SLIDEPOS));
	curAddr = startAddr;
	posTbl[curAddr].level = 0;
	qHead = qTail = curAddr;
	lev = 0;
	newlev = 0;
	bSolution = 0;
	while((lev == 0) && (qHead != FLAG)) {
		lev = GenMoves(qHead);
		qHead = posTbl[qHead].qNext;
		if(qHead != FLAG) {
			if(posTbl[qHead].level != newlev) {
				newlev = posTbl[qHead].level;
//				printf("lev %d\r\n", newlev);
			}
			if(newlev > maxLevel) {
				return newlev;
			}
		}

	}
	if(lev > 0) {
		nSolnSteps = lev;
		bSolution = 1;
	}
	return lev;
}

void ShowDiffs(char *s1, char *s2)
{
	int i, j;
	unsigned char uc1 = 0, uc2 = 0;

	for(i = 0; i < 8; i += 2){
		for(j = 0; j < 8; j += 2){
			if(s1[i] == s2[j] && s1[i+1] == s2[j+1]){
				uc1 |= (1<<(i/2));
				uc2 |= (1<<(j/2));
			}
		}
	}
#ifdef DEBUG
	printf("uc1=%x uc2=%x\n", uc1, uc2);
#endif
	for(i = 0; i < 4; i++){
		if((uc1 & (1<<i)) == 0){
			printf("%c %c ", s1[i*2], s1[i*2+1]);
			break;
		}
	}
	for(i = 0; i < 4; i++){
		if((uc2 & (1<<i)) == 0){
			printf("%c %c\n", s2[i*2], s2[i*2+1]);
			break;
		}
	}
}

void ShowSoln(char *szStart, int cnt)
{
	char *p;
	char **addrs;
	DWORD curAddr;
	int idx = cnt;

	addrs = new char *[cnt];
	if(addrs == NULL){
		fprintf(stderr, "memory alloc error in show soln\n");
		return;
	}
	
	curAddr = endAddr;
	while(curAddr != startAddr) {
		if(idx == 0){
			fprintf(stderr, "count ran out!\n");
			return;
		}
		p = new char[16];
		if(p == NULL){
			fprintf(stderr, "memory alloc error 2 in show soln\n");
			return;
		}
		AddrToStr(curAddr, p);
		addrs[--idx] = p;
		curAddr = posTbl[curAddr].pathPrev;
	}
	if(idx != 0){
		fprintf(stderr, "Extra slots in show soln\n");
		return;
	}
	for(idx = 0; idx < cnt; idx++){
#ifdef DEBUG
		printf("%d: %s %s\n", idx, szStart, addrs[idx]);
#endif
		ShowDiffs(szStart, addrs[idx]);
		if(idx > 0){
			delete [] szStart;
		}
		szStart = addrs[idx];
	}
}

int main()
{
	int ret, cnt;
	char szStart[32];
#ifdef TEST
	int nprob, curprob, probnum, problines;
	if(fgets(&(inbuf[0]), 255, stdin) == NULL) {
		fprintf(stderr, "read failed on problem count\n");
		return -1;
	}
	if(sscanf(&(inbuf[0]), "%d", &nprob) != 1){
		fprintf(stderr, "scan failed on problem count\n");
		return -2;
	}
	for(curprob = 1; curprob <= nprob  ;  curprob++) {
		if(fgets(&(inbuf[0]), 255, stdin) == NULL) {
			fprintf(stderr, "read failed on problem num & sz\n");
			return -3;
		}
		if(sscanf(&(inbuf[0]), "%d %d", &probnum, &problines) != 2){
			fprintf(stderr, "scan failed on num & sz\n");
			return -4;
		}
#endif
	maxLevel = 50;
	if(fgets(&(inbuf[0]), 255, stdin) == NULL) {
		fprintf(stderr, "read failed on start pos\n");
		return -7;
	}
	if((ret = StrToAddr(&(inbuf[0]), &startAddr)) != 0) {
		fprintf(stderr, "scan of start pos ret %d\n", ret);
		return -8;
	}
	if(fgets(&(inbuf[0]), 255, stdin) == NULL) {
		fprintf(stderr, "read failed on end pos\n");
		return -7;
	}
	if((ret = StrToAddr(&(inbuf[0]), &endAddr)) != 0) {
		fprintf(stderr, "scan of end pos ret %d\n", ret);
		return -10;
	}
	cnt = Solve();
#ifdef TEST
	printf("%d: %d\n", curprob, cnt);
	if((cnt > 0) && (cnt < (int)maxLevel)) {
		ShowSoln(cnt);
	}
	}
#else
	if(bSolution){
		printf("%d\n", cnt);
		if((cnt > 0) && (cnt < (int)maxLevel)) {
			AddrToStr(startAddr, &(szStart[0]));
			ShowSoln(szStart, cnt);
		}
	} else {
		printf("no solution in %d levels\n", maxLevel);
	}
#endif
	return 0;
}
