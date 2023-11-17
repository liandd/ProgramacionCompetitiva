#include<bits/stdc++.h>
using namespace std;

int main(){
    string str,res;
    cin>>str;
    res=toupper(str[0]);
    for(int i=1;i<str.size();i++){
        res+=str[i];
    }
    cout<<res<<"\n";
return 0;
}
