#include<bits/stdc++.h>
using namespace std;

int main(){
    string num;
    cin>>num;
    int ceros=0;
    float respuesta=0;
    int dias=0;
    for(int i=0;i<num.size();i++){
        if(num[i]=='1'){//Tomo el mayor bloque de ceros, si encuentra un 1, termina ese bloque y busqueme el siguente bloque
            if(ceros>respuesta){
                respuesta=ceros;
            }
            ceros=0;
        }
        else{
            ceros++;
        }
    }
    dias=ceil(respuesta/2);//si tengo 6 ceros, entonces 6/2=3, si es impar 5/2=2,5 ceil lo aproxima a 3
    //divido mi mayor bloque de ceros entre 2, ya que 2 torres se certifican, y mediante la funcion ceil aproximo al siguiente valor entero de la division
    cout<<dias<<"\n";
    return 0;
}
