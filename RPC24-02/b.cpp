#include<bits/stdc++.h>

using namespace std;

int main(){
	
	long double n=0;
	int cont=0;
	cin>>n;
	while(n>1){
		
		n=n/2;
		cont++;		
	}
	
	cout<<cont+1<<"\n";
	
	
	return 0;
}
