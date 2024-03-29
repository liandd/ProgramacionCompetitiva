#include <bits/stdc++.h>
#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)

using namespace std;

int minimum_rotation(string s) {
  int n = s.size();
  s += s;
  int mini = 0, p = 1, k = 0;

  while (p < n and mini + k + 1 < n) {
    if (s[mini + k] == s[p + k]) {
      k++;
    }
    else if(s[mini + k] < s[p + k]) {
      p = p + k + 1;
      k = 0;
    }
    else if(s[mini + k] > s[p + k]) {
      mini = max(mini + k + 1, p);
      p = mini + 1;
      k = 0;
    }
  }
  cout << s.substr(mini, n) << endl;
  return mini;
}

int main() {
  fast;
  int n;
  cin >> n;

  while (n--) {
    string s;
    cin >> s;
    cout << minimum_rotation(s) + 1 << endl;
  }

  return 0;
}
