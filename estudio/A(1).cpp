#include<bits/stdc++.h>
using namespace std;

int main(){

int t,n,b,d;
    cin>>t;
    while(t--){
	bool com=false;
	int sum=0,temp=0,cont=0;
    int a1[100];
    int a2[100];
        cin>>n;
    for(int i=0;i<n;i++){
			cin>>b>>d;		
				a1[i]=b;
            	a2[i]=d;	
        }
    int *maxi=max_element(a2,a2+n);

		for(int i=0;i<n;i++){
			if(a2[i]==1){
				com=true;
			}
			for(int j=i+1;j<n;j++){
				
				if(a2[i]==a2[j]){
        			a1[j]=0;
				}
			}
		}
		
		for(int i=1;i<=*maxi;i++){
    		for(int j=0;j<*maxi;j++){
    			if(a2[j]==i){
    				cont++;
				}
			}
		}	
				
		 for(int i=0;i<n;i++){
			sum+=a1[i];	
        }
       
        if(cont<*maxi){
            cout<<"MOREPROBLEMS\n";
        }else{
            cout<<sum<<"\n";
        }
    }
return 0;

}
