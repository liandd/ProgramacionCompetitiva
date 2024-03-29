#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include<cstdlib>
using namespace std;

void leer(){
string cadena,line,palabra;
vector<string> vector_cadenas;
ifstream cad_archivo("prueba.txt");
if(!cad_archivo){
    cout<<"NO SE ENCONTRO\n";
}
else{
    cout<<"SE ENCONTRO\n";
    while(!cad_archivo.eof()){
        getline(cad_archivo,line);
        cadena+=line+"\n";
    }
    stringstream cad_stream(cadena);
    while(getline(cad_stream,palabra,';')){
        vector_cadenas.push_back(palabra);
    }
    for(int i=0;i<vector_cadenas.size();i++){
        cout<<vector_cadenas[i]<<"\n";
    }

}
cad_archivo.close();
}
void guardar(){
ofstream f("prueba.txt",ofstream::out);
f << 3; f << ";";
f << 4; f << ";";
f << "hola"; f << ";";
f << "mundo"; f << ";";
f.close();
}
int main(){
guardar();
leer();
return 0;
}
