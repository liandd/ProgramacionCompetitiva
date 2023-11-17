#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k,w,res=0;
    cin>>k>>n>>w;
    res+=k;
    for(int i=2;i<=w;i++){
        res+=i*k;
    }
    printf("%d\n",(res-n<0)?0:res-n);
    return 0;
}
