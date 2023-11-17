#include<bits/stdc++.h>
using namespace std;
#define INF -1
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
vector<vi> ady;
vi dist;
int mov;
int dfs(int a, int b) {
    int cont = 0;
    dist[a] = 1;
    for (int i=0; i<b; i++) {
        if (ady[a][i] && !dist[i]) {
            cont += dfs(i, b) + 1;
        }
    }
    return cont;
}
int main() {
    int t, n, a, b, origen, destino;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> a >> b;
        ady.assign(a, vi(a, 0));
        dist.assign(a, 0);
        while (b--) {
            cin >> origen >> destino;
            ady[origen][destino] = 1;
            ady[destino][origen] = 1;
        }
        mov = dfs(n, a) * 2;
        cout << mov << "\n";
    }
    return 0;
}