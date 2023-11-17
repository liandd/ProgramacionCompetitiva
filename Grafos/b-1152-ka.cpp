#include<bits/stdc++.h>
using namespace std;
#define INF 1000001
struct Edge{
    int origen, destino;
    int pesoE;
}edge[INF];
int padre[INF];
inline int find(int a);
int kruskal(int N, int E);
// CodeX Junio y Julio
int main(){
    int m, n;
    while (cin>>m>>n && (m != 0 || n != 0)) {
        for (int i=0; i<n; i++) {
            cin >> edge[i].origen >> edge[i].destino >> edge[i].pesoE;
        }

        long long pesoTotal = kruskal(m, n);
        cout<<"peso:"<<pesoTotal<< "\n";
        long long ahorro = 0;
        for (int i = 0; i < n; i++) {
            cout<<"ahorrosAntes:"<<ahorro<<"\n";
            ahorro += edge[i].pesoE;
            cout<<"ahorrosADespues:"<<ahorro<<"\n";
        }
        cout<<"edge:\n";
        for (int i=0; i<n; i++) {
                cout<<"\npara i:"<<i<<"\n";
            cout<<"origen: "<< edge[i].origen <<"\ndestino: "<<edge[i].destino <<"\npesoE: "<< edge[i].pesoE<<"\n";
        }
        cout<<"padre:\n";
        for (int i=0; i<n; i++) {
                cout<<"para i:"<<padre[i]<<"\n";
        }
        long long ans = ahorro - pesoTotal;
        cout << ans << "\n";
    }

    return 0;
}
int kruskal(int N, int E){
    for (int i=0; i<=N; i++)
        padre[i] = i;
    sort(edge, edge + E, [](const Edge& a, const Edge& b)->bool{return a.pesoE < b.pesoE;});
    int e, cost = 0;
    for (int i=0, e=0; i<E&&e<N-1; e++,i++){
        while (find(edge[i].origen) == find(edge[i].destino)) i++;
        padre[find(edge[i].origen)] = find(edge[i].destino);
        cout<<"costAntes: "<<cost<< "\n";
        cout<<"pesoEdgeAntes: "<<edge[i].pesoE<< "\n";
        cost += edge[i].pesoE;
        cout<<"costDespues: "<<cost<< "\n";
        cout<<"pesoEdgeDespues: "<<edge[i].pesoE<< "\n";
    }
    return cost;
}
int find(int a){
    return a == padre[a] ? a : (padre[a] = find(padre[a]));
}
