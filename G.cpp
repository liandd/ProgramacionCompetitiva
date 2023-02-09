#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    pair <int, int> resultado;
    int T, F, S, P, C;
    cin>>T>>F>>S>>P>>C;
    resultado.first=((6*T)+(3*F)+(S*2)+(1*P)+(2*C));
    cin>>T>>F>>S>>P>>C;
    resultado.second=((6*T)+(3*F)+(S*2)+(1*P)+(2*C));
    cout<<resultado.first<<" "<<resultado.second<<"\n";

return 0;
}
