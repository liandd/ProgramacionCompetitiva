#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=0,m=0,p=0;
    int sumatodos=0;
    double res;
    cin>>n>>m>>p;
    vector<int>paquetes(n);
    for(int i=0;i<n;i++){
        cin>>paquetes[i];
        sumatodos+=paquetes[i];//30+20+25=75
    }
    sort(paquetes.rbegin(),paquetes.rend());
    int t=0;
    for(int i=0;i<p+m;i++){
        t+=paquetes[i];
    }
    res=static_cast<double>(t)/static_cast<double>(sumatodos);
    res*=100;
    if((res) - static_cast<int>(res) == 0){
        cout<<fixed<<setprecision(0)<<res<<"\n";
    }else{
        cout<<fixed<<setprecision(9)<<res<<"\n";
    }
    return 0;
}
