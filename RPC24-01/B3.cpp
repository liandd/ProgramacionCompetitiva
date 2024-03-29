#include <bits/stdc++.h>
using namespace std;

int main() {
    int capacidad, canciones;
    cin>>capacidad>>canciones;
    vector<int> minutos(canciones);
    for (int i = 0; i < canciones; ++i) {
        cin >> minutos[i];
    }
    sort(minutos.rbegin(), minutos.rend());
    int cd1=0, cd2=0;
    for (int i=0; i<canciones; ++i) {
        if (cd1<=cd2) {
            if (cd1 + minutos[i] <= capacidad) {
                cd1 += minutos[i];
            }
        } else {
            if (cd2+minutos[i] <= capacidad) {
                cd2+=minutos[i];
            }
        }
    }
    cout<<max(cd1, cd2)<<" "<<min(cd1, cd2)<<"\n";
    return 0;
}
