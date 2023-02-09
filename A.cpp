#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;
vector <ii> numeros;
int t, n, suma;
int main(){
    
    cin>>t;
    while(t--){
        bool control=true;
        suma=0;
        cin>>n;
        numeros.assign(10, ii(0,-1));
        for(int i=0; i<n; i++){
            int a, b;
            cin>>a>>b;
            numeros[b-1].first++;
            numeros[b-1].second=max(numeros[b-1].second, a);
        }
        for(int i=0; i<10; i++){
            
            if(numeros[i].first!=0){
                
                suma+=numeros[i].second;
                
            }else if(control){
                cout<<"MOREPROBLEMS\n";
                control=false;
            }
        }
        
        if(control){
            cout<<suma<<"\n";
        }
        numeros.clear();

    }

    return 0;
}
