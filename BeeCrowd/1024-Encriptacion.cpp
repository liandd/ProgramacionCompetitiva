#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n=0;
    cin>>n;
    cin.ignore();  
    while (n--){
        int i=0;
        string str="",str1="";
        getline(cin, str);
        for (; i<str.size(); i++) {
            if ((str[i]>=65 && str[i]<=90) || (str[i]>=97 && str[i]<=122)) {
                str[i]+=3;
            }
        }
        for (int j=str.size()-1; j>=0; j--) {
            str1+=str[j];
        }
        for (int k=str.size()/2; k<str.size(); k++) {
            str1[k]-=1;
        }
        cout<<str1<<"\n";
    
/*
    int n=0,i=0;
    string str="",str1="";
    cin>>n;
    while(n--){
        cin.ignore();
        getline(cin,str);
        //reverse(str.begin(), str.end());
        for(;i<str.size();i++){
            if((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z')){
                str[i]=str[i]+3;
            }
        }
        //reverse(str.begin(), str.end());
        int tmp=0;
        for(int j=str.size()-1;j>=0;j--){
            str1[tmp]=str[j];
            tmp++;
        }
        str1[tmp]='\0';
        for(int k=(str.size()/2);k<str.size();k++){
            str1[k]=str1[k]-1;
        }
        cout<<str1<<"\n";
        */
        /*
        //reverse(str.begin(), str.end()); 
        for(int i=0;i<str.size();i++){
            if(str[i]==32){
                continue;
            }
            else{
                ascii=str[i];
                ascii+=3;
                str[i]=static_cast<char>(ascii);
                //str2+=str[i];
            }
        }
        //cout<<str<<"\n";
        reverse(str.begin(), str.end());
        for(int i=0;i<str.size();i++){
            if(!(str[i]==97 || str[i]==122))continue; 
            ascii=0,ascii=str[i];
            ascii-=1;
            str[i]=static_cast<char>(ascii);
        }
            
        reverse(str.end(), str.begin());
        for(int i=0;i<ceil(str.size()/2);i++){
            if((int)str[i]==32){
                ascii=0,ascii=str[i+1];
                ascii+=1;
                str[i+1]=static_cast<char>(ascii);
                break;
            } 
            ascii=0,ascii=str[i];
            ascii-=2;
            str[i]=static_cast<char>(ascii);
        }
        */
        //cout<<str2<<"\n";
        
    }
    return 0;
}