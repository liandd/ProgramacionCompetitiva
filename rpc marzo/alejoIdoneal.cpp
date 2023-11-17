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
Esta función de C++ se llama idoneal y toma un número entero
n como entrada. Devuelve true si n es un número idóneo y false
en caso contrario. Un número idóneo es un número entero positivo
que no puede escribirse como la suma de tres números enteros
positivos diferentes a, b, c tales que a * b + a * c + b * c = n.
La función implementa este concepto de la siguiente manera.
Usa tres bucles for anidados para iterar sobre todos los posibles
valores de a, b, c en el rango 1 a n. En cada iteración, comprueba
si a * b + a * c + b * c = n. Si esta condición se cumple para algún
valor de a, b, c, entonces el número n no es idóneo y la función
imprime los valores de a, b, c y devuelve false. De lo contrario
, después de iterar sobre todos los valores de a, b, c, se imprime
"idoneal" y la función devuelve true.

La función imprime el resultado en la salida estándar utilizando
cout y "\n" para separar las líneas.
*/
