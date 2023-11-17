#include<bits/stdc++.h>
using namespace std;
int dr[]={1,1,0,-1,-1,-1,0,1};
int dc[]={0,1,1,1,0,-1,-1,-1};
char grid[100][100];
int R,C;
int floodfill(int r, int c, char c1, char c2){
    if(r<0 || r>=R || c<0 || c>=C)return 0;
    if(grid[r][c]!=c1)return 0;
    int ans=1;
    grid[r][c]=c2;
    for(int i=0; i<8; i++){
        ans += floodfill(r+dr[i],c+dc[i],c1,c2);
    }
    return ans;
}
int main(){
    while(true){
        cin>>R>>C;
        cin.ignore();
        if(R==0 && C==0)break;
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                cin>>grid[i][j];
            }
        }
        int ans=0;
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if (grid[i][j] == '*' && floodfill(i, j, '*', '.') == 1) {
                    grid[i][j] = '.';
                    ans++;
                }
            }
        }
        /*cout<<"DESPUES: \n";
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                cout<<grid[i][j];
            }
            cout<<"\n";
        }*/
        cout<<ans<<"\n";
    }
return 0;
}
