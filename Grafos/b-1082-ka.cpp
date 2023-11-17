#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
struct Edge {
    int origen, destino;
};
struct DS {
    vi padre, rango;
    DS(int n) {
        padre.resize(n);
        rango.resize(n, 0);
        for (int i=0; i<n; i++) {
            padre[i] = i;
        }
    }
    int find(int a) {
        if (a != padre[a]) {
            padre[a] = find(padre[a]);
        }
        return padre[a];
    }
    void unionSets(int a, int b) {
        int raizOrigen = find(a);
        int raizDestino = find(b);
        if (raizOrigen == raizDestino) {
            return;
        }
        if (rango[raizOrigen] < rango[raizDestino]) {
            padre[raizOrigen] = raizDestino;
        } else if (rango[raizOrigen] > rango[raizDestino]) {
            padre[raizDestino] = raizOrigen;
        } else {
            padre[raizDestino] = raizOrigen;
            rango[raizOrigen]++;
        }
    }
};
vii kruskal(int n, const vector<Edge>& edges) {
    DS ds(n);
    for (const Edge& edge : edges) {
        ds.unionSets(edge.origen, edge.destino);
    }
    vii componentes(n);
    for (int i=0; i<n; i++) {
        componentes[ds.find(i)].push_back(i);
    }
    componentes.erase(remove_if(componentes.begin(), componentes.end(),[](const vector<int>& component) { return component.empty(); }), componentes.end());
    return componentes;
}
int main() {
    int t;
    cin >> t;
    int c=1;
    do {
        int n, e;
        cin >> n >> e;
        vector<Edge> edges(e);
        for (int i = 0; i < e; i++) {
            char a, b;
            cin >> a >> b;
            edges[i].origen = a - 'a';
            edges[i].destino = b - 'a';
        }
        vii componentes = kruskal(n, edges);
        cout << "Case #" << c << ":\n";
        for (const auto& component : componentes) {
            for (int e : component) {
                cout << (char)('a' + e) << ",";
            }
            cout << "\n";
        }
        cout << componentes.size() << " connected components\n\n";
        c++;
    } while (--t > 0);
    return 0;
}
