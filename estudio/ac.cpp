#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    double ruido_prom = accumulate(a.begin(), a.end(), 0.0, [](double sum, int val){
        return sum + pow(val, 2);}) / n;

    if (ruido_prom == 0){
        for (int i=0; i<n; i++){
            cout << "0 ";
        }
    }
    else{
        double factor=sqrt(x/ruido_prom);
        for (int i=0; i<n; i++){
            cout<<fixed;
            cout <<setprecision(9)<< a[i] * factor << " ";
        }
    }
    return 0;
}
