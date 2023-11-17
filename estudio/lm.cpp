#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<n;i++)
#define pb push_back
typedef vector<int> vi;

int main(){

	ios::sync_with_stdio(0);cin.tie(0);
	int n,k;
	cin>>n>>k;
	vi a(n);
	vi b(k);
	vi c(k);
	vector<uint8_t> g(n);
	fo(i,n)cin>>a[i];
	fo(i,k)cin>>b[i];
	int grosor=0;
	fo(i,n){
		if(a[i]<=0){
			grosor+=(uint8_t)a[i]>>3;
		}else{
			grosor-=(uint8_t)a[i]>>3;
		}
		if(grosor<0) grosor=0;
		g[i]=(uint8_t)grosor;
	}
	fo(i,k)
		fo(j,n)
			if(g[j]>=b[i]) c[i]++;

	fo(i,k)	cout<<c[i]<<" ";

	cout<<"\n";
	return 0;
}
