#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
vector<vi> ady;
vi inDegree;
vi toposort;

bool topologicalSort(int n) {
    queue<int> q; //controla el paso de los nodos y sus vecinos, variación del bfs
    for(int i=1; i<inDegree.size(); i++){
        if(inDegree[i]==0) q.push(i); //Se insertan los indegree 0 ya que son los primeros que se visitan
    }
    while(!q.empty()){//posible: q.size()
        int u = q.front(); q.pop();
        toposort.push_back(u);
        for(int v: ady[u]){
            inDegree[v]--;
            if(inDegree[v]==0) q.push(v);
        }
    }
    return toposort.size() == n;
}
int main(){
    int n, e;
    cin >> n >> e;
    ady.resize(n + 1);
    inDegree.resize(n + 1);
    for (int i=0; i<e; i++){
        int a, b;
        cin >> a >> b;
        ady[a].push_back(b);
        inDegree[b]++;
    }
    if(!topologicalSort(n)){
        cout << "IMPOSSIBLE" << "\n";
    }else{
        for (int i=0; i<n; i++){
            cout << toposort[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
