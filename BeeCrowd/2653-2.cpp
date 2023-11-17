#include<bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> joya;
    string s;
    int n=0;
    while (cin >> s && n) {
        n=s.size();
        joya[s]++;
        n--;
    }
    cout << joya.size() << endl;
    return 0;
}
