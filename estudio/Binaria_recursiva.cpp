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
    int a=0, b=n-1;
    while(a<=b){
        int k = (a+b)/2;
        if(array[k]==x){
            cout<<"Encontre x: "<<x<<" En la posicion: "<<k<<"\n";
        }
        if(array[k]>x)b=k-1;
        else a=k+1;
    }
    return 0;
}
