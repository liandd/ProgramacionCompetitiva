#include <bits/stdc++.h>
using namespace std;
/*
int main() {
    int t = 0;
    cin >> t;
    while (t--) {
        long n;
        cin >> n;
        bool f = false;
        for (int x = 1; x <= n; x++) {
            for (int y = x + 1; y <= n; y++) {
                int z = n - x - y;
                if (z <= 0 || z == x || z == y || z % 3 == 0 || x % 3 == 0 || y % 3 == 0) {
                    continue;
                }
                cout << "YES\n";
                cout << x << " " << y << " " << z << "\n";
                f = true;
                break;
            }
            if (f) break;
        }
        if (!f) {
            cout << "NO\n";
        }
    }
    return 0;
}*/
    int main(){
       int t=0;
       cin>>t;
       while(t--){
            long n=0,i=0;
            cin>>n;
            vector<int>num,non;
            while(i<n){
                num.push_back(i+1);
                //cout<<num[i]<<" ";
                i++;
            }
            //cout<<"\n";
            int cont=0;
            for(int i=0;i<num.size();i++){
                if(num[i]%3!=0){
                    non.push_back(num[i]);
                }
            }
            bool f=false;
            for(int i=0;i<non.size();i++){
                if(non[i]==n){
                    non[i]=0;
                }
                for (int j=i+1;j<non.size()-2; j++) {
                    for (int k = j + 1; k < non.size()-1; k++) {
                        if (non[i] + non[j] + non[k] == n) {
                            cout<<"YES\n";
                            cout<<non[i]<<" "<<non[j]<<" "<<non[k]<<"\n";
                            cont++;
                            f=true;
                            break;
                        }
                    }
                    if (f) break;
                }
                if (f) break;
            }
            if(cont==0){
                cout<<"NO\n";
            }
       }
        return 0;
    }
