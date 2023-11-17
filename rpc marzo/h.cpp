#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(0);
	cin.tie(0);
    long n;
    cin>>n;
    while(n--){
        long cnt, s;
        scanf("%ld %ld", &cnt, &s);
        long d = (s / cnt);
        long m = (s % cnt);
        long ans = (cnt - m) * d * d + m * (d + 1) * (d + 1);
        printf("%ld\n", ans);
    }
	return 0;
}


