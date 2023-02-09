#include <bits/stdc++.h>

using namespace std;

int main(){

string palabra2="";
string palabra="";
vector <string> todas;
cin>>palabra;
for(int i=0; i<7; i++){
    string x="";
    cin>>x;
    for(int y=0; y<palabra.size(); y++){
        if(x==palabra){
            palabra2=palabra;
        }
        if(x[y]==palabra[y] && x!=palabra){
            palabra2+='G';
        }
        if((x[y]==palabra[0] || x[y]==palabra[1] || x[y]==palabra[2] || x[y]==palabra[3] || x[y]==palabra[4]) && x[y]!=palabra[y]){
            palabra2+='Y';
        }
        if((x[y]!=palabra[0] && x[y]!=palabra[1] && x[y]!=palabra[2] && x[y]!=palabra[3] && x[y]!=palabra[4]) && x[y]!=palabra[y]){
            palabra2+='X';
        }
    }
    todas.push_back(palabra2);
    palabra2.clear();
}
for(int i=0; i<7; i++){
    if(todas[i]==palabra){
        cout<<"WINNER"<<"\n";
        break;
    }

    if(todas[i]!=palabra){
      if(i==(todas.size()-1)){
        cout<<"LOSER\n";
     }
     else{
        cout<<todas[i]<<"\n";
     }
    }
}

return 0;
}
