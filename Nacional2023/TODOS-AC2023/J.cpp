
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int > pii;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair

const int N = 1e8 + 10;

vector< int > ret = {
    3,
    20,
    119,
    696,
    4059,
    23660,
    137903,
    803760,
    4684659,
    27304196
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
  
    //freopen("input.txt", "r", stdin );
    
    /*
    ll root = 1;
    for( int i = 1; i < N; ++ i)
    {
        ll tar = 2LL * i * ( i + 1 ) + 1;
        while( root * root < tar ) root += 2;
        
        if( root * root == tar )
            cout << i << '\n';
    }*/
    
    int a, b;
    while( cin >> a >> b )
    {
        if( a == 0 && b == 0 ) break;
        
        int ans = 0;
        for( int x : ret )
            if( a <= x && x <= b )
                ++ans;
                
        cout << ans << '\n';
    }
    
    
    return 0;
}