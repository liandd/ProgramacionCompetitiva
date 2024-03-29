#include<bits/stdc++.h>
using namespace std;

int main(){
ios::sync_with_stdio(0);
cin.tie(0);
int n;
cin>>n;
while(n--){
    int m;
    cin >> m;
    string parentesis;
    cin >> parentesis;
    int cont1 = 0;
    int cont2 = 0;
    for (int i = 0; i < parentesis.size(); i++) {
        if (parentesis[i] == '(') {
            cont1++;
        }
        else{
            if(cont1){
                cont1--,cont2++;
            }
        }
    }
    cout<<cont2*2<<"\n";
}
return 0;
}

