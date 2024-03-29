#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=0,t=0;
    cin>>n>>t;
    string fila;
    cin>>fila;
    while(t--){
    for(int i=0;i<n-1;i++){
        if(fila[i]=='B' && fila[i+1]=='G'){
            fila[i]='G';
            fila[i+1]='B';
            i++;
        }
    }
    }
    cout<<fila<<"\n";
return 0;
}
