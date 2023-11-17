#include <bits/stdc++.h>

using namespace std;

int main(){
    vector <int> letras(26, 0);
    bool control=true;
    string cadena, answer="", correct="GGGGG";
    cin>>cadena;
    for(int i=0; i<5; i++){
        letras[cadena[i]-65]++;
    }
    string aux;
    int j=7;
    while(j--){
            cin>>aux;
        if(control){
            answer="";
            for(int i=0; i<5; i++){
                if(letras[aux[i]-65]==0){
                    answer+="X";
                }else if(aux[i]==cadena[i]){
                    answer+="G";
                }else{
                    answer+="Y";
                }
            }
            if(answer==correct) {
                    cout<<"WINNER\n";
                    control=false;
            }
            else if(j!=0) cout<<answer<<"\n";
            else cout<<"LOSER\n";

        }
    }
return 0;
}
