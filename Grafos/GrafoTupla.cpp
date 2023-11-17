#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int, string> ti;
vector<ti> edgeList;

int main() {
  int n, e;
  cin >> n >> e;

  while (e--) {
    int a, b, w;
    string connectionType;
    cin >> a >> b >> w >> connectionType;

    edgeList.push_back(make_tuple(a, b, w, connectionType));
  }

  int q;
  cin >> q;

  while (q--) {
    int a, b;
    cin >> a >> b;

    bool found = false;

    for (const auto& edge : edgeList) {
      int u, v, w;
      string connectionType;
      tie(u, v, w, connectionType) = edge;

      if ((u == a && v == b) || (u == b && v == a)) {
        cout << "Consulta: " << a << " " << b << "\n";
        cout << "Distancia: " << w << " km\n";
        cout << "Estado de conservación: " << connectionType << "\n";
        found = true;
        break;
      }
    }

    if (!found) {
      cout << "Consulta: " << a << " " << b << "\n";
      cout << "No se encontró información para esta carretera\n";
    }
  }

  return 0;
}
