#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<double> sides(n);
    for (int i = 0; i < n; i++) {
        cin >> sides[i];
    }

    double total_volume = accumulate(sides.begin(), sides.end(), 0.0, [](double a, double b) {
        return a + b * b * b;
    });

    double max_side = *max_element(sides.begin(), sides.end());
    double container_side = cbrt(total_volume);

    if (container_side < max_side) {
        container_side = max_side;
    }

    cout << fixed << setprecision(9) << container_side << endl;

    return 0;
}
