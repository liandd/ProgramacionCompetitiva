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
        for(long long j = a; j<=b; j++){
           for(long long i = 1; i<=j; i++){
                long long izq = ceil(((pow(i, 2))+i)/2);
                long long der = ceil(((pow(j, 2))+j)/2);
                der-=izq;
                if(izq == der){
                    cont++;
                }
            }
        }

        printf("%lld\n", cont);

    }

return 0;
}
