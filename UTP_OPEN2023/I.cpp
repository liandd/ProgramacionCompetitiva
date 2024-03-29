#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n=0,d=0;
	cin>>n>>d;
	bool z=1;
	while(z){
	    n++;
	    string n_str=to_string(n);
	    int t=n_str.size()-1;
	    int a= n_str[t]-'0';
	        if(a==d){
	        cout<<n<<"\n";
	        z=0;
	        break;
	    }
	}
	
	return 0;
}