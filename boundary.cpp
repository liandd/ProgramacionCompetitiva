#include<bits/stdc++.h>
using namespace std;
#define lson (i<<1)
#define rson (i<<1|1)
#define repeat(i, s, n) for(int i = s; i <= n; ++i)
#define foreach(i,items) for(auto &i: items)
#define downrep(i, n, s) for(int i = n; i >= s; --i)
#define lowbit(x) (x&-x)
#define bzero(x) memset(x, 0, sizeof(x))
#define bzeron(x, n) memset(x, 0, (n) * sizeof *x)
#define gcd(a,b) __gcd(a,b)
#define brkline puts("")
#define spaceout putchar(' ')
#define all(a) a.begin(),a.end()
#define pb	push_back

// using i128=__int128; //??????,?????
using i64 = long long;
using i32 = int;
const int INF = 0x3f3f3f3f;
const double tol = 1e-8;
const int P = 998244353;

int pop_count(i64 x) {
  return __builtin_popcountll(x);
}
int pop_count(int x) {
  return __builtin_popcount(x);
}

template<typename S, typename T>
bool check_and_save_min_in_lhs(S& lhs, const T& rhs) {
  return lhs < rhs ? 1 : lhs = rhs, 0;
}

template<typename S, typename T>
bool check_and_save_max_in_lhs(S& lhs, const T& rhs) {
  return lhs > rhs ? 1 : lhs = rhs, 0;
}
template<typename T>
T min_all(T ele) {
  return ele;
}

template<typename T, typename ...Args>
T min_all(T fst_el, Args ...others) {
  return min_all(fst_el, mins(others...));
}

template<typename T>
T maxs(T ele) {
  return ele;
}

template<typename T, typename ...Args>
T maxs(T fst_el, Args ...others) {
  return max(fst_el, maxs(others...));
}

template<typename T>
void read_int(T& num) {
  bool positive = true;
  char ch; num = 0;
  while (isspace(ch = getchar()));
  if (ch == '-')	positive = false;
  else num = ch - '0';
  while ((ch = getchar()) >= '0' && ch <= '9')
    num = num * 10 + ch - '0';
  if (!positive) num = -num;
}

void read_ints() {};
template <typename T, typename ...Args>
void read_ints(T& fst_el, Args&... others) { read_int(fst_el);read_ints(others...); }

template<typename T>
void int_out(T num) {
  if (num < 0) {
    putchar('-');
    num = -num;
  }
  if (num > 9)
    int_out(num / 10);
  putchar(num % 10 + '0');
}

void int_outs() { brkline; }
template<typename T, typename ...Args>
void int_outs(T fst_ele, Args ...others) {
  int_out(fst_ele);
  spaceout;
  int_outs(others...);
}

int gcd(int a, int b) {
  return !b ? a : gcd(b, a % b);
}

void getFactors(int num, vector<int>& res) {

  res.push_back(num);
  if (!(num & 1)) res.push_back(2), res.push_back(num / 2);

  repeat(i, 3, sqrt(num)) {
    if (num % i == 0) {
      res.push_back(i);
      res.push_back(num / i);
    }
  }
}

void solve(int case_t) {
  int n, m;
  read_ints(n, m);
  vector<int> ans({ 1, 2 });

  getFactors(gcd(n - 2, m), ans);
  getFactors(gcd(n - 1, m - 1), ans);
  getFactors(gcd(n, m - 2), ans);

  sort(ans.begin(), ans.end());
  int x = unique(ans.begin(), ans.end()) - ans.begin();
  ans.resize(x);

  printf("%d ", ans.size());
  for (int e : ans) {
    printf("%d ", e);
  }
  puts("");

}

int main() {
  int t = 1;
  read_int(t);
  repeat(i, 1, t) {
    solve(i);
  }
  return 0;
}
