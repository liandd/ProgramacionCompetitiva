#include<bits/stdc++.h>
using namespace std;
#define INF -1
typedef pair<int,int>ii;
typedef vector<int> vi;
typedef vector<ii> vii;
vectot<vi> ady;
vi dist;
int origen, destino, n, e;
void dfs(int a){
    dist[a]=1;
    for(int i=0; i<ady[a].size();i++){
        int b=ady[a][i];
        if(dist[b]==INF)
            dfs(b);
    }
}
// CodeX Junio y Julio
int main(){
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> e;
        if (n == 0 && e == 0)
            break;
        ady.assign(n, vi(0, 0));
        dist.assign(n, INF);

        int a, b;
        cin >> a >> b;
        ady[a].push_back(b);
        ady[b].push_back(a);

        dfs(a);
        int movements = 0;
        for (int i = 0; i < n; i++) {
            if (dist[i] == 1)
                movements++;
        }
        cout << movements << endl;
    }
return 0;
}
