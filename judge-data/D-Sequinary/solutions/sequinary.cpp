/*
 * Sequinary - GNY Regional 2021 - John Buck
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#include <numeric>
#include <algorithm>

using namespace std;

typedef unsigned long long LLTYPE;

#define	MAX_SEQ		32
int n = 0;
int nidx = MAX_SEQ;
LLTYPE nDigs[MAX_SEQ];
LLTYPE pown[MAX_SEQ];
LLTYPE powd[MAX_SEQ];
LLTYPE curn = 3;
LLTYPE curd = 2;
LLTYPE sum = 0;

int main()
{
	int c, i;
	LLTYPE w, r, d;

	while((c = getc(stdin)) >= '0' && c <= '2'){
		if(n == 0){
			pown[0] = 1;
			powd[0] = 1;
		}
		else {
			pown[n] = curn;
			powd[n] = curd;
			curn *= 3;
			curd *= 2;
		}
		nDigs[--nidx] = (LLTYPE)(c - '0');
		n++;
	}

	/* Common denom */
	curd = powd[n - 1];

	/* Convert fractions to common denom */
	for(i = 0; i < n; i++){
		pown[i] = pown[i] * (curd / powd[i]);
		sum += pown[i] * nDigs[nidx + i];
	}
	w = sum / curd;
	r = sum % curd;
	printf("%llu", w);
	if(r != 0){
		/* Get gcd */
		d = std::gcd(r, curd);
		printf(" %llu/%llu ", r/d, curd/d);
	}
	putc('\n', stdout);
	return(0);
}
