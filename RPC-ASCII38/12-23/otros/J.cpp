#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=0;
    string str="",str2="";
    cin>>n;
    cin>>str;
    cin>>str2;
    int m=0;
    for(int i=0; i<n; i++) {
        int res = abs(str[i] - str2[i]);
        m += min(res, 26 - res);
    }
    cout<<m<<"\n";
return 0;
}
