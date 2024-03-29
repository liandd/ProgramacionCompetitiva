#include<bits/stdc++.h>
using namespace std;
//Wrong answer ascii38
int main(){
	long long n=0,c=0;
	cin>>n;
	while(n){
		c ++;
		if(n%2==0){
			n/=2;
		}else{
			n-=1;
		}
	}
	cout<<c<<"\n";
	return 0;
}
