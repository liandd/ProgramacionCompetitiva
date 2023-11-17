#include<bits/stdc++.h>
using namespace std;

int main(){
    int a=0,b=0,cont=0;
    cin>>a>>b;
    do{
        a*=3;
        b*=2;
        cont++;
    }while(a<b);
    if(a==b)cont++;
    cout<<cont<<"\n";
return 0;
}
