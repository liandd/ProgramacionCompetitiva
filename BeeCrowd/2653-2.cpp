#include <bits/stdc++.h>
using namespace std;
int main(){
    string str="";
    set<string> s;
    while(cin>>str){
    s.insert(str);

    }
    cout<<s.size()<<'\n';
    return 0;
}