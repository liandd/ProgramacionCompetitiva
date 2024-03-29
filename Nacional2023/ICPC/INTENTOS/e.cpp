#include <bits/stdc++.h>

#define debug(x) cout<<#x<<" = "<<x<<endl;

using namespace std;

int main(){
    int n, cont=0;
    scanf("%d", &n);
    stack <char> pila;
    while(n--){
        int tam;
        scanf("%d", &tam);
        cin.ignore();
        cont=tam;
        while(tam--){
            char aux;
            cin.get(aux);
            if(aux=='('){
                pila.push(aux);
            }else{
                if(!pila.empty()){
                    pila.pop();
                }else cont--;
            }
        }
        if(pila.size()==0) cout<<cont<<endl;
        else cout<<cont-pila.size()<<endl;
    }

return 0;
}
