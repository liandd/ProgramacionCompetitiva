#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>f;
    int n=0,i=0,res=0;
    for(cin>>n;i<n;i++){
        int tmp=0;
        cin>>tmp;
        f.push_back(tmp);
    }
    int c=0;
    sort(f.begin(),f.end());
    res=f[c]+f[c+1];
    cout<<res<<"\n";

return 0;
}
