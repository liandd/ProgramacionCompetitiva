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

const int N = 100100;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
  
    int n;
    while ( cin >> n ) {
        if ( !n ) break;
        string res = "";
        bool first = true;
        while ( n-- ) {
            string curr;
            cin >> curr;
            
            if ( first )
                res = curr;
            int sz = min ( res.size(), curr.size() ), i = 0;
            for ( ; i < sz; ++i ) {
                if ( tolower ( res[i] ) != tolower ( curr[i] ) )
                    break;
            }
            res = res.substr ( 0, i );
            first = false;
        }
        for ( char &c : res ) c = tolower ( c );
        if ( res.size() )
            cout << res << endl;
        else
            cout << "*" << endl;
    }
    
    return 0;
}
