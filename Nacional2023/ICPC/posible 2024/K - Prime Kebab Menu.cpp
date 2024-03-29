#include <bits/stdc++.h>
#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)

using namespace std;
typedef long long ll;

vector<bool> criba(10000005,false);
vector<int> primes;

void sieve() {
  primes.push_back(2);

  for (int i = 3; i < criba.size(); i += 2) {
    if (!criba[i]) {
      primes.push_back(i);
      for (int j = i; j < criba.size(); j += i) {
        criba[j] = true;
      }
    }
  }
}

ll solve(ll n) {
  ll ans = 0;
  for (int i = 0; i < primes.size(); i++) {
    if (n % primes[i] == 0) {
      while (n % primes[i] == 0) {
        n /= primes[i];
        ans++;
      }
    }
    if (n <= 1) break;
  }
  
  return (n > 1)? ans + 1 : ans;
}

int main() {
  fast;
  sieve();
  ll n;

  while (cin >> n and n != 1) {
    cout << solve(n) << endl;
  }

  return 0;
}
