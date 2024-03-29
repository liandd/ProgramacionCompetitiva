#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long p;
  while (cin >> p) {
    cout << ((p <= 1)? 0: p-1) << endl;
  }
  return 0;
}
