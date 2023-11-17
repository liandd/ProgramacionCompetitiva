#include <iostream>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        int row = 0;
        int value = 1;
        while (value < n) {
            row++;
            value = (value * (row + 1)) / (row - 1); // calculate value using binomial coefficient
        }
        cout << row << endl;
    }
    return 0;
}

