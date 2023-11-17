#include<bits/stdc++.h>
using namespace std;
vector<vector<char>> grid;
vector<vector<bool>> visited;
vector<vector<int>> ancestor;
int R, C;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, 1, -1};
bool isValid(int r, int c) {
    return (r >= 0 && r < R && c >= 0 && c < C);
}
int dfs(int r, int c, bool isStartingPoint) {
    visited[r][c] = true;
    int spots = 0;
    for (int i = 0; i < 4; i++) {
        int newR = r + dr[i];
        int newC = c + dc[i];
        if (isValid(newR, newC) && grid[newR][newC] != '.' && !visited[newR][newC]) {
            ancestor[newR][newC] = ancestor[r][c];
            if (grid[newR][newC] == '#') {
                spots++;
            }
            spots += dfs(newR, newC, false);  // No se considera el punto de partida como lugar turístico visitado
        }
    }
    if (isStartingPoint) {
        spots--;  // Restar 1 si el punto de partida es un lugar turístico
    }
    return spots;
}
int main() {
    cin >> R >> C;
    grid.resize(R, vector<char>(C));
    visited.resize(R, vector<bool>(C, false));
    ancestor.resize(R, vector<int>(C, -1));
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cin >> grid[i][j];
        }
    }
    int maxSightseeingSpots = 0;
for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
        if (grid[i][j] != '.' && !visited[i][j]) {
            ancestor[i][j] = i * C + j;
            int spots = dfs(i, j, true);  // Indicar que el punto de partida es un lugar turístico
            if (spots > maxSightseeingSpots) {
                maxSightseeingSpots = spots;
            }
        }
    }
}
maxSightseeingSpots = max(maxSightseeingSpots - 1, 0);  // Restar 1 si el punto de partida es un lugar turístico
cout << maxSightseeingSpots << endl;
    return 0;
}
