/*
5 7
2 6 2
6 5 2
1 2 3
2 5 5
5 1 5
2 5 6
6 4 7     este es el kruskal de array (retorna mst como entero)
          oes no se me grabo la pantalla del codeblocks en el momento jaaj
          mala mia el ruido
*/
#include<bits/stdc++.h>
using namespace std;
#define INF 1000001
struct Edge{
    int origen,destino,pesoE;
}edge[INF];
int padre[INF];
inline int find(int a);// truco de compilador, da importancia de velocidad
int kruskal(int N, int E);//nodos , aristas
int main(){
    int n,e;
    while(cin>>n>>e && (n!=0 || e!=0)){//no dio con el while ajaj, aqui se quedo pensando
        for(int i=0; i<e; i++){
            cin>>edge[i].origen>>edge[i].destino>>edge[i].pesoE;
        }
        long long mst = kruskal(n,e);
        cout<<"MST :"<<mst<<"\n";
    }
return 0;
}
int kruskal(int N, int E){
    for(int i=0;i<=N; i++){
        padre[i]=i;
    }
    sort(edge,edge+E,[](const Edge& a, const Edge& b)->bool{return a.pesoE<b.pesoE;});//sort de lamba que ordena con respecto a la arista de menor peso
    int e=0, mst=0;
    //union
    for(int rango=0, e=0; rango<E && e<N-1; e++, rango++){//evitar desbordamiento
        while(find(edge[rango].origen) == find(edge[rango].destino))rango++;
        padre[find(edge[rango].origen)] = find(edge[rango].destino);//aqui hace union, complejidad rapida
        mst +=edge[rango].pesoE;
    }
    return mst;
}
int find(int a){
    return a == padre[a] ? a : (padre[a]= find(padre[a]));
}//ternario recursivo
