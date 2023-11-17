#include<bits/stdc++.h>
using namespace std;
int natasha(int n, const vector<int>& primoEvitado) {
    vector<int> numerosNoEvitados;
    for (int i = 1; ; i++) {
        bool evitar = false;
        for (int primo : primoEvitado) {
            if (i % primo == 0) {
                evitar = true;
                break;
            }
        }
        if (!evitar) {
            numerosNoEvitados.push_back(i);
            if (numerosNoEvitados.size() == n) {
                break;
            }
        }
    }
    return numerosNoEvitados.back();
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> primoEvitado(k);
    for (int i = 0; i < k; i++) {
        cin >> primoEvitado[i];
    }
    int ans = natasha(n, primoEvitado);
    cout << ans << "\n";
    return 0;
}
