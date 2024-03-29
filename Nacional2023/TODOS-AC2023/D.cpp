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
  
    
    int n, m;
    while ( cin >> n >> m ) {
        if ( !n and !m ) continue;
        vector <int> vec;
        for ( int i = 0; i < n; ++i ) {
            int curr;
            cin >> curr;
            vec.pb ( curr );
        }
        sort ( vec.rbegin(), vec.rend() );
        ll mini = vec[0], maxi = vec[0];
        for ( int i = 1; i < n; ++i )
            mini -= vec[i], maxi += vec[i];
        mini = max ( mini, 0LL );
        while ( m-- ) {
            ll x, y;
            cin >> x >> y;
            ll sqrlen = x*x + y*y;
            if ( mini * mini <= sqrlen and sqrlen <= maxi*maxi )
                cout << "Y" << endl;
            else
                cout << "N" << endl;
        }
    }
    
    
    return 0;
}
