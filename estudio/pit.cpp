#include <bits/stdc++.h>
using namespace std;
#define MAX 300001

struct X
{
    long long s;
    long long ub;
    long long c;
    long long m;

} pole[MAX];

long long pre[MAX];
long long n, qe;
long long pom;

long long out[MAX];

int main()
{
    cin >> n >> qe;
    while(n>=MAX or qe>=MAX)
    {
        return 0;
    }
    for(long long i=1; i<n; i++)
    {
        cin >> pom;
        pole[pom].s++;
        pre[i]=pom;
    }

    pole[0].c=1;
    pole[0].m=0;

    for(long long i=0; i<n; i++)
    {
        long long kde = i;
        if(i>0)
        {
            pole[kde].c = min(pole[pre[kde]].s*pole[pre[kde]].c, 2*qe);
            pole[kde].m = pole[pre[kde]].ub*pole[pre[kde]].c+pole[pre[kde]].m;
            pole[pre[kde]].ub++;
        }

        if(pole[kde].s==0)
        {
            while(pole[kde].m<qe)
            {
                out[pole[kde].m]=kde;
                pole[kde].m += pole[kde].c;
                if(pole[kde].c < 1 or pole[kde].c > qe) break;
            }
        }
    }

    for(long long i=0; i<qe; i++)
    cout << out[i] << '\n';
    cout << endl;
    
    return 0;
}