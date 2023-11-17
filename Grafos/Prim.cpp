#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
vector<vii> adjList;

int prim(const vector<vii>& adjList, int vI){//Enviar el grafo, Y el nodo inicial
    int n=adjList.size();
    vector<bool> eA (n, false);//arbol espacion minima
    vector<int> minDist (n, INT_MAX);
    priority_queue<ii, vii, greater<ii>> pq;
    int ans=0;
    minDist[vI]=0;//minimaDistancia
    pq.push(ii{0,vI});
    while(!pq.empty()){
        int actV = pq.top().second;//vertice actual
        int actP = pq.top().first;//peso actual
        pq.pop();
        if(eA[actV])continue;
        eA[actV]=true;
        ans += actP;
        for(const auto& con: adjList[actV]){
            int vertice = con.first;
            int peso = con.second;
            if(!eA[vertice] && peso < minDist[vertice]){//Si en el arbol eA[vertice] no es true. y peso es menor que la minima distancia[vertice}
                minDist[vertice]=peso;
                pq.push(ii{peso,vertice});
            }
        }
    }
    return ans;
}
vector<int> Prim(const vector<vii>& adjList, int startNode) {
    int n = adjList.size(); // Número de nodos
    vector<int> dist(n, INT_MAX); // Distancias mínimas desde el MST
    vector<bool> visited(n, false); // Nodos visitados
    vector<int> parent(n, -1); // Padre de cada nodo en el MST
    // Usamos una cola de prioridad para seleccionar las aristas de menor peso
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    dist[startNode] = 0; // La distancia al nodo inicial es 0
    pq.push(make_pair(0, startNode)); // Agregamos el nodo inicial a la cola
    while (!pq.empty()) {
        int u = pq.top().second; // Obtener el nodo de menor distancia
        pq.pop();
        visited[u] = true; // Marcar el nodo como visitado
        // Recorrer los vecinos del nodo actual
        for (const auto& neighbor : adjList[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            // Si el vecino no ha sido visitado y la distancia es menor a la mínima actual
            if (!visited[v] && weight < dist[v]) {
                dist[v] = weight; // Actualizar la distancia mínima
                pq.push(make_pair(dist[v], v)); // Agregar el vecino a la cola de prioridad
                parent[v] = u; // Establecer el padre del vecino en el MST
            }
        }
    }
    return parent; // Retornar el arreglo de padres del MST
}
int main(){

return 0;
}
