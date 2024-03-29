#include<bits/stdc++.h>
using namespace std;

int main(){
    string str="",str2="";
    cin>>str>>str2;
    reverse(str2.begin(),str2.end());
    (str==str2)?cout<<"YES\n":cout<<"NO\n";
 return 0;
}
