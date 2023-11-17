#include <bits/stdc++.h>
using namespace std;
int main(){
        int t;
        cin>>t;
        while(t--){
        	int n,num[105];
        	cin>>n;
        	for(int i=1;i<=n;i++)
        	cin>>num[i];
        	if(n%2==0){
        		cout<<2<<"\n";
        		cout<<1<<" "<<n<<"\n";
        		cout<<1<<" "<<n<<"\n";
    		}
    		if(n%2!=0){
    			cout<<4<<"\n";
    			cout<<1<<" "<<2<<"\n";
    			cout<<1<<" "<<2<<"\n";
    			cout<<2<<" "<<n<<"\n";
    			cout<<2<<" "<<n<<"\n";
    		}
    	}
    	return 0;
    }
