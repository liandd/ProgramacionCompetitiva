#include <bits/stdc++.h>
using namespace std;
int factorial[]={1,1,2,6,24,120,720,5040,40320,362880};
int f(int x){//  0,1,2,3,4,  5,  6,  7,    8,    9
    if(x==0){
        return 1;
    }
    int suma=0;
    while(x>0){
        suma +=factorial[x%10];
        x/=10;
    }
    return suma;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int y=0;
    cin>>y;//3,20
    int k=9;//Empezar con el mas grande osea 9 'CONSEJO DE JHON de la utp.'
    stringstream oss;//secuencia de caracteres leidas como objeto por buffer
    while(y>0){//3 mayor 0 si, 20 mayor 0 si
        while(y<factorial[k]){
                //3 menor que factorial de 9 si, k=8 /20 menor que factorial de 9 si, k=8
                //3 menor que factorial de 8 si, k=7 /20 menor que factorial de 8 si, k=7
                //3 menor que factorial de 7 si, k=6 /20 menor que factorial de 7 si, k=6
                //3 menor que factorial de 6 si, k=5 /20 menor que factorial de 6 si, k=5
                //3 menor que factorial de 5 si, k=4 /20 menor que factorial de 5 si, k=4
                //3 menor que factorial de 4 si, k=3 /20 menor que factorial de 4 si, k=3
                //3 menor que factorial de 3 si, k=2 /20 menor que factorial de 3 no, k=2
                //3 menor que factorial de 2 no, k=1

            k--;//k = 1 para 3,k = 2 para 20
        }

        oss << k;//oss*oss(k^k) redirecciono bits
        y -= factorial[k];
        //valor de y para 3, y=1, luego 0, valor de y para 20, y=14,8,2,0, y -= factorial[k]
    }
    string str = oss.str ();//copio el contenido de oss del buffer despues del shifting en variable str
    //str vale 21 para 3, str vale 3332 para 20 intercambio el orden de str obtengo la respuesta
    if (str == "1") {
        str = "0";
    }
    // retorno el iterador inverso que apunta al ultimo elemento con rbegin
    // con el for muestro la respuesta por pantalla complejidad 0(1)
    for (auto it = str.rbegin(); it != str.rend(); it++) {
        cout << *it;//imprime el orden del numero
    }

    cout << "\n";
    return 0;
}
