/*
 * Football Scoring
 * ICPC Greater NY Regional
 * Solution by: John Buck
 */
#include <stdio.h>
#ifdef _MSC_VER
#define SCANF   scanf_s
#else
#define SCANF   scanf
#endif

int main()
{
    int at, af, as, ap, ac, ht, hf, hs, hp, hc;
    if(SCANF("%d %d %d %d %d %d %d %d %d %d",
        &(at), &(af), &(as), &(ap), &(ac),
        &(ht), &(hf), &(hs), &(hp), &(hc)) == 10){
        printf("%d %d\n", at * 6 + af * 3 + as * 2 + ap * 1 + ac * 2, ht * 6 + hf * 3 + hs * 2 + hp * 1 + hc * 2);
    }
    return(0);
}
