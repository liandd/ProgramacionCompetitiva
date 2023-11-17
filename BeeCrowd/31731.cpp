#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vector<vi> ady;
vi dist;
int origen, destino, n, e;

void bfs() {
    dist[origen] = 0;
    queue<int> q;
    q.push(origen);
    while (!q.empty()) {
        int a = q.front();
        q.pop();
        for (int i = 0; i < (int)ady[a].size(); i++) {
            int b = ady[a][i];
            if (dist[b] == -1) {
                dist[b] = dist[a] + 1;
                q.push(b);
            }
        }
    }
}

int main() {
    cin >> n >> e;
    ady.assign(n + 1, vi());
    dist.assign(n + 1, -1);
    origen = 1;
    destino = n;
    while (e--) {
        int a, b;
        cin >> a >> b;
        ady[a].push_back(b);
        ady[b].push_back(a);
    }
    bfs();
    if (dist[destino] != -1) {
        cout << "COMPLETO\n";
    } else {
        cout << "INCOMPLETO\n";
    }
    return 0;
}