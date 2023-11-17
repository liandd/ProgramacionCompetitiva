#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, l;
    cin >> n >> l;

    map<int, int> led_string;

    for (int i = 1; i <= n; i++) {
        led_string[i] = i;
    }

    for (int i = 0; i < l; i++) {
        int x, y;
        cin >> x >> y;
        int parent_x = led_string[x];
        int parent_y = led_string[y];
        for (auto& p : led_string) {
            if (p.second == parent_y) {
                p.second = parent_x;
            }
        }
    }

    bool completo = true;
    for (int i = 2; i <= n; i++) {
        if (led_string[i] != led_string[1]) {
            completo = false;
            break;
        }
    }

    if (completo) {
        cout << "COMPLETO\n";
    } else {
        cout << "INCOMPLETO\n";
    }

    return 0;
}