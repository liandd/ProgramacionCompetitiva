#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=0,cont=0,res=0;
    cin>>n;
    while(n--){
        int a=0,b=0;
        cin>>a>>b;
        //cout<<a<<"-a,"<<b<<"-b\n";
        res=res-a+b;//3,6,4
        //cout<<res<<"-res\n";
        cont=max(cont,res);//3,6,6
        //cout<<cont<<"-cont\n";
    }
    cout<<cont<<"\n";
return 0;
}
