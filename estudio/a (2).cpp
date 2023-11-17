#include <bits/stdc++.h>
using namespace std;

enum ValorAsociado {
    NO_ENCONTRADO = -1,
    VALOR_1 = 1,
    VALOR_2 = 2,
    VALOR_3 = 3,
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    map<int,ValorAsociado> mapa;
    mapa[1] = VALOR_1;
    for (long long i=1; i<=1e5; i++){
        long long coeficiente = 1;
        for (long long j = 0; j <= (i + 1) / 2; j++){
            coeficiente *= i - j;
            coeficiente /= j + 1;
            if (coeficiente > 1e9){
                break;
            }
            if (mapa.find(coeficiente) == mapa.end()){
                mapa[coeficiente] = static_cast<ValorAsociado>(i + 1);
            }
        }
    }
    while (q--){
        int n;
        cin >> n;
        if (mapa.find(n) == mapa.end()){
            cout << n+1 << '\n';
        }
        else{
            cout << static_cast<int>(mapa[n]) << '\n';
        }
    }
    return 0;
}
