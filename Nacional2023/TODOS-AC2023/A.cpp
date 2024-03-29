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
  
    //freopen("input.txt", "r", stdin );
    int n;
    while ( cin >> n ) {
        if ( !n ) break;
        cout << ( n * ( n - 1 ) + 1 ) << '\n';
    }
    
    return 0;
}
