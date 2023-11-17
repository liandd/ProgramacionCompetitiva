#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
void dfs(int n, const vii& ady, vi& visitado, vi& componente) {
    visitado[n] = true;
    componente.push_back(n);
    for (int vecino : ady[n]) {
        if (!visitado[vecino]) {
            dfs(vecino, ady, visitado, componente);
        }
    }
}
int find(const vii& ady) {
    int n = ady.size();
    vi visitado(n, false);
    int conectado=0;
    for (int i=0; i<n; i++) {
        if (!visitado[i]) {
            vi componente;
            dfs(i, ady, visitado, componente);
            conectado++;
        }
    }
    return conectado;
}
int main() {
    int t;
    cin >> t;
    int c=1;
    do {
        int n, e;
        cin >> n >> e;
        vii ady(n);
        for (int i=0; i<e; i++) {
            char a, b;
            cin >> a >> b;
            ady[a - 'a'].push_back(b - 'a');
            ady[b - 'a'].push_back(a - 'a');
        }
        cout << "Case #" << c << ":\n";
        vi visitado(n, false);
        for (int i=0; i<n; i++) {
            if (!visitado[i]) {
                vi componente;
                dfs(i, ady, visitado, componente);
                sort(componente.begin(), componente.end());
                for (int e : componente) {
                    cout << (char)('a'+e) << ",";
                }
                cout << "\n";
            }
        }
        int conectado = find(ady);
        cout << conectado << " connected components\n\n";
        c++;
    } while (--t > 0);
    return 0;
}
