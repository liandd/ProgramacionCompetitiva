/******************************************************************************

                              Online C++ Debugger.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Debug" button to debug it.

*******************************************************************************/


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int > pii;

const int N = 1010;

const int alpha = 400; 
struct suffix_array { // s MUST not have 0 value
  vector<int> sa, pos, lcp;
  suffix_array(vector<int> s) {
    s.push_back(1); // always add something less to input, so it stays in pos 0
    int n = s.size(), mx = max(alpha, n)+2;
    vector<int> a(n), a1(n), c(n+1), c1(n+1), head(mx), cnt(mx);
    pos = lcp = a;
    for(int i = 0; i < n; i++) c[i] = s[i], a[i] = i, cnt[ c[i] ]++;
    for(int i = 0; i < mx-1; i++) head[i+1] = head[i] + cnt[i];
    for(int k = 0; k < n; k = max(1, k<<1)) {
      for(int i = 0; i < n; i++) {
        int j = (a[i] - k + n) % n;
        a1[ head[ c[j] ]++ ] = j;
      }
      swap(a1, a);
      for(int i = 0, x = a[0], y, col = 0; i < n; i++, x = a[i], y = a[i-1]) {
        c1[x] = (i && c[x] == c[y] && c[x+k] == c[y+k]) ? col : ++col;
        if(!i || c1[x] != c1[y]) head[col] = i;
      }
      swap(c1, c);
      if(c[ a[n-1] ] == n) break;
    }
    swap(sa, a);
    for(int i = 0; i < n; i++) pos[ sa[i] ] = i;
    for(int i = 0, k = 0, j; i < n; lcp[ pos[i++] ] = k) { /// lcp[i, i+1]
      if(pos[i] == n-1) continue;
      for(k = max(0, k-1), j = sa[ pos[i]+1 ]; s[i+k] == s[j+k]; k++);
    }
  }
  int& operator[] ( int i ){ return sa[i]; }
};

struct rmq {
  vector<vector<int>> table;
  rmq(vector<int> &v) : table(20, vector<int>(v.size())) {
    int n = v.size();
    for (int i = 0; i < n; i++) table[0][i] = v[i];
    for (int j = 1; (1<<j) <= n; j++)
      for (int i = 0; i + (1<<j-1) < n; i++)
        table[j][i] = min(table[j-1][i], table[j-1][i + (1<<j-1)]);
  }
  int query(int a, int b) {
    int j = 31 - __builtin_clz(b-a+1);
    return min(table[j][a], table[j][b-(1<<j)+1]);
  }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
  
    // freopen("input.txt", "r", stdin );
    
    int n, k; 
    while(cin >> n >> k) {
        if(n == 0 && k == 0) break;
        
        // vector<string> strings;
        vector<int> all;
        vector<int> id;
        int separator = 'z'+1;
        string ans1 = "";
        for(int i = 0; i < n; i++) {
            string s; cin >> s;
            if(s.size() > ans1.size()) {
                ans1 = s;
            } else if(s.size() == ans1.size() && s < ans1) {
                ans1 = s;
            }
            // strings.push_back(s);
            for(char c : s) {
                all.push_back(c);
                id.push_back(i);
            }
            all.push_back(separator);
            separator++;
            id.push_back(i);
        }
        
        if(k == 1) {
            cout << ans1 << endl;
            continue;
        }
        
        n = all.size();
        suffix_array sa(all);
        
        rmq ds(sa.lcp);
        
        int cnt = 0;
        map<int, int> freq;
        int best_len = 0;
        int pos = -1;
        for(int i = 1, j = 1; i <= n; i++) {
            // cout << sa[i] << " -> ";
            // for(int j = sa[i]; j < all.size(); j++) {
            //     cout << char(all[j]);
            // }
            // cout << endl;
            while(j <= n && cnt < k) { /// add the jth
                int &t = freq[ id[ sa[j] ] ]; 
                cnt += t == 0;
                t++;
                j++;
            }
            
            int len = i+1 == j ? 0: ds.query(i, j-2);
            if(len > best_len) {
                best_len = len;
                pos = sa[i];
            }
            
            // remove ith
            int &t = freq[ id[ sa[i] ] ];
            t--;
            cnt -= t == 0;
        }
        if(best_len == 0) {
            cout << "*\n";
            continue;
        }
        while(best_len--) {
            cout << char(all[pos]);
            pos++;
        }
        cout << '\n';
        
    }
    
    return 0;
}
