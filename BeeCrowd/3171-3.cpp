#include<bits/stdc++.h>
using namespace std;

vector<int> padre;

int find(int a) {
    if (padre[a] == a)
        return a;
    return padre[a] = find(padre[a]);
}

void unionSets(int a, int b) {
    int raizA = find(a);
    int raizB = find(b);
    padre[raizA] = raizB;
}

int main() {
    int n, e;
    cin >> n >> e;
    padre.resize(n + 1 );
    for (int i = 1; i <= n; i++) {
        padre[i] = i;
    }

    while(e--){
        int a, b;
        cin >> a >> b;
        unionSets(a,b);
    }

    bool completo = true;
    for (int i = 2; i <= n; i++) {
        if (find(i) != find(1)) {
            completo = false;
            break;
        }
    }

    if (completo) {
        cout << "COMPLETO\n";
    } else {
        cout << "INCOMPLETO\n";
    }

    return 0;
}