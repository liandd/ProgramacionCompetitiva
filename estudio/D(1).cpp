#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long in;
long long inn;
long long  t;
long long pole[1123456];

void solve(){
    long long  vp = 0;
    cin >> in;
    inn = in;
    
    if(in==1){
        cout << "Yes\n";
        return;
    }
    
    long long  pom = 2;
    while(in > 1 and pom*pom <= inn){
        if(in % pom == 0){
            pole[vp++] = pom;
            in = in / pom;
        }else pom++;
    }

        if (in){
        	pole[vp++]=in;
		}

	    long long sum =  1;
	    long long summ = 0;
	    long long  i = 0;
	    
	    while(i < vp ){
        if(sum < pole[i]-1){
            cout << "No\n";
            return;
        }
        summ = pole[i]+1;
        while(pole[i+1]==pole[i]){
            i++;
            summ *= pole[i];
            summ += 1;
        }
        sum *= summ;
        if(sum >= inn){
            cout << "Yes\n";
            return;
        }
        i++;
	}
}

int main(){
    pole[1]=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
