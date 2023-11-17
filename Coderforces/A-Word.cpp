#include<bits/stdc++.h>
using namespace std;

int main(){
    string str="";
    cin>>str;
    int i=0,c1=0,c2=0;
    while(i<str.size()){
        if(str[i]>=65 && str[i]<=90){
           c1++;
        }
        if(str[i]>=97 && str[i]<=122)c2++;
        i++;
    }
    //cout<<c1<<":"<<c2<<"\n";
    if(c1>c2){
        transform(str.begin(),str.end(),str.begin(),::toupper);
    }
    else if(c1<c2){
        transform(str.begin(),str.end(),str.begin(),::tolower);
    }
    else if(c1==c2)transform(str.begin(),str.end(),str.begin(),::tolower);
    cout<<str<<"\n";
    return 0;
}
