#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); i++)

const int maxN = 1 << 19, maxA = 1 << 20;

int last[maxA];

int main()
{
	stack <int> S;
	int n;
	scanf ("%d", &n);
	
	long long res = 0;
	S.push(maxA);
	
	FOR(i, 1, n+1)
	{
		int v;
		scanf ("%d", &v);
		while (S.top() < v)
			S.pop();
		if (S.top() == v)
		{
			S.pop();
			res += i - last[v] - 1;
		}
		S.push(v);
		last[v] = i;
	}
	
	printf("%lld\n", res);
	
	return 0;
}