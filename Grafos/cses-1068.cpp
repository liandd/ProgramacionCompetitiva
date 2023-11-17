#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin >> n;
    while (n != 1) {
        cout << n << " ";
        if (n & 1) {
            // n es impar
            n = (n << 1) + n + 1;
        } else {
            // n es par
            n >>= 1;
        }
    }
    cout << 1;
    return 0;
}
