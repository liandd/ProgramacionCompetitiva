#include<bits/stdc++.h>
using namespace std;

int main(){
    string str="";
    cin>>str;
    set<char>letras;
    int i=0,tam=str.size();
    for(;i<tam;i++){
        if(letras.find(str[i])== letras.end()){
            letras.insert(str[i]);
        }
    }
    tam=letras.size();
    if(tam&1){
        cout<<"IGNORE HIM!\n";
    }
    else{
        cout<<"CHAT WITH HER!\n";
    }
    return 0;
}
