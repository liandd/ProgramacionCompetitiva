
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfsTraversal(int start, const vector<vector<int>>& adj) {
    int V = adj.size();
    vector<bool> visited(V, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();

        cout << vertex << " ";  // Print the visited vertex

        for (int neighbor : adj[vertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    cout << endl;  // Print newline after BFS traversal
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfsTraversal(0, adj);

    return 0;
}
