#include <bits/stdc++.h>
using namespace std;
int main() {
    double x1=0,x2=0,y1=0,y2=0,res=0;
    cin>>x1;
    cin>>y1;
    cin>>x2;
    cin>>y2;
    res=sqrt((pow(x2 - x1, 2) + pow(y2 - y1, 2)));
    cout<<fixed;
    cout<<setprecision(4)<<res<<"\n";
    return 0;
}
