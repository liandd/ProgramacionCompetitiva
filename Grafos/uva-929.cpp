#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef pair<int, pair<int, int>> pii;

int dijkstra(vector<vi>& maze, int N, int M) {
    vector<vi> dist(N, vi(M, INT_MAX));
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[0][0] = maze[0][0];
    pq.push({maze[0][0], {0, 0}});
    while (!pq.empty()) {
        int cost = pq.top().first;
        int a = pq.top().second.first;
        int b = pq.top().second.second;
        pq.pop();
        if (cost > dist[a][b])continue;
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};
        for (int i=0; i<4; i++) {
            int na = a + dr[i];
            int nb = b + dc[i];
            if (na >= 0 && na < N && nb >= 0 && nb < M) {
                int resultado = cost + maze[na][nb];
                if (resultado < dist[na][nb]) {
                    dist[na][nb] = resultado;
                    pq.push({resultado, {na, nb}});
                }
            }
        }
    }
    return dist[N - 1][M - 1];
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vi> maze(N, vi(M));
        for (int i=0; i<N; i++)
            for (int j=0; j<M; j++)
                cin >> maze[i][j];

        int ans = dijkstra(maze, N, M);
        cout << ans << "\n";
    }
    return 0;
}
