#include <bits/stdc++.h>

using namespace std;

int main(){
    string n1, n2, n3;
    cin>>n1>>n2>>n3;
    vector<string> numeritos;
    numeritos.push_back(n1+n2+n3);
    numeritos.push_back(n1+n3+n2);
    numeritos.push_back(n2+n1+n3);
    numeritos.push_back(n2+n3+n1);
    numeritos.push_back(n3+n1+n2);
    numeritos.push_back(n3+n2+n1);
    string mayor="";
    for(int i=0; i<numeritos.size(); i++){
        if(numeritos[i]>mayor) mayor=numeritos[i];
    }
    cout<<mayor<<"\n";


return 0;
}
