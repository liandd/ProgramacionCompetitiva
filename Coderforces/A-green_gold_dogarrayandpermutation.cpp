#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int a,b;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            cin>>a;
            v.push_back({a,i});
        }
        sort(v.begin(),v.end());
        for(int i=0,j=n;i<n;i++,j--){
            v[i].first=j;
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[v[i].second]=v[i].first;
        }
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
}
