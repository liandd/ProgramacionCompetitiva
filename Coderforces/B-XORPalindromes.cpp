#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int> ans(n + 1);
        int cnt = 0, a = 0, b = 0;
        int i=0, j=n-1;
        do{
            if (s[i] != s[j]) cnt++;
            if (s[i] == s[j] && (s[i] == '0')) a++;
            else if (s[i] == s[j] && (s[i] == '1')) b++;
            i++;
            j--;
        }while(i<j);
        if (cnt == 0) ans[0] = 1;
        int v = 0;
        if (n & 1) v = 1;
        for(int i=1; i<=n; i++){
            if (cnt > i)continue;
            int y=i-cnt;
            if((y > (a * 2 + b * 2) + v))continue;
            if (y&1) {
                if(n%2==0)
                    continue;
                else ans[i] = 1;
            }
            else ans[i] = 1;
        }
        string str;
        for (int i=1;i<= n+1;i++)
            str.push_back(ans[i-1]+'0');
        cout<<str<<"\n";
    }
    return 0;
}
