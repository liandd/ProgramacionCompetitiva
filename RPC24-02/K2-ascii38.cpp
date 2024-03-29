#include<bits/stdc++.h>
using namespace std;
//Wrong answer ascii38
long long c=0;
bool cmp(char a,char b){

	if(a>b){
		return false;
	}else if(a<b){
		c++;
		return true;
	}
	return false;
}
int main(){
	string n,cn;
	cin>>n;
	cn=n;
	sort(cn.begin(),cn.end(),cmp);
	cout<<c<<"\n";
	return 0;
}
