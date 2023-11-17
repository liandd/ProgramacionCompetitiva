#include<bits/stdc++.h>
using namespace std;
int main() {
    int t, n;
    cin >> t;
    for(int k=1; k<=t; k++){
        cin >> n;
        int a[n];
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        n = (n/2);
        cout << "Case " << k << ": " << a[n] << endl;
    }
    return 0;
}