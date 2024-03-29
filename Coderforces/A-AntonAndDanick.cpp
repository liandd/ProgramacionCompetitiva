#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=0,cont=0,cont2=0;
    cin>>n;
    string jugadores="";
    cin>>jugadores;
    transform(jugadores.begin(),jugadores.end(),jugadores.begin(),::tolower);
    for(int i=0;i<n;i++){
        (jugadores[i]==97)?cont++:cont2++;
    }
    if(cont==cont2){
        cout<<"Friendship\n";
        exit(0);
    }
    (cont>cont2)?cout<<"Anton\n":cout<<"Danik\n";


return 0;
}

