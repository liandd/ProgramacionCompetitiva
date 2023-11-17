    #include<bits/stdc++.h>
    using namespace std;

    int main(){
        int t=0;
        cin>>t;
        while(t--) {
            string str="",str2="";
            int a=0, b=0;
            cin>>a>>b;
            cin>>str;
            cin>>str2;
            int cont=0;
            int i=0;
            while(i<=6){
                if(str.find(str2)!=string::npos) {
                    cont++;
                    cout<<i<<"\n";
                    break;
                }
                str+=str;
                i++;
            }
            if(!cont){
                cout<<"-1\n";
            }
        }
            /*
            for(int i=0;i<5;i++){
                string tmp="";
                str+=str,cont++;
                tmp=tmp+str;
                str=str+tmp,cont++;
            }
            cout<<cont<<"\n";
            */
    return 0;
    }
