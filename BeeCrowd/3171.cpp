#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef map<int, int> mii;
int main(){
  mii leds;
  int n=0, l=0;
  cin >> n >> l;
  for(int i=1; i<n; i++){
    leds[i]=i;
  }
  for(int i=0; i<l; i++) {
        int x=0, y=0;
        cin >> x >> y;
        int px = leds[x];
        int py = leds[y];
        for (auto& p : leds) {
            if (p.S == py) {
                p.S = px;
            }
        }
  }
  bool completo = true;
  for (int i=2; i<=n; i++) {
    if (leds[i] != leds[1]) {
      completo = false;
      break;
    }
  }
  if (completo) {
    cout << "COMPLETO\n";
  }
  else {
    cout << "INCOMPLETO\n";
  }
  return 0;
}
