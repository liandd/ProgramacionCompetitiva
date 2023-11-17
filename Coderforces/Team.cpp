#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,res=0;
    cin>>n;
    n+=1;
    while(n--){
        string str;
        getline(cin,str);
        int cont=0;
        for(int i=0;i<str.size();i++){
            if(str[i]=='1')cont++;
        }
        if(cont==3 || cont==2)res++;

    }
    cout<<res<<"\n";
    return 0;
}
