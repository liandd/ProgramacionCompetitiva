#include<bits/stdc++.h>
using namespace std;
int dr[] = {-1, 1, 0, 0}; //arriba y abajo (fila)
int dc[] = {0, 0, -1, 1}; //izquierda y derecha (columna)
char grid[100][100];
int R,C;
int floodfill(int r, int c, char c1, char c2){
    if(r<0 || r>=R || c<0 || c>=C)return 0;
    if(grid[r][c] != c1)return 0;
    int ans=1;
    grid[r][c]=c2;
    for(int i=0; i<4;i++){
        ans += floodfill(r+dr[i],c+dc[i],c1,c2);
    }
    return ans;
}
int main(){
    while(true){
        cin>>R>>C;
        cin.ignore();//Arregla el bug que no lee la ultima columna
        if(R==0 && C==0)break;
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                cin>>grid[i][j];
            }
            getchar();
        }
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if(grid[i][j]=='T'){
                    grid[i][j]='A';
                    floodfill(i,j,'A','T');
                }
            }
        }
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                cout<<grid[i][j];
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
return 0;
}