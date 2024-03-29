#include<bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    int ceros = 0;
    int unos = 0;
    float respuesta1 = 0, respuesta2 = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '1') {
            unos++;
            if (ceros > respuesta2) {
                respuesta2 = ceros;
            }
            ceros = 0;
        } else {
            ceros++;
            if (unos > respuesta1) {
                respuesta1 = unos;
            }
            unos = 0;
        }
    }
    if (unos > respuesta1) {
        respuesta1 = unos;
    }
    if (ceros > respuesta2) {
        respuesta2 = ceros;
    }
    ((max(respuesta1,respuesta2)>=7))?printf("YES\n"):printf("NO\n");
    return 0;
}
