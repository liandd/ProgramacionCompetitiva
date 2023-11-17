#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio (false);

    size_t count;

    cin >> count;

    for (size_t i = 0; i < count; i++) {
        size_t num;
        cin >> num;

        if (num % 2 == 0 && ((num % 3 == 0) || (num % 4 == 0))) { //Divisible by 2 and 3 or 4
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}