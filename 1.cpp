#include <bits/stdc++.h>
using namespace std;

int main(){
	int t,s1,s2,s3,c=0;
	cin>>t;
	while(t--){
		cin>>s1>>s2>>s3;
		vector<int> vi;
		vi.push_back(s1);
		vi.push_back(s2);
		vi.push_back(s3);
		int n=vi.size();
		int numero[n];
		sort(vi.begin(),vi.end());
		copy(vi.begin(),vi.end(),numero);
		c++;
		cout<<"Case "<<c<<": "<<numero[1]<<"\n";
	}
	
	return 0;
}
