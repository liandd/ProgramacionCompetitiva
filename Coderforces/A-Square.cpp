    #include<bits/stdc++.h>
    using namespace std;
    #define fo(i,n) for(int i=0;i<n;i++)
    typedef vector<int>		vi;

    struct point{
    	int x,y;
    };
    int main(){
    	ios::sync_with_stdio(0);cin.tie(0);
    	int t;
    	cin>>t;
    	while(t--){
    		vector<point> p(4);
    		fo(i,4)
    			cin>>p[i].x>>p[i].y;

    		int r=0;
    		fo(i,4){
    			if(r!=0) break;
    			r=abs(p[i+1].x - p[i].x);
    		}
    		cout<<r*r<<"\n";
    	}

    	return 0;
    }
