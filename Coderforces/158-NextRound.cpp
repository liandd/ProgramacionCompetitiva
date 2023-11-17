#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,cont=0;
    cin>>n>>m;
        vector<int> p;
        for(int i=0;i<n;i++){
            int aux=0;
            cin>>aux;
            p.push_back(aux);
        }
        for(int i=0;i<n;i++){
            if(p[i]>=p[m-1] &&p[i]>0)
                 cont++;
        }
        cout<<cont<<"\n";
    return 0;
}
