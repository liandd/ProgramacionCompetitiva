#include<bits/stdc++.h>
using namespace std;

int main(){
    int X;
    vector<int> values;
    while (cin >> X){
        values.push_back(X);
        nth_element(values.begin(),
                    values.begin() + values.size() / 2,
                    values.end());
        int m1 = *(values.begin() + values.size() / 2);
        int m2 = m1;
        if ((values.size() & 1) == 0){
            nth_element(values.begin(),
                        values.begin() + values.size() / 2 - 1,
                        values.end());
            m2 = *(values.begin() + values.size() / 2 - 1);
        }
        cout << (m1 + m2) / 2 << endl;
    }
    return 0;
}
