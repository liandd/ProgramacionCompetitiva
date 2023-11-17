#include<bits/stdc++.h>
using namespace std;

int main() {
    string input;
    cin >> input;
    sort(input.begin(), input.end(), greater<char>());
    int largestNumber = stoi(input);
    cout << largestNumber << "\n";
    return 0;
}
