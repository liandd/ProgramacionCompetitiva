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
        cont=0;
        while(tam--){
            char aux;
            cin.get(aux);
            if(aux=='('){
                pila.push(aux);
            }else{
                if(!pila.empty()){
                    pila.pop();
                    cont+=2;
                }
            }
        }
        cout<<cont<<endl;
        while(!pila.empty()) pila.pop();
    }

return 0;
}
