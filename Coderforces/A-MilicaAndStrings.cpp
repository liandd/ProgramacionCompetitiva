#include<bits/stdc++.h>
using namespace std;

int main(){
    int t=0,n=0,k=0;
    string str="";
    cin>>t;
    while(t--){
        cin>>n>>k;
        cin>>str;
        int contB=0,tmp=0;
        for(int i=0;i<str.size();i++){
            if(str[i]=='B'){
                contB++;
                continue;
            }
            }if(contB==k){
                cout<<"0\n";
                contB=0;
                break;
        }
        else{
            if(str[0]=='A'){
                str[0]='B';
                contB++,tmp++;
                if(contB==k){
                    cout<<tmp<<" "<<str[0]<<"\n";
                }
            }
        }
    }

return 0;
}
