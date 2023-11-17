#include<bits/stdc++.h>
using namespace std;
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
char grid[100][100];
int R, C , n , m;
int floodfill(int r, int c, char c1, char c2) {
    if (!(0 <= r && r < n && 0 <= c && c < m)) return 0;
    if (grid[r][c] != c1) return 0;
    grid[r][c] = c2;
    int area = 1;
    for (int i = 0; i < 8; i++) {
        area += floodfill(r + dr[i], c + dc[i], c1, c2);
    }
    return area;
}
int main() {
    int t;
    cin >> t;
    cin.ignore(1);
    string s;
    getline(cin, s);
    while (t--) {
        n = 0;
        m = 0;
        while (getline(cin, s), (s[0] == 'L' || s[0] == 'W')) {
            for (int i = 0; i < s.size(); i++) {
                grid[n][i] = s[i];
            }
            n++;
            m = s.size();
        }
        stringstream ss(s);
        ss >> R >> C;
        cout << floodfill(R - 1, C - 1, 'W', '.') << '\n';
        floodfill(R - 1, C - 1, '.', 'W');
        while (getline(cin, s), s.compare("") != 0) {
            ss.clear();
            ss.str(s);
            ss >> R >> C;
            cout << floodfill(R - 1, C - 1, 'W', '.') << '\n';
            floodfill(R - 1, C - 1, '.', 'W');
        }
        if (t) cout << '\n';
    }
    return 0;
}
