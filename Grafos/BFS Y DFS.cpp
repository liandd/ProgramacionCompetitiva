#include <bits/stdc++.h>
using namespace std;
#define INF -1
typedef vector <int> vi; //Vector base para adjList sin pesos
vector <vi> adjList;
vi dist;
int source, n, e;
void BFS(){
    dist[source]=0;//El bfs guarda las distancias que hay del source a los demás nodos, por lo que el nodo de origen consigo mismo no hay distancias.
    queue <int> q; q.push(source); //Ingresa un 0, tener en cuenta que la cola es FIFO, first in, first out
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int j = 0; j < (int)adjList[u].size(); j++){
            if(dist[j]!=INF) continue;
            dist[j]=dist[u]+1;
            q.push(j);
        }
    }
}
// CodeX Junio y Julio
int main(){
    //int n, e;
    cin>>n>>e;
    adjList.assign(0, vi(0, 0));
    dist.assign(n, INF);
    source=0;
    while(e--){
        int a, b;
        adjList[a].push_back(b);
    }
    BFS();
return 0;
}
