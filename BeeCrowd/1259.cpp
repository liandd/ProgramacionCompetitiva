#include<bits/stdc++.h>              
using namespace std;                 
                                     
int main(){                          
  int n=0;                           
  vector<int> par;                   
  vector<int> impar;                 
  cin >> n;                          
  for(int i=0; i<n; i++){            
    int tmp=0;                       
    cin>>tmp;                        
    if(tmp % 2==0){                  
      par.push_back(tmp);            
    }                                
    else if(tmp % 2==1){             
      impar.push_back(tmp);          
    }                                
  }                                  
  sort(par.begin(), par.end());      
  sort(impar.rbegin(), impar.rend());
  for(auto x: par){                  
    cout << x << "\n";               
  }                                  
  for(auto y: impar){                
    cout << y << "\n";               
  }                                  
  return 0;                          
}                  