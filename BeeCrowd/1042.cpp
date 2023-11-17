#include <bits/stdc++.h>
using namespace std;

int main(){
  int a;
  set<int> s;
  vector<int> vi(3,0);
  for(int i=0; i<3; i++){
    cin>>a;
    vi[i]=a;
  }
  s.insert(vi[0]);
  s.insert(vi[1]);
  s.insert(vi[2]);
  for(auto k=s.begin(); k != s.end(); k++){ 
    cout<<*k<<"\n";                         
  }                                         
  cout<<"\n";                               
  for(auto x: vi){
    cout<<x<<"\n";                          
  }
  return 0;
}