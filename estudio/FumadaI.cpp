#include<bits/stdc++.h>
using namespace std;

int main(){
    string num;
    cin>>num;
    int ceros=0;
    float respuesta=0;
    int dias=0;
    for(int i=0;i<num.size();i++){
        if(num[i]=='1'){
            if(ceros>respuesta){
                respuesta=ceros;
            }
            ceros=0;
        }
        else{
            ceros++;
        }
    }
    dias=ceil(respuesta/2);
    cout<<dias<<"\n";
    return 0;
}