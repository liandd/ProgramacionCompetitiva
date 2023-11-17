#include<bits/stdc++.h>
using namespace std;

int main(){
    int i=0;
    string str="",str2="",aux,aux2;
    cin>>aux;
    cin>>aux2;
    for(;i<aux.size();i++){
        str+=tolower(aux[i]);
        str2+=tolower(aux2[i]);
    }
    if(str<str2){
        cout<<"-1\n";
    }
    else if(str>str2){
        cout<<"1\n";
    }
    else cout<<"0\n";
    /*
    for(int i=0;i<str.size();i++){
        char tmp,tmp2;
        tmp=str[i];
        tmp2=str2[i];
        ascii=(int)tmp;
        ascii2=(int)tmp2;
        if(ascii>=97 || ascii<=122){
            sum+=ascii;
        }
        if(ascii2>=97 || ascii2<=122){
            sum2+=ascii2;
        }
    }
    if(sum<sum2){
        cout<<"-1\n";
    }
    else if(sum>sum2){
        cout<<"1\n";
    }
    else if(sum==sum2){
        sort(str.begin(),str.end());
        sort(str2.begin(),str2.end());
        char tmp=str[str.size()-1];
        char tmp2=str2[str2.size()-1];
        if(tmp>tmp2)cout<<"-1\n";
        else if(tmp<tmp2)cout<<"1\n";
        else{
            cout<<"0\n";
        }

    };
    */
return 0;
}
