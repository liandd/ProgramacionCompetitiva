/*
 * Spaghetti - GNY Regional 2021 - John Buck
 */
#include <stdio.h>
#include <stdlib.h>

#define	MAX_TRUCKS	200		// Really, max C + max D as per problem spec
#define	MAX_BOATS	100		// Really, max C as per problem spec
#ifndef _MSVC_VER
#define	scanf_s	scanf
#endif

int main()
{
	int a, b, c, d, nt, nb, bcap, tcap;

	while (scanf_s("%d %d %d %d", &(a), &(b), &(c), &(d)) == 4) {
		/* Can never have more than MAX_TRUCKS trucks (c+d) */
		for (nt = 0; nt <= MAX_TRUCKS; nt++) {
			tcap = nt * a;
			/* Can never have more than MAX_BOATS boats (c) */
			for (nb = 0; nb <= MAX_BOATS; nb++) {
				/* Boat capacity with nb boats */
				bcap = nb * b;
				/* Contraint check */
				if (tcap - bcap == d && bcap >= c) {
					printf("We need %d truck%s and %d boat%s.\n",
						nt, (nt == 1) ? "" : "s", nb, (nb == 1) ? "" : "s");
					break;
				}
			}
			if (nb <= MAX_BOATS) {
				break;
			}
		}
		/* Whoops - no solution */
		if (nt > MAX_TRUCKS) {
			printf("No solution.\n");
		}
	}
	return(0);
}
