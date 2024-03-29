#include<bits/stdc++.h>
using namespace std;

struct d{
	char l;
	int n;
	
	bool operator < (const d& other) const{
		return n>other.n;
	}
};

int main(){
	string dna;
	int m,s,e;
	cin>>dna>>m;
	while(m--){
	
	vector<d> vd={{'A',0},{'T',0},{'G',0},{'C',0}};	
		cin>>s>>e;
		string aux= dna.substr(s-1,(s-e)+1);
		vd[0].n=count(aux.begin(), aux.end(),'A');
		vd[1].n=count(aux.begin(), aux.end(),'T');
		vd[2].n=count(aux.begin(), aux.end(),'G');
		vd[3].n=count(aux.begin(), aux.end(),'C');

		
		sort(vd.begin(), vd.end());
		for(int j=0;j<4;j++){
			cout<<vd[j].l;
		}
		cout<<"\n";
	}	
	return 0;
}

