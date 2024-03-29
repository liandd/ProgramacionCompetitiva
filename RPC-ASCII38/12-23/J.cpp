#include<bits/stdc++.h>
using namespace std;

int ubicar(char c, string w){
    int i=0;
    while(c!=w[i])i++;
    return i;
}
int contarA(int s, int e, string w){
    int i=s,c=0;
    while(w[i]!=w[e]){
        i++;
        c++;
    }
    return c;
}
int contarB(int s, int e, string w){
    int i=s+26,c=0;
    while(w[i]!=w[e]){
        i--;
        c++;
    }
    return c;
}
int main(){
    int n,cont;
    string a,b;
    cin>>n;
    cin>>a;
    cin>>b;
    string w="ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i=0;i<n;i++){
        int in=ubicar(a[i],w);
        int ni=ubicar(b[i],w);
        int u=contarA(in,ni,w);
        int d=contarB(in,ni,w);
        cont+=min(u,d);
    }
    cout<<cont<<"\n";
    return 0;
}
