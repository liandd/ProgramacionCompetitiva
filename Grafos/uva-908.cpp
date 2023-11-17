#include<bits/stdc++.h>
using namespace std;
#define MAX 1000001
struct Edge{
    int v1, v2;
    int weight;
}edge[MAX];
int p[MAX];
inline int find(int a);
int kruskal(int N, int E);
int main(){
    int N;
    bool first = true;
    while (cin >> N){
        int a, b, w;
        int old_cost = 0, new_cost;
        for (int i=1; i<N; i++){
            cin >> a >> b >> w;
            old_cost += w;
        }
        int K, M;
        cin >> K;
        for (int i=0; i<K; i++)
            cin >> edge[i].v1 >> edge[i].v2 >> edge[i].weight;
        cin >> M;
        for (int i=0; i<M; i++)
            cin >> edge[i + K].v1 >> edge[i + K].v2 >> edge[i + K].weight;
        new_cost = kruskal(N, K + M);
        if (first)
            first = false;
        else
            putchar('\n');
       cout << old_cost << '\n' << new_cost << '\n';
    }
    return 0;
}
int kruskal(int N, int E){
    for (int i=0; i<= N; i++)
        p[i] = i;
    sort(edge, edge + E,[](const Edge& a, const Edge& b)->bool{return a.weight < b.weight;});
    int e, cost = 0;
    for (int i=0,e=0; i<E&&e<N-1; e++, i++){
        while (find(edge[i].v1) == find(edge[i].v2))i++;
        p[find(edge[i].v1)] = find(edge[i].v2);
        cost += edge[i].weight;
    }
    return cost;
}
int find(int a){
    return a == p[a] ? a : (p[a] = find(p[a]));
}
