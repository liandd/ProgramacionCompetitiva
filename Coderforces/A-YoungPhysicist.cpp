#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=0,res=0,tmp=0;
    cin>>n,tmp=n,n*=3;
    vector<int>f(n,0);
    int i=0;
    while(n--){
        int a,b,c;
        cin>>a;
        cin>>b;
        cin>>c;
        f[0]+=a;
        f[1]+=b;
        f[2]+=c;
        i++;
        //cout<<i<<"\n";
        if(i==tmp)break;
    }
    printf("%s\n",(f[0]==0&&f[1]==0&&f[2]==0?"YES":"NO"));
return 0;
}
