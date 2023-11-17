#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 0;
    for (int i = 0; i < n-1; i++) {
        if (s[i] == s[i+1]) {
            cnt++;
            s[i+1] = s[i+1] == '+' ? '-' : '+';
        }
    }
    cout << cnt << endl;
    return 0;
}
