#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 7;


vector<pair<int,int> > g[N];
int wei[N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string s; cin >> s;
	
	int res = 0, cnt= 0;
	
	for (auto i : s) {
		if (i == '1') {
			res = max(res, (cnt + 1) / 2);
			cnt = 0;
		} else {
			cnt++;
		}
	}
	
	res = max(res, (cnt + 1) / 2);
	
	cout << res << "\n";
	
}