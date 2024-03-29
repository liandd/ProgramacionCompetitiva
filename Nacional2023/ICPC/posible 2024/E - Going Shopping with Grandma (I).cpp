#include <bits/stdc++.h>
#define MOD 9999959999
using namespace std;

long memo[2001][2001];

long dp(long l, long s) {
  if (l <= 0 and s <= 0) return 0;
  if (memo[l][s] != -1) return memo[l][s];
  long ans = 0;
  if (s > 0) {
    ans += dp(l, s - 1) + 1;
    ans %= MOD;
  }

  if (l > 0) {
    ans += dp(l - 1, s + 1) + 1;
    ans %= MOD;
  }

  return memo[l][s] = ans % MOD;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long l, s;
  memset(memo, -1, sizeof(memo));

  while ((cin >> l >> s) and (l+s)) {
    cout << (dp(l, s) + 1) << endl;
  }
  return 0;
}
