#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
int main() {
    int n;
    while (cin >> n) {
        vector<tuple<string, string, int>> estudiantes;
        for (int i = 0; i < n; ++i) {
            string nombre, region;
            int distancia;
            cin >> nombre >> region >> distancia;
            estudiantes.emplace_back(nombre, region, distancia);
        }
        sort(estudiantes.begin(), estudiantes.end(), [](auto const& a, auto const& b) {
            return tie(get<2>(a), get<1>(a), get<0>(a)) <
                   tie(get<2>(b), get<1>(b), get<0>(b));
        });
        for (auto const& estudiante : estudiantes) {
            cout << get<0>(estudiante) << "\n";
        }
    }
    return 0;
}