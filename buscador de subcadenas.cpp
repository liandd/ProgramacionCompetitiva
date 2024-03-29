#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    string cadenaPrincipal;
    getline(cin, cadenaPrincipal);

    string subcadena;
    cin >> subcadena;

    int contador = 0;


    size_t pos = cadenaPrincipal.find(subcadena, 0);
    while (pos != string::npos) {

        contador++;
        pos = cadenaPrincipal.find(subcadena, pos + 1);
    }

    cout << "La subcadena \"" << subcadena << "\" aparece " << contador << " veces en la cadena principal.\n";

    return 0;
}
