#include<bits/stdc++.h>
using namespace std;

int main(){
    string lucky="";
    cin>>lucky;
    int cont=0;
    for(int i=0;i<lucky.size();i++){
        if(lucky[i]==52 || lucky[i]==55)cont++;
    }
    (cont==4 || cont==7)?cout<<"YES\n":cout<<"NO\n";

return 0;
}
