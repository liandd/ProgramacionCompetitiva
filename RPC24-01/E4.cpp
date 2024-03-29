#include<bits/stdc++.h>
using namespace std;

int main(){
    double a, b;
    cin >> a >> b;

    if (a <= 0 || a >= 100 || b <= 0 || b >= 100) {
        return 0;
    }

    double factor = (a / (100 - a)) / (b / (100 - b));

    cout << fixed;

    if (factor - static_cast<int>(factor) == 0) {
        cout << setprecision(1) << factor << endl;
    } else {
        cout << setprecision(9) << factor << endl;
    }

    return 0;
}
