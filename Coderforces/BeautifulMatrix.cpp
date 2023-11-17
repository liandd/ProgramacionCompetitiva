#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>>tabla(5,vector<int>(5, 0));
    int movs=0;
    for(int i=0;i<5;i++) {
        for (int j=0;j<5;j++) {
            cin>>tabla[i][j];
        }
    }
    //tabla[2][2]=centro
    int a=0,b=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(tabla[i][j]==1){
               a=i,b=j;//a=1,j=4
            }
        }
    }
    movs=abs(a-2)+abs(b-2);
    cout<<movs<<"\n";

return 0;
}
