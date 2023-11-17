#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=0;
    char num[102];
    cin>>t;
    while(t--){
        int led=0;
        cin>>num;
        int l=strlen(num);
        for(int i=0;i<l;i++){
            if(num[i]=='1')led+=2;
            else if(num[i]=='2' || num[i]=='3' || num[i]=='5')led+=5;
            else if(num[i]=='6' || num[i]=='9' || num[i]=='0')led+=6;
            else if(num[i]=='7')led+=3;
            else if(num[i]=='4')led+=4;
            else if(num[i]=='8')led+=7;
        }
        cout<<led<<" leds\n";
}
    return 0;
}