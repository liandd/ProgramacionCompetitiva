#include <bits/stdc++.h>
using namespace std;
bool idoneal(int num) {
    for(int a=1;a<num;a++){
        int b=a+1;
        while(b<num){
            int low=b+1;
            int  high=num-1;
            do{
                int c=(low+high)/2;
                int sum=a*b+a*c+b*c;
                if(sum==num){
                    cout<<a<<" "<<b<<" "<<c<<"\n";
                    return false;
                }
                else if(sum<num){
                    low=c+1;
                }
                else{
                    high=c-1;
                }
            }while(low<=high);
            b++;
        }
    }
    return true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(true){
        cin>>n;
        if(n==0){
            break;
        }
        if(idoneal(n)){
            cout<<"idoneal\n";
        }
    }
    return 0;
}

