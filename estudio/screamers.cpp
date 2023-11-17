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

constexpr int MOD = 1000000007;

constexpr int N = 69;

struct Mat{
	int tab[N][N];

	Mat(){
		FOR(i, N) FOR(j, N) tab[i][j] = 0;
	}

	int size() const{
		return N;
	}
};

Mat mul(const Mat& a, const Mat& b){
	Mat ret;
	FOR(i, SZ(a)){
		FOR(j, SZ(a)){
			FOR(k, SZ(a)){
				ret.tab[i][j] = (ret.tab[i][j] + 1ll * a.tab[i][k] * b.tab[k][j])%MOD;
			}
		}
	}
	return ret;
}

Mat add(const Mat& a, const Mat& b){
	Mat ret;
	FOR(i, SZ(a)){
		FOR(j, SZ(a)){
			ret.tab[i][j] = (a.tab[i][j] + b.tab[i][j])%MOD;
		}
	}
	return ret;
}

VI mul(const Mat& a, const VI& vec){
	assert(a.size() == SZ(vec));
	VI ret(SZ(vec));
	FOR(i, SZ(vec)){
		FOR(j, SZ(vec)){
			ret[i] = (ret[i] + 1ll * vec[j] * a.tab[i][j])%MOD;
		}
	}
	return ret;
}

Mat pw(Mat a, ll e){
	Mat ret;
	FOR(i, N) ret.tab[i][i] = 1;

	while(e){
		if(e&1) ret = mul(ret, a);
		a = mul(a, a);
		e>>=1;
	}
	return ret;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int k;
	ll n;
	std::cin >> k >> n;

	Mat mat;
	REP(i, 1, k+1){
		REP(j, 1, k+1){
			if(std::__gcd(i, j) == 1) mat.tab[i][j] = 1;
		}
	}
	REP(i, 1, k+1) mat.tab[i][0] = 1;

	auto xd = pw(mat, n);

	VI vc(N);
	vc[0] = 1;
	auto ans = mul(xd, vc);
	assert(ans[0] == 0);
	int sm = 0;
	REP(i, 1, k+1) sm = (sm + ans[i])%MOD;
	std::cout << sm << "\n";

	return 0;
}