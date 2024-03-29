#include<bits/stdc++.h>
using namespace std;
//Wrong answer ascii38
long long countSort(string &s){
	vector<int> cont(3,0);
	long long r=0;
	for(char c : s){
		cont[c-'0']++;
	}
	int index=0;
	for(int i=0;i<3;i++){
		while(cont[i]--){
			s[index++] = '0' + i;
			r++;
		}
	}
	return r;
}
int main(){
	string s;
	cin>>s;
	cout<<countSort(s)<<"\n";
	return 0;
}
