#include <bits/stdc++.h>
using namespace std;

#define INF -1
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vi> ady;
vi dist;
int origen, destino, n, e, cont;

int bfs() {
    dist[origen] = 0;
    queue<int> q;
    q.push(origen);

    while (!q.empty()) {
        int a = q.front();
        q.pop();
        cont++;

        for (int j = 0; j < ady[a].size(); j++) {
            int v = ady[a][j];
            if (dist[v] == INF) {
                dist[v] = dist[a] + 1;
                q.push(v);
            }
        }
    }

    return cont;
}

int main() {
    int n, e;
    while (cin >> n >> e && n && e) {
        ady.assign(n, vi(0, 0));
        dist.assign(n, INF);

        for (int i = 0; i < e; i++) {
            int v, w, p;
            cin >> v >> w >> p;
            v--, w--;
            ady[v].push_back(w);
            if (p == 2) ady[w].push_back(v);
        }

        bool s = true;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            cont = 0;
            origen = i;
            fill(dist.begin(), dist.end(), INF);
            ans = bfs();

            if (ans < n) {
                s = false;
                break;
            }
        }

        cout << s << "\n";
    }

    return 0;
}