#include<bits/stdc++.h>
using namespace std;
int main(){
    double n, m, k, sum=0 , op=0;
    double r= 0;
    cin>>n>>m>>k;
    vector<int>num(n);
    for(int i = 0; i<n; i++){
        cin>>num[i];
        sum = sum + num[i];
    }
    sort(num.begin(),num.end());
    for(int i = 0; i<(n-m-k); i++){
        op+=num[i];
    }
    r= sum-op;
    r=r/sum;
    r*=100;
    if((r) - static_cast<int>(r) == 0){
        cout<<fixed<<setprecision(0)<<r<<"\n";
   }else{
        cout<<fixed<<setprecision(9)<<r<<"\n";
   }
return 0;
}
