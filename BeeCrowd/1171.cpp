#include<bits/stdc++.h>                 
                                        
using namespace std;                    
                                        
int main() {                            
    int n;                              
    cin >> n;                           
    vector<int> vi(n);                  
    for (int i=0; i<n; i++) {           
        cin >> vi[i];                   
    }                                   
    set<int> s(vi.begin(), vi.end());   
    for (auto x : s) {                  
        int cont=0;                     
        for (int i=0; i<n; i++) {       
            if (vi[i] == x) {           
                cont++;                 
            }                           
        }                               
        cout << x << " aparece " << cont << " vez(es)\n";                       
    }                                   
                                        
    return 0;                           
}            