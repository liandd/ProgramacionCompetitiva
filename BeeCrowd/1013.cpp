#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,maior,s,maximo;
    cin>>a>>b>>c;
    maior=(a+b+abs(a-b))/2;
    maximo=(maior+c+abs(maior-c))/2;
    cout<<maximo<<" eh o maior"<<endl;
    return 0;
}