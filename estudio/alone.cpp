#include <bits/stdc++.h>
using namespace std;


using LL = long long int;

const int N = 211;

LL dp[N+7];

bool pr[N+7];

bool prime(int n){
	
	for(int i = 2; i < n; i++){
		if(n%i == 0){
			return false;
		}
	}
	return true;
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);
	
	int P;
	cin >> P;
	for(int i = 2; i <= P; i++){
		pr[i] = prime(i);
	}
	dp[2] = 1;
	for(int i = 3; i <= P; i++){
		if(pr[i] == false) continue;
		for(int j = max(2, i-14); j < i; j++){
			dp[i] += dp[j];
		}
	} 
	cout << dp[P] << '\n';
	
	
	


	return 0;
}