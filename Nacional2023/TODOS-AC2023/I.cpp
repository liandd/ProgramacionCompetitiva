/******************************************************************************

                              Online C++ Debugger.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Debug" button to debug it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int > pii;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair

const int N = 1010;
const int INF = (int) 1e9;
int v[N], dp[N][N], sum[N], best[N][N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
  
    //freopen("input.txt", "r", stdin );
    
    int n; 
    while(cin >> n) {
        if(n == 0) break;
        for(int i = 0; i < n; i++) cin >> v[i];
        
        
        for(int i = 0; i < n; i++) {
            sum[i+1] = sum[i] + v[i];
        }
        
        for(int i = 0; i < n; i++) best[i][i] = i;
        
        for(int len = 2; len <= n; ++len) {
            for(int i = 0; i+len-1 < n; ++i) {
                int j = i+len-1;
                int &ref = dp[i][j];
                ref = INF;
                for(int k = best[i][j-1]; k <= best[i+1][j]; ++k) {
                    if(k < j) {
                        int cur = dp[i][k] + dp[k+1][j];
                        if(cur < ref) {
                            best[i][j] = k;
                            ref = cur;
                        }
                    }
                }
                ref += sum[j+1] - sum[i];
            }
        }
        
        cout << dp[0][n-1] << '\n';
    }
    
    
    return 0;
}