#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int w,h,x,y;
    cin>>w>>h>>x>>y;
    if(w % 2 == 0 || h % 2 == 0) {
        cout<<"Win\n";
    } else {
        if ((x+y) & 1) {
            cout<<"Win\n";
        } else {
            cout<<"Lose\n";
        }
    }
	return 0;
}

