#include <bits/stdc++.h>

using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int>n1(n);
    vector<int>n2(n);
    for (int i = 0; i < n; i++) {
        cin >> n1[i];
    } 
    for (int i = 0; i < n; i++) {
        cin >> n2[i];
    }
    sort(n1.begin(), n1.end());
    sort(n2.begin(), n2.end());
    long long f = 0;
    long long s = 0;
    for (int i = 0; i < n; i++) {
        long long count = upper_bound(n2.begin(), n2.end(), n1[i]) - n2.begin();
        f += count;
    } 
    for (int i = 0; i < n; i++) {
        long long count = upper_bound(n1.begin(), n1.end(), n2[i]) - n1.begin();
        s += count;
    } 
    if (f > s) {
        cout << "first" << endl;
    }
    else if (f < s) {
        cout << "second" << endl;
        } else{ 
            cout << "tie" << endl;
        }
    return 0;
}
