#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b, c, d;

    cin>>a>>b>>c>>d;

    int pastTotal = c+d, aux = a, contC=1;
    if(c==0 && d==0) {cout<<"We need 0 trucks and 0 boats.\n"; return 0;}

    if(pastTotal!=0){
        if(c==0){
            if(d%a!=0) cout<<"No solution.\n";
            else{
                contC=d/a;
                cout<<"We need ";

                if(contC>1){

                    cout<<contC<<" trucks and 0 boats";
                }else{

                    cout<<contC<<" truck and 0 boats";
                }
            }
        }else if(d==0){
            while(a<pastTotal && pastTotal!=0){

                a+=aux;
                contC++;
            }
            if(a%b==0){
                int boat=a/b;
                cout<<"We need ";

                if(contC>1){

                    cout<<contC<<" trucks and ";
                }else{

                    cout<<contC<<" truck and ";
                }
                if(boat>1){

                    cout<<boat<<" boats.\n";
                }else{

                    cout<<boat<<" boat.\n";
                }
            }else cout<<"No solution.\n";
        }else{
            while(a<pastTotal && pastTotal!=0){

                a+=aux;
                contC++;
            }

            a-=d;

            if(a%b==0 && (c!=0 || d!=0)){


                    int boat = a/b;

                    cout<<"We need ";

                    if(contC>1){

                        cout<<contC<<" trucks and ";
                    }else{

                        cout<<contC<<" truck and ";
                    }
                    if(boat>1){

                        cout<<boat<<" boats.\n";
                    }else{

                        cout<<boat<<" boat.\n";
                    }



            }else{

                cout<<"No solution.\n";
            }
        }

    }else cout<<"No solution.\n";

return 0;
}
