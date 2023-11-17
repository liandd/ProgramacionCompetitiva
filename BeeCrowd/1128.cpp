#include<bits/stdc++.h>
using namespace std;
#define INF -1
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
vector<vi> ady;
vi dist;
int origen,destino,n,e,cont;
int bfs(){
    dist[origen]=0;
    queue<int> q;
    q.push(origen);
    while(!q.empty()){
        int a=q.front();
        q.pop();
        cont++;
        for(int i=0; i<ady[a].size();i++){
            int v = ady[a][i];
            if (dist[v] == INF) {
                dist[v] = dist[a]+1;
                q.push(v);
        }
    }
    }
return cont;
}
int main(){
    while(cin>>n>>e && n && e){
        ady.assign(n,vi(0,0));
        dist.assign(n,INF);
        while(e--){
            int a,b,w;
            cin>>a>>b>>w;
            a--;b--;
            ady[a].push_back(b);
            if(w==2)ady[b].push_back(a);
        }
        bool ans = true;
        int ss=0;
        for(int i=0; i<n; i++){
            cont=0;
            origen = i;
            fill(dist.begin(),dist.end(),INF);
            ss = bfs();
            if(ss < n){
                ans = false;
                break;
            }
        }
        cout<<ans<<"\n";
    }
return 0;
}