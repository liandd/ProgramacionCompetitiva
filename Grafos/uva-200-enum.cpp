#include <bits/stdc++.h>
using namespace std;

void topologicalDFS(int u, const vector<vector<int>>& ady, vector<int>& dfs_num, vector<int>& toposort) {
    dfs_num[u] = 1;
    for (int v : ady[u]) {
        if (dfs_num[v] == 0) {
            topologicalDFS(v, ady, dfs_num, toposort);
        }
    }
    toposort.push_back(u);
}
int main() {
    vector<string> palabras;
    string letra;
    while (getline(cin, letra)) {
        if (letra == "#") {
            break;
        }
        palabras.push_back(letra);
    }
    map<char, set<char>> origen;
    set<char> caracteres;
    for (const string& letra : palabras) {
        for (char c : letra) {
            caracteres.insert(c);
        }
    }
    for (int i = 0; i < palabras.size() - 1; i++) {
        const string& actual = palabras[i];
        const string& siguiente = palabras[i + 1];
        int j = 0;
        while (j < actual.size() && j < siguiente.size() && actual[j] == siguiente[j]) {
            j++;
        }
        if (j < actual.size() && j < siguiente.size()) {
            origen[actual[j]].insert(siguiente[j]);
        }
    }
    int nodos = caracteres.size();
    map<char, int> mapa;
    int raiz = 0;
    for (char c : caracteres) {
        mapa[c] = raiz++;
    }
    vector<vector<int>> ady(nodos);
    vector<int> inDegree(nodos, 0);
    for (const auto& e : origen) {
        char nodo = e.first;
        int a = mapa[nodo];
        for (char siguiente : e.second) {
            int b = mapa[siguiente];
            ady[a].push_back(b);
            inDegree[b]++;
        }
    }
    vector<int> dfs_num(nodos, 0);
    vector<int> toposort;
    for (int i = 0; i < nodos; i++) {
        if (dfs_num[i] == 0) {
            topologicalDFS(i, ady, dfs_num, toposort);
        }
    }
    reverse(toposort.begin(), toposort.end());
    for (int i : toposort) {
        for (const auto& e : mapa) {
            if (e.second == i) {
                cout << e.first;
            }
        }
    }
    cout << "\n";
    return 0;
}
