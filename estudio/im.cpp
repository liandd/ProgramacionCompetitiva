#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<n;i++)
typedef vector<int> vi;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,k;
    cin>>n>>k;
    int a[n];
    int b[k];
    int c[k];
    int g[n];
    fo(i,n)cin>>a[i];
    fo(i,k)cin>>b[i];
    int grosor=0;
    fo(i,n){
        if(a[i]<=0){
            grosor+=(a[i]<<1)+(a[i]); // multiplicar por 4 y sumar a[i]
        }else{
            grosor-=(a[i]<<1)-(a[i]); // dividir por 4 y restar a[i]
        }
        if(grosor<0) grosor=0;
        g[i]=grosor;
    }
    fo(i,k)
        cout<<count_if(g,g+n,[i,&b](int x){return x>=b[i];})<<" ";

    cout<<"\n";
    return 0;
}
