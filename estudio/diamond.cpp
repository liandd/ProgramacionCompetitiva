#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::vector<int> VI;
typedef std::pair<int, int> PII;

constexpr int MOD = 360;
constexpr int INF = 1e9;
int N;
int seg[23][366];
int rad[23][366];
PII where_[23][366][366];
int dist[23][366][366];

int dd(int a, int b) {
    return std::min((a-b+MOD)%MOD, (b-a+MOD)%MOD);

}

PII where(PII pos, int obrot){
	if(where_[pos.X][pos.Y][obrot].X != -1) return where_[pos.X][pos.Y][obrot];
	std::vector<PII> score{{INF, 0}, {INF, 1}, {INF, 2}, {INF, 3}, {90, -1}};
	int fakt = (pos.Y + obrot) % MOD;
//	std::cerr << "fakt " << fakt << std::endl;
	if(pos.X > 0 && rad[pos.X - 1][pos.Y]) score[0].X = dd(fakt, 0);
	if(pos.X < N && rad[pos.X][pos.Y]) score[1].X = dd(fakt, 180);
	if(seg[pos.X][(pos.Y - 1 + MOD) % MOD]) score[2].X = dd(fakt, 270);
	if(seg[pos.X][pos.Y]) score[3].X = dd(fakt, 90);
	int ind = (*std::min_element(score.begin(), score.end())).Y;
	auto old = pos;
	if(ind == 0) pos.X--;
	if(ind == 1) pos.X++;
	if(ind == 2) pos.Y = (pos.Y - 1 + MOD) % MOD;
	if(ind == 3) pos.Y = (pos.Y + 1) % MOD;
	if(ind == -1) return where_[old.X][old.Y][obrot] = pos; 
	return where_[old.X][old.Y][obrot] = where(pos, obrot);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> N;
	FOR(i, N){
		int s;
		std::cin >> s;

		FOR(j, s){
			int a, b;
			std::cin >> a >> b;
			while(a != b){
				seg[i][a] = 1;
				a = (a+1)%MOD;
			}
		}

		std::cin >> s;
		FOR(j, s){
			int a;
			std::cin >> a;
			rad[i][a] = 1;
		}
	}

	PII start, end;
	std::cin >> start.X >> start.Y >> end.X >> end.Y;

	FOR(i, N) FOR(j, MOD) FOR(k, MOD) where_[i][j][k] = MP(-1, -1);

	start = where(start, 0);
	if(start == end){
		std::cout << 0 << "\n";
		return 0;
	}

	std::queue<PR<PII, int>> que;
	que.push(MP(start, 0));
	FOR(i, N) FOR(j, MOD) FOR(k, MOD) dist[i][j][k] = INF;
	dist[start.X][start.Y][0] = 0;

	VI moz{MOD-1, 1};

	while(SZ(que)){
		auto pr = que.front();
		que.pop();

		TRAV(obr, moz){
			auto nw = pr;
			nw.Y = (nw.Y+obr)%MOD;
			nw.X = where(nw.X, nw.Y);
			if(dist[nw.X.X][nw.X.Y][nw.Y] == INF){
				dist[nw.X.X][nw.X.Y][nw.Y] = dist[pr.X.X][pr.X.Y][pr.Y]+1;
				que.push(nw);
				if(nw.X == end){
					std::cout << dist[nw.X.X][nw.X.Y][nw.Y] << "\n";
					return 0;
				}
			}
		}
	}

	std::cout << "Impossible\n";

	return 0;
}