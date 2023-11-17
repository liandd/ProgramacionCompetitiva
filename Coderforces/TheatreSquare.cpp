#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n, m, a;
    cin>>n>>m>>a;
    long long x=(n+a-1)/a;
    long long y=(m+a-1)/a;
    long long res=x*y;
    cout<<res<<"\n";
    return 0;
}
