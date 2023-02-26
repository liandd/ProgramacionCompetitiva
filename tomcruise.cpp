#include <bits/stdc++.h>

const int N = 1e4 + 7;
using namespace std;

int wei[N];
std::vector<pair<int,int> > g[N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	for(int i = 0; i < n; ++i)
		cin >> wei[i];
		
	int res = 1e9;
	int mini = *min_element(wei, wei + n);
	
	set<tuple<int,int,int> > kolejka;
	map<pair<int,int>, int> cost;
		
	for(int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		
		res = min(res, wei[a] + wei[b] + c);
		
		g[a].push_back({b, c});
		g[b].push_back({a, c});
		kolejka.insert({c + wei[a], a, b});
		kolejka.insert({c + wei[b], b, a});
		cost[{a, b}] = wei[a] + c;
		cost[{b, a}] = wei[b] + c;
	}
	
	while(kolejka.size()) {
		auto best = *kolejka.begin();
		kolejka.erase(kolejka.begin());
		
		int c = get<0>(best);
		int u = get<1>(best);
		int v = get<2>(best);
		
		if(c + mini > res) break;
		if(u == v) continue;
		res = min(res, c + wei[v]);
		
		for(auto ed : g[v]) {
				int nc = ed.second + c;
				if (cost.count({u, ed.first}) == 0 or cost[{u, ed.first}] > nc) {
					kolejka.erase({cost[{u, ed.first}], u, ed.first});
					cost[{u, ed.first}]  = nc;
					kolejka.insert({cost[{u, ed.first}], u, ed.first});
				}
		}
		
	}
	cout << res << '\n';
}