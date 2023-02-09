/*
 * Unicycle returns - GNY Regional 2021 - Fred Pickel
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef unsigned int DWORD;

//#define TEST

#ifdef WIN32
typedef unsigned __int64 LLONG;
#else
typedef unsigned long long LLONG;
#endif

#define MODULUS	100007

#define MAX_N 4000

LLONG fibs[2*MAX_N];
int lastFib;

/*
 *	if we do not use the edge from v(n) to v(1) the cycle in the unicycle has the form
 *	v[0]->v[i]]->...->v[j]->v[0] for j > i where ... indicates the vertices on the rim from i to j
 * call the the i,j cycle
 *	j can run from 2 to n and for a given j, i can run from 1 to j-1
 *	so total unicycles is SUM(j-2,n)[SUM(i = 1, j-1)[uniccycle with cycle the i,j cycle]
 *	uniccycle with cycle the i,j cycle = 
 *	number of was to connect vertices before i to cycle * number of ways to connect verts after j
 *	by symmetry, the number of way to connect k vertices before i is the same as the number
 *		of way to connect k vertices after j Call the number F(k)
 *	so total unicycles is SUM(j-2,n)[SUM(i = 1, j-1)[F(i-1)*F(n-j)]
 *
 *	what is F(k): (consider vertices before i)
 *	F(0) = 1
 *	F(1) = 2	v[1] connects to v[0] or v[2]
 *	f(2) = 5:	v[1] connects to v[0] and v[2] connects to v[0], v[1] or v[3]
 *			OR	v[1] connects to v[2] and v[2] connects to v[0] or v[3] (v[1] does not work)
 *	SWAG F[k] = Fib[2*k+1] (when Fib[1] = Fib[2] = 1)
 *	so total unicycles is SUM(j=2,n)[Fib(2*(n-j) + 1)* SUM(i = 1, j-1)[Fib(2*i-1)]
 *					= SUM(j-2,n)[Fib(2*(n-j) + 1)* Fib(2*j-2)]
 *	since sum i = 1 to n Fib(2*i-1) = Fib(2*n) 
 */

/*
 * why do we get fibonacci's
 * again let F(k) = number of ways of connecting k vertices V[1] to v[k]to a cycle including v[0]->v[k+1]
 *	now suppose we consider vertices v[1] .. v[k+1] attaching to a cycle including v[0]->v[k+2]
 * v[k+1] can connect to v[k+2] and then there are F(k) ways of connecting v[1] ... v[k]
 * v[k+1] can connect to v[0] and then there are F(k) ways of connecting v[1] ... v[k]
 * v[k+1] can connect to v[k] but we cannot count any fo the F(k) ways of connecting v[1 ... v[k]
 * to the cycle which connect via edge v[k]->v[k+1] (F9k-1) of them
 * so F(k+1) = 3*f(k) - F(k-1) (Fib(k+2) = 3*Fib(k) - Fib(k-2))
 */
int MakeFibs(int n)
{
	int j;
	fibs[1] = fibs[2] = 1;
	for(j = 3; j < 2*n ; j++) {
		fibs[j] = (fibs[j-1] + fibs[j-2]) % MODULUS;
	}
	return 0;
}

DWORD brokerim(int n)
{
	LLONG res;
	int j;
	for(j = 2, res = 0 ; j <= n ; j++) {
		res = (res + fibs[2*(n-j) - 1] * fibs[2*j-2]) % MODULUS;
	}
	return (DWORD)res;
}

char inbuf[256];

int main()
{
	DWORD n, cnt;
#ifdef TEST
	while(1) {
#endif
	if(fgets(&(inbuf[0]), 255, stdin) == NULL) {
		fprintf(stderr, "read failed on input data\n");
		return -3;
	}
	if(sscanf(&(inbuf[0]), "%u", &n) != 1){
		fprintf(stderr, "scan failed on problem data\n");
		return -3;
	}
	if((n < 3) || (n > MAX_N)) {
		fprintf(stderr, "wheel size %d not in range 1 ... %d\n", n, MAX_N);
		return -5;
	}
	MakeFibs(n);
	cnt = brokerim(n);
#ifdef TEST
	printf("%u\n", cnt);
	}
#else
	printf("%u\n", cnt);
#endif
	return 0;
}
