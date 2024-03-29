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

            int aux = b;
           for(int i = a; i<=aux; i++){
                int izq = ceil(((pow(i, 2))+i)/2);
                int der = ceil(((pow(b,2))+b)/2);
                der-=izq;
                b--;
                if(izq == der){
                    cont++;
                }
            }


        printf("%d\n", cont);

    }

return 0;
}
