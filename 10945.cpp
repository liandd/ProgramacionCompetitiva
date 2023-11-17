#include <bits/stdc++.h>

using namespace std;

int main (){
    string cadena, nuevo;
    while(getline(cin,cadena)&& cadena!="DONE"){
        nuevo="";
        bool palindromo=true;
        if(cadena=="DONE") return 0;
        for(int i=0; i<cadena.size(); i++){
            if((cadena[i]>=65 && cadena[i]<=90)||(cadena[i]>=97 && cadena[i]<=122)){
                nuevo+=toupper(cadena[i]);
            }
        }
        //cout<<nuevo<<endl;
        for(int i=0; i<nuevo.size() && palindromo; i++){
            if(nuevo[i]!=nuevo[nuevo.size()-1-i]) palindromo=false;
        }
        if(palindromo) cout<<"You won't be eaten!\n";
        else cout<<"Uh oh..\n";

    }
    return 0;
}
