#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=0,s=0,m=0,h=0;
    cin>>n;
    h=n/3600;
    n%=3600;
    m=n/60;
    n%=60;
    s=n;
    string res="";
    res=to_string(h)+':'+to_string(m)+':'+to_string(s);
    cout<<res<<"\n";
return 0;
}
