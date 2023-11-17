#include <bits/stdc++.h>
using namespace std;
const int MOD = 1073741824;
vector<int> divisores(1e6 + 1);
void sacarDivisores(int n) {
    for (int i=1; i<=n; i++) {
        for (int j=i; j<=n; j+=i) {
            divisores[j]++;
        }
    }
}
int main() {
    int num1, num2, num3;
    cin>>num1>>num2>>num3;
    int maxNum = num1*num2*num3;
    sacarDivisores(maxNum);
    long long sum=0;
    for (int i=1; i<=num1; i++) {
        for (int j=1; j<=num2; j++) {
            for (int k=1; k<=num3; k++) {
                sum+=divisores[i*j*k];
                sum%=MOD;
            }
        }
    }
    cout<<sum<<'\n';
    return 0;
}
