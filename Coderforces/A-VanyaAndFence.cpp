#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=0,h=0,res=0;
    cin>>n>>h;
    int totalAmigos=n;
    int tmp=0;
    vector<int> amigos;
    for(int i=0;i<totalAmigos;i++){
        cin>>tmp;
        amigos.push_back(tmp);
    }
    for(int i=0;i<totalAmigos;i++){
        (amigos[i]<=h)?res++:res+=2;
    }
    cout<<res<<"\n";
return 0;
}
