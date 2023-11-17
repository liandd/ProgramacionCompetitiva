#include<bits/stdc++.h>
using namespace std;

int main(){
    string str="";
    int i=0,j=0,n=0;
    cin>>n;
    cin>>str;
    for(;j<str.size();j++){
        if(str[j]==str[j+1]){
            i++;
        }
    }
    cout<<i<<"\n";

return 0;
}
