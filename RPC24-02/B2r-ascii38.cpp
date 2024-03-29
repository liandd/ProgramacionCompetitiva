#include<bits/stdc++.h>
using namespace std;

long long ataque(long long n) {
    if (n == 1) return 1;
    if (n % 2 == 0) return 1 + ataque(n / 2);
    else return 1 + ataque(n - 1);
}

int main() {
    long long n;
    cin >> n;
    cout << ataque(n) << "\n";
    return 0;
}
