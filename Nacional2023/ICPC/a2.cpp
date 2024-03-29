#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(cin>>n){
        if(!n) return 0;
        int sum=0;
        for(int i=1; i<n; i++){
            sum+=i;
        }
        sum*=2;
        sum++;
        cout<<sum<<endl;
    }

return 0;
}
