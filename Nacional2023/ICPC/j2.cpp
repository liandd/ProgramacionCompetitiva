#include <bits/stdc++.h>
#define debug(x) cout<<#x<<" = "<<x<<endl;
using namespace std;

int main(){
    long long a, b;
    while(scanf("%lld %lld", &a, &b)){
        if(!a && !b) return 0;
        //debug(a);
        //debug(b);
        long long cont = 0;
        for (long long j = a; j <= b; j++) {
            long long izq = (j * (j + 1) * (2 * j + 1)) / 6;  // Suma de cuadrados hasta j
            long long der = (j * (j + 1)) / 2;               // Suma de números hasta j
            der = der * der - izq;
            debug(i);
        debug(j);                          // Der = (suma de números hasta j)^2 - (suma de cuadrados hasta j)
            if (izq == der) {
                    debug(der);
                cont++;
            }
        }

        printf("%lld\n", cont);

    }

return 0;
}
