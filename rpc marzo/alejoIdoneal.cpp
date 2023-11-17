#include<bits/stdc++.h>
using namespace std;

bool idoneal(int n) {
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            for (int k=j+1; k<=n; k++) {
                if (i*j + i*k + j*k == n) {
                    cout<<i<<" "<<j<<" "<<k<<"\n";
                    return false;
                }
            }
        }
    }
    cout<<"idoneal"<<"\n";
    return true;
}

int main() {
    int n;
    while(cin>>n && n!=0) {
        idoneal(n);
    }
    return 0;
}
/*
Esta funci�n de C++ se llama idoneal y toma un n�mero entero
n como entrada. Devuelve true si n es un n�mero id�neo y false
en caso contrario. Un n�mero id�neo es un n�mero entero positivo
que no puede escribirse como la suma de tres n�meros enteros
positivos diferentes a, b, c tales que a * b + a * c + b * c = n.
La funci�n implementa este concepto de la siguiente manera.
Usa tres bucles for anidados para iterar sobre todos los posibles
valores de a, b, c en el rango 1 a n. En cada iteraci�n, comprueba
si a * b + a * c + b * c = n. Si esta condici�n se cumple para alg�n
valor de a, b, c, entonces el n�mero n no es id�neo y la funci�n
imprime los valores de a, b, c y devuelve false. De lo contrario
, despu�s de iterar sobre todos los valores de a, b, c, se imprime
"idoneal" y la funci�n devuelve true.

La funci�n imprime el resultado en la salida est�ndar utilizando
cout y "\n" para separar las l�neas.
*/
