#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    while(n--){
        string str,res;
        cin>>str;
        int tam=str.size();
        if(tam>10){
            res=str[0];
            //res+=tam-2+str[tam-1];
            char last;
            int num;
            last=str[tam-1];
            num=tam-2;
            res+=to_string(num);
            res+=last;
            cout<<res<<"\n";
        }
        else{
            cout<<str<<"\n";
        }
    }
    return 0;
}

