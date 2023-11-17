#include<bits/stdc++h>
using namespace std;

int main(){
    int v;
    cin >> v;
    vector<list<int>> ady(v);
    int edges;
    cin >> edges;
    for (int i=0; i<edges; i++) {
        int u, v;
        cin >> u >> v;
        ady[u].push_back(v);
        ady[v].push_back(u);
    }
    for (int i=0; i<v; i++) {
        cout << "Lista adyacencia " << i << ": ";

        for (const auto& n : ady[i]) {
            cout << n << " ";
        }

        cout << "\n";
    }
    return 0;
}
