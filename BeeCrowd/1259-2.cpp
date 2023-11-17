#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> par;
    vector<int> impar;
    for(int i=0; i<n; i++) {
        int tmp;
        cin>>tmp;
        if(tmp%2==0){
            par.push_back(tmp);
        }
        else{
            impar.push_back(tmp);
        }
    }
    sort(par.begin(), par.end());
    sort(impar.rbegin(), impar.rend());

    for (int x: par) {
        cout<<x<<"\n";
    }
    for (int y: impar) {
        cout<<y<<"\n";
    }
    return 0;
}