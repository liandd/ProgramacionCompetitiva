#include <bits/stdc++.h>
#define debug(x) cout<<#x<<" = "<<x<<endl;
using namespace std;

int main(){
    int a, b;
    while(scanf("%d %d", &a, &b)){
        if(!a && !b) return 0;
        //debug(a);
        //debug(b);
        int cont = 0;
        for(int j = a; j<=b; j++){
           for(int i = 1; i<=j; i++){
                int izq = ceil(((pow(i, 2))+i)/2);
                int der = ceil(((pow(j, 2))+j)/2);
                der-=izq;
                if(izq == der){
                    cont++;
                }
            }
        }

        printf("%d\n", cont);

    }

return 0;
}
