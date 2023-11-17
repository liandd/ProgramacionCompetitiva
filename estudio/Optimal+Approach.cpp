//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>

#define pb push_back
#define ll long long int

using namespace std;

/*-------------------------------------------
--------------Rohith's Solution--------------
---------------------------------------------*/

#define maxX(a,b) (a>b?a:b)
#define minX(a,b) (a<b?a:b)
#define isEven(a) ((a%2==0)?1:0)
#define isOdd(a) ((a%2==0)?0:1)
#define isNeg(a) ((a<0)?1:0)
#define	loop(n) for(int i = 0; i < n; i++)
#define	loop2(n) for(int j = 0; j < n; j++)
#define abs(a) ((a<0)?-a:a)

int gcd(int a, int b){
	if(a == 0){
		return b;
	}else{
		return gcd(b % a, a);
	}
}

int commonDivisors(int a, int b)
{
	/* Idea: Find GCD of the numbers and then find the factors of the GCD */
    int n = gcd(a, b); 
    int result = 0;

    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
        	// 4 / 2 = 2, factor would be 2, but not 2, 2
            if (n / i == i)
                result += 1;
            else
            	// 6 / 3 = 2 we have to add both 3 and 2, hence res = res+2
                result += 2;
        }
    }
    return result;
}

void Sol(){
	ll m, n;
	cin >> m >> n;
	ll count = 0;
	count = commonDivisors(m, n);
	cout << count << endl;
}

void RepSolution(){
	int t;
	cin >> t;
	while(t!=0){
		Sol();
		t--;
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	RepSolution();
	//Sol();
	return 0;
}