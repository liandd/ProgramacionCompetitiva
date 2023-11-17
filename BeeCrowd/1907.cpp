#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tii;
int R, C;
char grid[1026][1026];
int floodfill(int r, int c, char c1, char c2) {
    if (r < 0 || r >= R || c < 0 || c >= C) return 0;
    if (grid[r][c] != c1) return 0;
    int ans = 1;
    grid[r][c] = c2;
    queue<tii> fila;
    fila.push(make_tuple(r, c, 0));
    while (!fila.empty()) {
        int x, y, cor;
        tie(x, y, cor) = fila.front();
        fila.pop();
        if (grid[x - 1][y] == c1) {
            fila.push(make_tuple(x - 1, y, cor));
            grid[x - 1][y] = c2;
        }
        if (grid[x + 1][y] == c1) {
            fila.push(make_tuple(x + 1, y, cor));
            grid[x + 1][y] = c2;
        }
        if (grid[x][y - 1] == c1) {
            fila.push(make_tuple(x, y - 1, cor));
            grid[x][y - 1] = c2;
        }
        if (grid[x][y + 1] == c1) {
            fila.push(make_tuple(x, y + 1, cor));
            grid[x][y + 1] = c2;
        }
    }
    return ans;
}
int main() {
    cin >> R >> C;
    cin.ignore();
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == '.') {
                ans++;
                floodfill(i, j, '.', 'k');
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
