#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double h=0,f=0;
    cin>>h>>f;
    double res=0;
    res=(f/12)*h;
    cout<<fixed;
    cout<<setprecision(3)<<res<<"\n";

    return 0;
}