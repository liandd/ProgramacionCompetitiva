#include <bits/stdc++.h>

#define debug(x) cout<<#x<<" = "<<x<<endl;

using namespace std;

map<string, int> cadenas;

struct cmp{
    bool operator()(const string &a, const string &b) const{
        if(cadenas[a]!=cadenas[b]){
            return cadenas[a]>cadenas[b];
        }else return a.size()>b.size();
    }
};
int main(){
    int m;
    while(scanf("%d", &m), m){
        if(!m) return 0;
        string aux = "", cadena;
        while(m--){
            aux="";
            cin>>cadena;
            for(int i=0; i<cadena.size(); i++){
                aux+=tolower(cadena[i]);
                //debug(aux);
                cadenas[aux]++;
                //debug(cadenas[aux]);
            }
        }
        map <string, int, cmp> ans(cadenas.begin(), cadenas.end());
            //int i=0;
            map <string, int>::iterator i = ans.begin();
            if(i->second>1)cout<<i->first<<endl;
            else cout<<"*\n";
            cadenas.clear();

    }

return 0;
}
