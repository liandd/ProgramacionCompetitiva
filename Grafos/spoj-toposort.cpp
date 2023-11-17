#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
vector<vi> ady;
vi inDegree;
vi toposort;

bool topologicalSort(int n) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i=1; i<=n; i++)
        if (inDegree[i] == 0)
            pq.push(i);
    while (!pq.empty()){
        int u = pq.top();
        pq.pop();
        toposort.push_back(u);
        for (int v : ady[u]){
            inDegree[v]--;
            if (inDegree[v] == 0) {
                pq.push(v);
            }
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
        cout << "IMPOSIBLE" << "\n";
    }else{
        for (int i=0; i<n; i++){
            cout << toposort[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
