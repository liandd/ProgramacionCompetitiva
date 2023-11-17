#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,cont=0,cont2=0,res=0;
  cin>>n;
  while(n--){
    string str;
    cin>>str;
    for(int i=0; i<str.size();i++){
        if(str[i]=='X' && str[i+1]=='+'){
            cont++;break;
        }
        else if(str[i]=='X' && str[i+1]=='-'){
            cont2++;break;
        }
        else if(str[i]=='+'){
            cont++;break;
        }
        else if(str[i]=='-'){
            cont2++;break;
        }
    }
    res=cont-cont2;
  }
  cout<<res<<"\n";
return 0;
}
