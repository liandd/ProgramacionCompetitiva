#include <bits/stdc++.h>
using namespace std;
/*la suma de una secuencia de números enteros consecutivos, la suma de los primeros k numeros consecuitovos es k = (k * (k + 1)) / 2
 1 + 2 (1 + 2 = 3) = 3 ES UN TNUMBER
encontrar un valor de k para que la suma sea igual que un numero 'n', n == a la suma de los primeros k numeros, por tanto si es
true n es tnumber, sino incrementar k
*/
const int N = 1e9;                     // input a y b van hasta 10 a la 8 (10^8)
vector<int>tnumbers = {3,20,119,696,4059,23660,137903,803760,4684659,27304196};// guardar los tnumbers
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*long long raiz=1;                // raiz cuadrada y luego aumenta de a 2 para los impares
        int  tnumber=1;                // Inicializa el contador de TNumber a 1
        do{
            long long dos=2;           // Factor constante para calcular seraTnumber
            long long  seraTnumber=dos*tnumber*(tnumber+1)+ 1; // Calcula el número
            while(raiz*raiz<seraTnumber){// Bucle para encontrar la raíz cuadrada de seraTnumber
                raiz+=2;               // Incrementa raiz en 2 (probando números impares)
            }
                                       // Comprueba si raiz cuadrada de seraTnumber es igual a raiz
            if(raiz*raiz==seraTnumber){// es cuadrado perfecto? significa que la suma se puede dar con numeros consecutivos
                cout<<tnumber<<'\n';   // Muestra el número TNumber encontrado
                tnumbers.push_back(tnumber);// Agrega el TNumber al vector tnumbers
            }
            tnumber++;                 // Incrementa el contador de TNumber para buscar el siguiente número
        }while(tnumber<=N);            //Continúa hasta que tnumber alcance el (10^8)*/
    int a,b;
    while(cin>>a>>b && a && b){
        int cont=0;
        for(int e: tnumbers)
            if(a<=e && e<=b)
                ++cont;
        cout<<cont<<"\n";
    }
    return 0;
}
