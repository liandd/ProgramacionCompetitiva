/*
 * Pooling PCR Tests - Fred Pickel, GNY Regional 2021
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

//#define TEST

int GetBest(double prob)
{
	double best, probnot, dn, cur;
	int bestind, i;
	probnot = (1.0 - prob)*(1.0 - prob);
	bestind = 1;
	best = 1.0;
	for(i = 2; i <= 16; i++) {
		dn = i;
		cur = probnot/dn + 1.0 - probnot;
//		printf("%lf\n", cur);
		if(cur < best) {
			bestind = i;
			best = cur;
		}
		probnot *= (1.0 - prob);
	}

	return bestind;
}

char inbuf[256];
int main()
{
	double prob;
	int ret;
#ifdef TEST
	while(1) {
#endif
	if(fgets(&(inbuf[0]), 255, stdin) == NULL) {
		fprintf(stderr, "read failed on dimensions\n");
		return -2;
	}
	if(sscanf(&(inbuf[0]), "%lf", &prob) != 1) {
		fprintf(stderr, "scan failed on input probability\n");
		return -3;
	}
	if((prob <= 0.0) || (prob >= 1.0)) {
		fprintf(stderr, "probability no in range 0.0 -> 1.0\n");
		return -4;
	}
	if((ret = GetBest(prob)) < 0) {
		fprintf(stderr, "Get error %d\n", ret);
		return ret;
	}
	printf("%d\n", ret);
#ifdef TEST
	}
#endif
	return 0;
}



