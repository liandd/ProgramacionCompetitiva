#include<bits/stdc++.h>
using namespace std;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	double n=0,k=0,d=0,s=0;
	cin>>n>>k>>d>>s;
	double a = k*s;
	double b = (n*d)-a;
	double c = b/(n-k);
	if(c>=0&&c<=100)
		cout<<fixed<<setprecision(7)<<c<<"\n";
	else
		cout<<"impossible"<<"\n";

	return 0;
}
