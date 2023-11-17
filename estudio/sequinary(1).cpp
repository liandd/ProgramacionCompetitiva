#include <bits/stdc++.h>

using namespace std;

int main(){

string s;
cin>>s;
long long a=int(s[0]-'0'),b=1;
for(int i=1;i<s.size();i++){

a*=3;
b*=2;
long long g=__gcd(a,b);
a/=g,b/=g;
a+=b*(s[i]-'0');
}
if(b==1){
cout<<a<<"\n";
}
else{
cout<<a/b<<" "<<a%b<<'/'<<b<<"\n";
}

return 0;
}
