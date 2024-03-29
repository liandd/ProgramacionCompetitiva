#include<bits/stdc++.h>
using namespace std;
//Wrong answer ascii38
int main(){
	int n=0,m=0,p=0;
	int sumatodos;
	double res;
	cin>>n>>m>>p;
	vector<int>paquetes(n);
	for(int i=0;i<n;i++){
		cin>>paquetes[i];
		sumatodos+=paquetes[i];//30+20+25=75
	}
	sort(paquetes.rbegin(),paquetes.rend());
	int t=0;

	//cout<<"PAQUETES: "; Nota para el profesor: No supimos aplicar la condicion si la cantidad de paquetes en paralelo era igual o menor que la cantidad de paquetes disponibles
	if(p==n-1){
		for(int i=0;i<p;i++){
			//cout<<i<<"-> "<<paquetes[i]<<"\n";
			t+=paquetes[i];
			//cout<<t<<"\n";
		}
	}else{
		for(int i=0;i<=p;i++){
			//cout<<i<<"-> "<<paquetes[i]<<"\n";
			t+=paquetes[i];
			//cout<<t<<"\n";
		}
	}

	//cout<<"\nSUMt: "<<t<<"\n";
	//cout<<"SUMATODOS: "<<sumatodos<<"\n";
	res=static_cast<double>(t)/static_cast<double>(sumatodos);
	res*=100;
	if((res) - static_cast<int>(res) == 0){
	cout<<fixed<<setprecision(0)<<res<<"\n";
	}else{
		cout<<fixed<<setprecision(9)<<res<<"\n";
	}

	return 0;
}
