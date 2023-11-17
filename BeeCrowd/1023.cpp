#include <bits/stdc++.h>
using namespace std;

#define fo(i,n) for(int i=0; i<(n); ++i)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef map<int, int> mii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int count = 0, n;
    while(cin >> n && n){
        if(count != 0) cout << "\n";
        mii freq;
        int total_x = 0, total_y = 0;
        fo(i, n){
            int x, y;
            cin >> x >> y;
            total_x += x;
            total_y += y;
            freq[y/x] += x;
        }
        cout << "Cidade# " << ++count << ":\n";
        bool first = true;
        for(auto& p : freq){
            if(!first) cout << " ";
            else first = false;
            cout << p.S << "-" << p.F;
        }
        cout << "\n";
        cout << "Consumo medio: " << fixed << setprecision(2) << floor(100 * (float)total_y / total_x) / 100 << " m3.\n";
    }
    return 0;
}
