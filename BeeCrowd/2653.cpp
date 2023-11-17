#include<bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> joya;
    string s;
    while (cin >> s) {
        joya[s]++;
    }
    cout << joya.size() << endl;
    return 0;
}