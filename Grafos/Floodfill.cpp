#include <bits/stdc++.h>

using namespace std;

int dr[]={1,1,0,-1,-1,-1,0,1};//Controla la coordenada del inundamiento en las filas
int dc[]={0,1,1,1,0,-1,-1,-1};//Controla la coordenada del inundamiento en la columnas
char grid[100][100];//Matriz cuadrada, siempre dejar espacio de más, por ejemplo, si son 105 de tamañi, pongale 110
int R,C; //R=filas (rows), C=columnas (columns), controlar los limites de la matriz real

int floodfill(int r, int c, char c1, char c2){//r= es la fila en donde se encuentra el puntero en la matriz, c=la columna donde se encuentra
//c1=char que se va a contar, buscar y reemplazar, c2=es el caracter por el que se va a reemplazar
    if(r<0 || r>=R || c<0 || c>=C) return 0;
    if(grid[r][c]!=c1) return 0;
    int ans=1;
    grid[r][c]=c2;//esta linea no se toca, porque queda infinito
    for(int d=0; d<8; d++)//control de la inundación mediante de los vectores
        ans+=floodfill(r+dr[d], c+dc[d], c1, c2); //inundación recursiva mediante dfs
    return ans;

}

int main(){
    R=6;
    C=4;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin.get(grid[i][j]);
        }
        getchar();
    }
    cout<<"ANTES: \n";
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cout<<grid[i][j];
        }
        cout<<"\n";
    }
    int aux=floodfill(0, 0, '*', '|');
    cout<<"DESPUÉS: \n";
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cout<<grid[i][j];
        }
        cout<<"\n";
    }
    cout<<aux<<"\n";

return 0;
}
