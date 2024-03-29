#include<bits/stdc++.h>
using namespace std;
//Wrong answer ascii38
int main(){
	string n,cn;
	int c;
	cin>>n;
	cn=n;
	sort(cn.begin(),cn.end());
	while(n!=cn){
		for(int i=n.size()-1;i>=0;i--){
			if(n[i]<n[i-1]){
				swap(n[i],n[i-1]);
				c++;
			}
		}

	}
	cout<<c<<"\n";
	return 0;
}
