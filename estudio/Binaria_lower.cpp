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
/*  auto k=lower_bound(array,array+n,x)-array;
    if(k<n && array[k]==x){
       cout<<"Encontre x: "<<x<<" En la posicion: "<<k<<"\n";
    }
*/
    auto a = lower_bound(array,array+n,x);
    auto b = upper_bound(array,array+n,x);
    cout << "Repetido : "<<b-a<<"\n";
    return 0;
}
