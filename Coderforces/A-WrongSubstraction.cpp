    #include<bits/stdc++.h>
    using namespace std;

    int main(){
        string str="";
        int k;
        cin>>str;
        fflush(stdin);
        cin>>k;
        int i=0,cont=0,tam=str.size();
        cont=stoi(str);
        while(i<k){
            if(str[tam-1]-'0'!=0){
                cont--;
                cout<<cont<<"\n";
                str=to_string(cont);
            }
            else if((str[tam-1]-'0')==0)cont=stoi(str)/10,str=to_string(cont);
            i++;
        }
        cout<<cont<<"\n";

        return 0;
    }
