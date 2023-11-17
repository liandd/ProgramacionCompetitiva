/*
 * Collatz Count - GNY Regional 2021 - Fred Pickel
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_N	40000
#define MODULUS	1000007

/*
 * let even[m] = # of even integers k for which S(k) = m and
 * let odd[m] = # of odd integers k for which S(k) = m
 * now if S(n) = m+1 then either (1)S(n+1) = m (n odd) or (2) S(n/2) = m (n even)
 * so (1) odd[m+1] = even[m] and (2) even[m+1] = even[m] + odd[m]
 * so Count(m+1) = even[m+1] + odd[m+1] = (even[m] + odd[m}) + even[m]
 *				 = Count(m) + even[m-1] + odd[m-1] = Count[m] + Count[m-1]
 */

typedef unsigned int DWORD;

DWORD Count[2*MAX_N];
int lastCount = 0;

void init()
{
	Count[0] = Count[1] = Count[2] = 1;
	lastCount = 2;
}

DWORD GetCount(int n)
{
	int i;
	if(lastCount < n) {
		for(i = lastCount+1; i <= n ; i++) {
#ifdef MODULUS
			Count[i] = (Count[i-1] + Count[i-2]) % MODULUS;
#else
			Count[i] = Count[i-1] + Count[i-2];
#endif
		}
		lastCount = n;
	}

	return Count[n];
}

int main()
{
	int m;

	init();
	if(scanf("%d", &(m)) != 1){
		fprintf(stderr, "scan failed on problem data\n");
		return -3;
	}
	if((m < 1) || (m > MAX_N)){
		fprintf(stderr, "bad input value %d\n", m);
		return -5;
	}
	printf("%u\n", GetCount(m));
	return 0;
}
