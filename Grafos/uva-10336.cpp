#include <bits/stdc++.h>
using namespace std;
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
map<char, int> mci;
char grid[100][100];
int R, C, t, c = 1;

void floodfill(int r, int c, char c1, char c2) {
    if (r < 1 || r > R || c < 1 || c > C)
        return;
    if (grid[r][c] != c1)
        return;
    grid[r][c] = c2;
    for (int p = 0; p < 4; ++p)
        floodfill(r+dr[p], c+dc[p], c1, c2);
}
struct Compare {
    bool operator()(const char& a, const char& b) const {
        if (mci[a] != mci[b])
            return mci[a] > mci[b];
        return a < b;
    }
};

int main() {
    cin >> t;
    while (t--) {
        mci.clear();
        cin >> R >> C;
        for (int i = 1; i <= R; ++i)
            for (int j = 1; j <= C; ++j)
                cin >> grid[i][j];
        for (int letra = 97; letra <= 122; letra++){
            int ans = 0;
            for (int i = 1; i <= R; ++i){
                for (int j = 1; j <= C; ++j){
                    if (grid[i][j] == (char)letra){
                        ++ans;
                        floodfill(i, j, (char)letra, '.');
                    }
                }
            }
            if(ans > 0)
                mci[(char)letra] = ans;
        }
        cout << "World #" << c++ << "\n";
        map<char, int, Compare> res(mci.begin(), mci.end());
        for (const auto& e : res) {
            cout << e.first << ": " << e.second << "\n";
        }
    }
    return 0;
}
