#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
vector<vector<ii>> ady;
vi visited, topo;
int n, e;
void topologicalDFS(int u){
    visited[u] = 1;
    for (ii temp : ady[u]){
        int v = temp.first;
        if (!visited[v])
            dfs(v);
    }
    topo.push_back(u);
}
int main(){
    while ((cin >> n >> e) && n){
        ady.assign(n + 1, vector<ii>());
        visited.assign(n + 1, 0);
        topo.clear();
        for (int i=0; i<e; ++i){
            int a, b;
            cin >> a >> b;
            ady[a].push_back(make_pair(b, 1));
        }
        for (int i = 1; i <= n; ++i){
            if (!visited[i])
                topologicalDFS(i);
        }
        reverse(topo.begin(), topo.end());
        for (int i=0; i<n; ++i){
            if (i > 0)
                cout << " ";
            cout << topo[i];
        }
        cout << "\n";
    }
    return 0;
}
