#include<bits/stdc++.h>
using namespace std;

int main(){
	int n=0,m=0;
	cin>>n>>m;
	vector<string> pal(n);
	for(int i=0;i<n;i++){
		cin>>pal[i];
	}
	int tam=pal.size();
	string pais="";
	for(int i=0;i<m;i++){
		vector<int> apariciones(26,0);
		for(int j=0;j<tam;j++){
			if(pal[j].size()>i){
				apariciones[pal[j][i]-'a']++;
			}
		}
		int cont1=0;
		char letramax='a';
		for(int k=0;k<26;k++){
			if(apariciones[k]>cont1){
				cont1=apariciones[k];
				letramax='a'+k;
			}
		}
		pais+=letramax;
	}
	cout<<pais<<"\n";
	return 0;
}
