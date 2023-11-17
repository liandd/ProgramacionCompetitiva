#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> prices(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> prices[i];
    }

    vector<long long> cumulativeSum(n + 1);
    cumulativeSum[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cumulativeSum[i] = cumulativeSum[i - 1] + prices[i];
    }

    int t;
    cin >> t;

    while (t--) {
        char transactionType;
        cin >> transactionType;

        if (transactionType == 'U') {
            int houseNumber;
            long long priceIncrease;
            cin >> houseNumber >> priceIncrease;
            prices[houseNumber] += priceIncrease;

            // Actualizamos la suma acumulada después de la actualización
            for (int i = houseNumber; i <= n; ++i) {
                cumulativeSum[i] += priceIncrease;
            }
        } else if (transactionType == 'R') {
            int startHouse, endHouse;
            cin >> startHouse >> endHouse;

            long long totalPrice = cumulativeSum[endHouse] - cumulativeSum[startHouse - 1];
            cout << totalPrice << "\n";
        }
    }

    return 0;
}
