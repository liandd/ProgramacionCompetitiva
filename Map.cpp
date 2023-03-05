#include<bits/stdc++.h>
using namespace std;

int main(){
    map<string,int> mapa;
    mapa["Mono"]=4;
    mapa["Conejo"]=3;
    mapa["Perro"]=9;
    cout<<mapa["Mono"]<<"\n";
    cout<<"Imprimiendo todo el mapa:\n";
    for(auto x: mapa){
        cout<<x.first<<" "<<x.second<<"\n";
    }
    return 0;
}
