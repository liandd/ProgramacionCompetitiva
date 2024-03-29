 #include<bits/stdc++.h>
using namespace std;

struct P{
    int x;
    int y;
};

double distancia(P p1, P p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double pendiente(P p1, P p2) {
    return (p2.x == p1.x) ? INFINITY : static_cast<double>(p2.y - p1.y) / (p2.x - p1.x);

}

bool sonParalel(double pendiente1, double pendiente2) {
    return pendiente1 == pendiente2;
}

bool sonIgual(double tam1, double tam2) {
    return abs(tam1 - tam2) < 1e-9;
}

bool esCuadrado(vector<double>& lados, vector<double>& angulos) {
    return sonIgual(lados[0], lados[1]) && sonIgual(lados[1], lados[2]) && sonIgual(lados[2], lados[3]) &&
           sonIgual(angulos[0], 90) && sonIgual(angulos[1], 90) && sonIgual(angulos[2], 90) && sonIgual(angulos[3], 90);
}

bool esRectangulo(vector<double>& angulos) {
    return sonIgual(angulos[0], 90) && sonIgual(angulos[1], 90) && sonIgual(angulos[2], 90) && sonIgual(angulos[3], 90);
}

bool esRombo(vector<double>& lados) {
    return sonIgual(lados[0], lados[1]) && sonIgual(lados[1], lados[2]) && sonIgual(lados[2], lados[3]);
}

bool esParalelogramo(double p1, double p2, double p3, double p4) {
    return sonParalel(p1, p3) && sonParalel(p2, p4);
}

bool esTrapecio(vector<double>& lados, double p1, double p2, double p3, double p4) {
    return (sonIgual(lados[0], lados[1]) && !sonIgual(p1, p3)) ||
           (sonIgual(lados[1], lados[2]) && !sonIgual(p2, p4)) ||
           (sonIgual(lados[2], lados[3]) && !sonIgual(p1, p3)) ||
           (sonIgual(lados[3], lados[0]) && !sonIgual(p2, p4));
}

bool esCometa(double p1, double p2, double p3, double p4) {
    return (sonParalel(p1, p3) && sonParalel(p2, p4)) ||
           (sonParalel(p1, p2) && sonParalel(p3, p4));
}

string checker(vector<P>& puntos) {
    vector<double> lados(4);
    vector<double> angulos(4);
    for (int i = 0; i < 4; ++i) {
        lados[i] = distancia(puntos[i], puntos[(i + 1) % 4]);
    }
    vector<double> pendientes(4);
    for (int i = 0; i < 4; ++i) {
        pendientes[i] = pendiente(puntos[i], puntos[(i + 1) % 4]);
    }
    for (int i = 0; i < 4; ++i) {
        P p1 = puntos[i];
        P p2 = puntos[(i + 1) % 4];
        P p3 = puntos[(i + 2) % 4];
        angulos[i] = atan2(p2.y - p1.y, p2.x - p1.x) - atan2(p3.y - p2.y, p3.x - p2.x);
        if (angulos[i] < 0) {
            angulos[i] += 2 * M_PI;
        }
        angulos[i] *= 180 / M_PI;
    }

    if (esCuadrado(lados, angulos)) {
        return "square";
    } else if (esRectangulo(angulos)) {
        return "rectangle";
    } else if (esRombo(lados)) {
        return "rhombus";
    } else if (esParalelogramo(pendientes[0], pendientes[1], pendientes[2], pendientes[3])) {
        return "parallelogram";
    } else if (esTrapecio(lados, pendientes[0], pendientes[1], pendientes[2], pendientes[3])) {
        return "trapezium";
    } else if (esCometa(pendientes[0], pendientes[1], pendientes[2], pendientes[3])) {
        return "kite";
    } else {
        return "none";
    }
}

int main() {
    vector<P> puntos(4);
    for (int i = 0; i < 4; ++i) {
        cin >> puntos[i].x >> puntos[i].y;
    }
    string result = checker(puntos);
    cout << result << endl;
    return 0;
}

