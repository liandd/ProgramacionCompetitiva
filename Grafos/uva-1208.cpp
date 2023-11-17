#include<bits/stdc++.h>
using namespace std;
struct Edge {
    int origen, destino;
    int pesoE;
};
const int MAX = 26;
int padre[MAX];
int find(int a) {
    return a == padre[a] ? a : (padre[a] = find(padre[a]));
}
int kruskal(int N, int E, Edge edge[]) {
    for (int i = 0; i < N; i++)
        padre[i] = i;
    sort(edge, edge + E, [](const Edge& a, const Edge& b) -> bool {
        return a.pesoE < b.pesoE;
    });
    int e, cost = 0;
    for (int i = 0, e = 0; i < E && e < N - 1; e++, i++) {
        while (find(edge[i].origen) == find(edge[i].destino))
            i++;
        padre[find(edge[i].origen)] = find(edge[i].destino);
        cost += edge[i].pesoE;
        char origen = 'A' + edge[i].origen;
        char destino = 'A' + edge[i].destino;
        printf("%c-%c %d\n", origen, destino, edge[i].pesoE);
    }
    return cost;
}
int main() {
    int t, ciudades, c = 0, tmp;
    char coma;
    scanf("%d", &t);
    do{
        scanf("%d", &ciudades);
        Edge edges[MAX];
        int e = 0;
        for(int i=0; i<ciudades; i++) {
            for(int j=0; j<ciudades; j++) {
                scanf("%d%c", &tmp, &coma);
                if(i<j && tmp) {
                    edges[e].origen = i;
                    edges[e].destino = j;
                    edges[e].pesoE = tmp;
                    e++;
                }
            }
        }
        printf("Case %d:\n", ++c);
        kruskal(ciudades, e, edges);
        t--;
    }while(t>0);
    return 0;
}
