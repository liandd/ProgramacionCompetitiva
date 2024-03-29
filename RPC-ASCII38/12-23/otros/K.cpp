#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<n;i++)
#define pb push_back
typedef vector<double>		vd;

struct p{
    int x,y;
};

double de(p P, p Q){
    return sqrt(((P.x - Q.x)*(P.x - Q.x))+((P.y - Q.y)*(P.y - Q.y)));
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
  int k;
  cin>>k;
  vector<p> vp(k);
  fo(i,k) cin>>vp[i].x>>vp[i].y;

  double mde=1e9;
  for(int i=0;i<k;i++){
      double distancia=0.0;
      for(int j=0;j<k;j++){
          if(i!=j)
              distancia+=de(vp[i],vp[j]);
      } 
      double prom=distancia/(k-1);
      mde=min(mde,prom);
  }
  cout<<fixed<<setprecision(9)<<mde<<"\n";
  return 0;
}
