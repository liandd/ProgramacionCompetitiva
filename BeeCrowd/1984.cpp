#include <iostream>
#include <string>
#include <algorithm>
usign namespace std;
int main() {
    string line;
    cin >> line;
    reverse(line.begin(), line.end());
    cout << line << "\n";
    return 0;
}
