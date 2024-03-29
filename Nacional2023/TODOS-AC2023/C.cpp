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

const int N = 303;
const int INF = (int) 1e9;
int dis1[2][N][N], dis2[2][N][N];

const int dx[9] = {-2,-1,1,2,2,1,-1,-2};
const int dy[9] = {1,2,2,1,-1,-2,-2,-1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
  
    //freopen("input.txt", "r", stdin );
    
    int n, a, b, c, d; 
    while(cin >> n >> a >> b >> c >> d ) {
        if( n == 0 ) break;
        
        for( int i = 0; i < n; ++ i )
        {
            for(int j = 0; j < n; ++ j)
            {
                dis1[0][i][j] = dis1[1][i][j] = INF;
                dis2[0][i][j] = dis2[1][i][j] = INF;
            }
        }
                
                
        queue< pair< int, pii > > q1;
        q1.push( { 0, {a, b }} );
        dis1[0][a][b] = 0;
        while( !q1.empty() )
        {
            int par = q1.front().ff;
            int x = q1.front().ss.ff, y = q1.front().ss.ss;
            q1.pop();
            
            for( int d = 0; d < 8; ++ d )
            {
                const int nx = x + dx[d], ny = y + dy[d];
                if( nx >= 0 && nx < n && ny >= 0 && ny < n && dis1[par^1][nx][ny] == INF )
                {
                    dis1[par^1][nx][ny] = dis1[par][x][y] + 1;
                    q1.push( { par^1, {nx, ny}});
                }
            }
        }
        
        int ans = INF;
        
        queue< pair< int, pii > > q2;
        q2.push( { 0, {c, d} } );
        dis2[0][c][d] = 0;
        while( !q2.empty() )
        {
            int par = q2.front().ff;
            int x = q2.front().ss.ff, y = q2.front().ss.ss;
            q2.pop();
            
            ans = min( ans, max( dis1[par][x][y], dis2[par][x][y]));
            
            for( int d = 0; d < 8; ++ d )
            {
                const int nx = x + dx[d], ny = y + dy[d];
                if( nx >= 0 && nx < n && ny >= 0 && ny < n && dis2[par^1][nx][ny] == INF )
                {
                    dis2[par^1][nx][ny] = dis2[par][x][y] + 1;
                    q2.push( { par^1, {nx, ny }});
                }
            }
        }
        
        if( ans == INF ) cout << "*" << '\n';
        else cout << ans << '\n';
    }
    
    
    return 0;
}
