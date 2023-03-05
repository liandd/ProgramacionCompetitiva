#include<bits/stdc++.h>

using namespace std;

int main(){
    int n=10;
    int array[n];
    int x=0,y=0;
    cin>>x;
    for(int i=0;i<n;i++){
        cin>>y;
        array[i]=y;
    }
    int k=0;
    for(int b=n/2;b>=1;b/=2){
        while(k+b < n && array[k+b] <= x) k+=b;
    }
    if(array[k]==x){
       cout<<"Encontre x: "<<x<<" En la posicion: "<<k<<"\n";
    }
    return 0;
}
