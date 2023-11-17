#include <bits/stdc++.h>
using namespace std;
int main()
{
    long arr[15]={
1,
1,
2,
6,
24,
120,
720,
5040,
40320,
362880,
3628800,
39916800,
479001600,
6227020800};
/*
    long res=1;
    cout<<1<<"\n";
for(long i=1;i<=13;i++){
    res*=i;
    cout<<res<<"\n";
}*/
int n=0;
cin>>n;
cout<<arr[n]<<"\n";
    return 0;
}