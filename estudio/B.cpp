#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> pol[1000005];
vector<pair<int,int>> odw[1000005];
priority_queue<pair<int,pair<int,int>>> q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,b;
    cin>>a>>b;
    for(int x=0;x<a;x++){
        int c;
        cin>>c;
        q.push(make_pair(-c, make_pair(x,x)));
    }
    while(b--){
        int c,d,e;
        cin>>c>>d>>e;
        pol[c].push_back({d,e});
        pol[d].push_back({c,e});
    }
    while(!q.empty()){
        auto p = q.top();
        q.pop();
        if(odw[p.second.first].size() == 2 || (odw[p.second.first].size() == 1 && odw[p.second.first][0].second == p.second.second))
            continue;
        odw[p.second.first].push_back({-p.first, p.second.second});
        for(auto x:pol[p.second.first])
            if(odw[x.first].size() == 0 || (odw[x.first].size() == 1 && odw[x.first][0].second != p.second.second))
                q.push({p.first - x.second, {x.first,p.second.second}});
    }
    int mini = 1e9;
    for(int x=0;x<a;x++)
        mini = min(mini, odw[x][0].first + odw[x][1].first);
    cout<<mini<<"\n";
    return 0;
}

