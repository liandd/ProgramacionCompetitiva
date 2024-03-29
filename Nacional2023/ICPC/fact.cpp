#include <iostream>

using namespace std;

double calcularSumaFactoriales() {
    int N;
    cout << "Ingrese un número entero no negativo: ";
    cin >> N;

    if (N < 0) {
        cout << "El número ingresado es negativo. Por favor, ingrese un número no negativo." << endl;
        return 0; // Devolvemos 0 en caso de entrada inválida
    }

    double suma_factoriales = 0;
    double factorial = 1;

    for (int i = 1; i <= N; ++i) {
        factorial *= i;
        suma_factoriales += factorial;
    }

    return suma_factoriales;
}

int main() {
    double suma_factoriales = calcularSumaFactoriales();

    if (suma_factoriales > 0) {
        cout << "La suma de los factoriales es: " << suma_factoriales << endl;
    }

    return 0;
}
