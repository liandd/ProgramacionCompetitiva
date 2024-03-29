#include<bits/stdc++.h>
using namespace std;
int main(){
    string x,y,z,r;
    cin>>x>>y>>z;
    string a,b,c,d,e,f;
    a = x+y+z;
    b = x+z+y;
    c = y+x+z;
    d = y+z+x;
    e = z+x+y;
    f = z+y+x;
    vector<string>s;
    s.push_back(a);
    s.push_back(b);
    s.push_back(c);
    s.push_back(d);
    s.push_back(e);
    s.push_back(f);
    r="";
    sort(s.begin(),s.end());
    cout<<s[5]<<"\n";
    /*
    long long A,B,C,D,E,F;
    A = stoi(a);
    B = stoi(b);
    C = stoi(c);
    D = stoi(d);
    E = stoi(e);
    F = stoi(f);
    vector<long long> vl={A,B,C,D,E,F};
    string s;
    sort(vl.begin(), vl.end());
    cout<<vl[5]<<"\n";
*/
    return 0;
}
