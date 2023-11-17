#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const int N=2e5;
const int oo=1e9+2;
const int MOD=1e9+7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> palabras(n);
    vector<bool> ascii(255);
    for(int i=0; i<n; i++){
        cin >> palabras[i];
        ascii[palabras[i][0]]=1;
    }
    bool verdad=0;
    for(auto s: palabras){
        bool falso = 1;
        for(auto c : s)falso &=ascii[c];
        verdad |= falso;
    }
    if(verdad) cout << "Y" <<"\n";
    else cout << "N" <<"\n";
return 0;
}
