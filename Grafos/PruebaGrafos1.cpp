#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> ii;
typedef vector<ii> vii;
vector <vii> adjList;//Vector de vector de pares

int main(){
    int n, e;
    cin>>n>>e;
    //resize(), assign(), clear()
    adjList.assign(n, vii(0,ii{0,0}));
    while(e--){//nosotros guardamos es las conexiones
        int a, b, w;
        cin>>a>>b>>w;
        //no dirigido
        // 1 2 3
        // a=1 b=2 w=3 weigth
        //adjList[a].push_back(ii{b, w}); //1 --->2 = 3
        //adjList[b].push_back(ii{a, w}); //2 --- >1 = 3
        //dirigido
        adjList[a].push_back(ii{b, w});
    }
    for(int i=0; i<adjList.size(); i++){
        cout<<i<<": "<<adjList[i].size()<<"\n";
        /*for(int j=0; j<adjList[i].size(); j++){
            cout<<adjList[i][j].first<<" = "<<adjList[i][j].second<<"\n";
        }*/
    }

return 0;
}
