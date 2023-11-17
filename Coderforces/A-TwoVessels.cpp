#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    while(n--){
        int a,b,c;
        cin>>a>>b>>c;
        int ans=0;
        ans=((abs(a-b)+1)/2+c-1)/c;
        cout<<ans<<"\n";
    }
    return 0;
}
