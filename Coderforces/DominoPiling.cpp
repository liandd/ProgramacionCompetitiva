#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,contDomi=0,domPieza=0;
    cin>>n>>m;
    vector<vector<char>>tabla(n,vector<char>(m, '*'));
    /*for(int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cout<< tabla[i][j];
        }
        cout << "\n";
    }*/
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(tabla[i][j]=='*'){
                tabla[i][j]=='.';
                contDomi++;
            }
            if(contDomi==2){
                domPieza++;
                contDomi=0;
            }
        }
    }
    cout<<domPieza<<"\n";
return 0;
}
