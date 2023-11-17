#include<bits/stdc++.h>
using namespace std;

struct DS {
    vector<int> padre;
    DS(int tam) {
        padre.resize(tam);
        for (int i = 0; i < tam; i++) {
            padre[i] = i;
        }
    }

    int find(int a) {
        if (padre[a] != a) {
            padre[a] = find(padre[a]);
        }
        return padre[a];
    }

    void unionSets(int a, int b) {
        int raizA = find(a);
        int raizB = find(b);
        if (raizA != raizB) {
            padre[raizA] = raizB;
        }
    }
};

struct Edge {
    int origen;
    int destino;
    int pesoE;
    bool operator<(const Edge& other) const {
        return pesoE < other.pesoE;
    }
};

vector<Edge> kruskal(const vector<Edge>& edges, int numV) {
    vector<Edge> mst;
    DS ds(numV);
    vector<Edge> sorteado = edges;
    sort(sorteado.begin(), sorteado.end());
    for (const Edge& e : sorteado) {
        int raizOrigen = ds.find(e.origen);
        int raizDestino = ds.find(e.destino);
        if (raizOrigen != raizDestino) {
            mst.push_back(e);
            ds.unionSets(raizOrigen, raizDestino);
        }
    }
    return mst;
}

int main() {
    int n, e, i = 0;
    while (cin >> n >> e && (n != 0 || e != 0)) {
        vector<Edge> edges(e);
        for (i = 0; i < e; i++) {
            cin >> edges[i].origen >> edges[i].destino >> edges[i].pesoE;
        }
        vector<Edge> mst = kruskal(edges, n);
        int pesoTotal = 0;
        for (const Edge& edge : mst) {
            pesoTotal += edge.pesoE;
        }
        int ahorro = 0;
        for (const Edge& edge : edges) {
            ahorro += edge.pesoE;
        }
        int ans = ahorro - pesoTotal;
        cout << ans << "\n";
    }
    return 0;
}
