 #include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t; // Leer el número de conjuntos de entradas
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b; // Leer los dos números de cada conjunto
        // Obtener el bit más significativo de a y b
        int bitA = (a >> 31) & 1;
        int bitB = (b >> 31) & 1;
        if (bitA > bitB) {
            cout << ">" << endl;
        } else if (bitA < bitB) {
            cout << "<" << endl;
        } else {
            // Comparar los bits restantes
            if ((a & 0x7FFFFFFF) > (b & 0x7FFFFFFF)) {
                cout << ">" << endl;
            } else if ((a & 0x7FFFFFFF) < (b & 0x7FFFFFFF)) {
                cout << "<" << endl;
            } else {
                cout << "=" << endl;
            }
        }
    }
    return 0;
}
