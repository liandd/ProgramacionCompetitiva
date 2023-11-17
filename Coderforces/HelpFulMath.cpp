#include<bits/stdc++.h>
using namespace std;

int main(){
    string str,res;
    cin>>str;
    vector<int> num;
    for(int i=0;i<str.size();i++){
        if(str[i]=='+')continue;
        else{
            num.push_back(str[i]-'0');
        }
    }
    sort(num.begin(),num.end());
    for(int i=0;i<num.size(); i++) {
        res+=to_string(num[i]);
        if(i<num.size()-1) {
            res+='+';
        }
    }
    cout<<res<<"\n";
return 0;
}

