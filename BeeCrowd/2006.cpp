#include<bits/stdc++.h>
using namespace std;

int main(){
    int t=0,a=0,b=0,c=0,d=0,e=0;
    int ar[5];
    cin>>t;
    int ans=0;
       cin>>a>>b>>c>>d>>e;
       ar[0]=a;
       ar[1]=b;
       ar[2]=c;
       ar[3]=d;
       ar[4]=e;

       for(int i=0;i<5;i++){
         if(ar[i]==t){
            ans++;
         }
       }
    cout<<ans<<"\n";
    return 0;
}