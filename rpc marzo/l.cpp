#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, i, k;
    cin >> n >> i >> k; //3 2 2

    double ciclos = 0;
    for (int j = 1; j <= n; j++) {
        cout<<"ciclos en j="<<j<<" ciclos= "<<ciclos<<"\n";
        double p = pow(double(j)/n,k) - pow(double(j-1)/n,k);
        cout<<"p en j="<<j<<" p="<<p<<"\n";
        if (j >= i) {
                cout<<"Entro en if\n";
            ciclos += p * (j+1)/2.0;
            cout<<"ciclos en if :"<<ciclos<<"\n";
        } else {
            cout<<"Entro en else\n";
            ciclos += p * i;
            cout<<"ciclos en else :"<<ciclos<<"\n";
        }
    }

    cout << fixed << setprecision(9) << ciclos << endl;
}
