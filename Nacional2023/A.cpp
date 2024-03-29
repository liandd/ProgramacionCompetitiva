#include<bits/stdc++.h>
using namespace std;

int main(){
ios::sync_with_stdio(0);
cin.tie(0);
int n;
while(cin>>n && n){
    int res=n*(n-1)+1;
    cout<<res<<"\n";
}
return 0;
}
