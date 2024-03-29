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



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
  
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        int ans = 0, open = 0;
        for(char c : s) {
            if(c == '(') open++;
            else {
                if(open) open--, ans++;
            }
        }
        cout << ans*2 << endl;
    }
    
    
    return 0;
}
