#include<bits/stdc++.h>
#ifndef _MSVC_VER
#define	scanf_s	scanf
#endif
#define maxt 200
#define maxb 100
using namespace std;

int main(){
	int a,b,c,d,bca,cap;
	int i,j;
	
	while(scanf_s("%d %d %d %d", &(a), &(b), &(c), &(d)) == 4){
	
		for(i=0;i<=maxt;i++){
			cap=i*a;
			for(j=0;j<=maxb;j++){
				bca=j*b;
				if (cap - bca == d && bca >= c) {
					printf("We need %d truck%s and %d boat%s.\n",
						i, (i == 1) ? "" : "s", j, (j == 1) ? "" : "s");
					break;
					exit(0);
				}
			}
			if(j<=maxb){
				break;
				exit(0);
			}
		}
		
		if(i>maxt){
			cout<<"No solutions.\n";
			exit(0);
		}
		exit(0);
	}
	return 0;
	
}
