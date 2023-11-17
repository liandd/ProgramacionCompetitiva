#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, cont=0;
    while(cin>>n && n!=0){
        if (cont) cout<<"\n";
        cont++;
        double r, c, promedio=0, totalR=0;
        map <int, int> ciudad;
        while(n--){
            cin>>r>>c;
            ciudad[floor(c/r)]+=r;
            totalR+=r;
            promedio+=c;
        }
        promedio/=totalR;
        cout<<"Cidade# "<<cont<<":\n";
        for(auto e: ciudad){
            cout<<e.second<<"-"<<fixed<<setprecision(0)<<floor(e.first)<<" ";
        }
        cout<<"\nConsumo medio: "<<fixed<<setprecision(2)<<floor(100*promedio)/100<<" m3.\n";
    }

return 0;
}
