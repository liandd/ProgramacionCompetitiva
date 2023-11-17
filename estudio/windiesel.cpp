#include <bits/stdc++.h>
using namespace std;

#define FOR(i, j, k, l) for(int i = (j); i < (k); i += (l))
#define FORD(i, j, k, l) for(int i =(j); i >= (k); i -= (l))
#define REP(i, n) FOR(i, 0, n, 1)
#define REPD(i, n) FORD(i, n, 0, 1)
typedef long long ll;
const int N = 1e6;
const ll INFF = (ll)1e18;
const int INF = (int)1e9;

vector<int> g[N];
int d[N], dang[N], u[N];
int pr[N][20], h[N], mp[N], n, m;
int cnt = 1;
ll traverse = 0;

void tree_jump(int x, int p) {
    h[x] = h[p] + 1;
    pr[x][0] = p;
    for (int i = 1; i < 20; i++) {
        pr[x][i] = pr[pr[x][i-1]][i-1];
    }
}

struct key {
    int dist, x, par;

    bool operator<(key a) const {
        return tie(dist, x, par) < tie(a.dist, a.x, a.par);
    }
};

set<key> s;

int lift(int a, int up) {
    for (int ptr = 19; ptr >= 0; ptr--) {
        if (up & (1 << ptr)) {
            a = pr[a][ptr];
        }
    }

    return a;
}

int lca(int a, int b) {
    a = lift(a, max(h[a] - h[b], 0));
    b = lift(b, max(h[b] - h[a], 0));
    if (a == b) return a;

    for (int ptr = 19; ptr >= 0; ptr--) {
        if (pr[a][ptr] != pr[b][ptr]) {
            a = pr[a][ptr];
            b = pr[b][ptr];
        }
    }

    return pr[a][0];
}

int dist(int a, int b) {
    a = mp[a];
    b = mp[b];
    return h[a] + h[b] - 2 * h[lca(a, b)];
}

void add(int a, int p) {
    mp[a] = cnt++;
    tree_jump(mp[a], mp[p]);
}



void bfs(int s) {
    queue<int> q;
    q.push(s);

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        u[x] = 1;

        for (auto to : g[x]) {
            if (u[to]) continue;
            u[to] = 1;
            d[to] = d[x] + 1;
            q.push(to);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bfs(0);

    fill(u, u + n, 0);

    int cur = 0;


    for (auto to : g[0]) {
        s.insert({1, to, 0});
    }

    u[0] = 1;

    while (!s.empty()) {
        auto x = *s.begin();
        s.erase(s.begin());
        if (u[x.x]) continue;
        u[x.x] = 1;
        add(x.x, x.par);
        traverse += dist(x.x, cur);
        for (auto to : g[x.x]) {
            if (u[to]) continue;
            s.insert({h[mp[x.x]] + 1, to, x.x});
        }
        cur = x.x;
    }
    
    cout << traverse;

    return 0;
}