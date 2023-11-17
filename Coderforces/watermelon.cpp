#include<bits/stdc++.h>
using namespace std;

int main(){
    int peso=0;
    cin>>peso;
    if(peso==2){
        cout<<"NO\n";
    }else if ( peso % 2 == 0 ) {
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
    return 0;
}
