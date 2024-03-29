#include <bits/stdc++.h>
#define debug(x) cout<<#x<<" = "<<x<<endl;
using namespace std;

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n;
    while(scanf("%d", &n))
    {
        if(!n)
            return 0;
        int minimo =1e9;
        vector <string> cadenas(n);
        for(int i=0; i<n; i++)
        {
            cin>>cadenas[i];
            minimo = min(minimo, (int)cadenas[i].size());
        }
        if(n==1){
            for(int i=0; i<cadenas[0].size(); i++){
                cadenas[0][i]=tolower(cadenas[0][i]);
            }
            cout<<cadenas[0]<<endl;
        }
        else
        {
            char aux2;
            bool control = false;
            string cadena="";
            for(int i=0; i<minimo; i++)
            {
                control = false;
                for(int j=0; j<cadenas.size(); j++)
                {
                    if(j==0)
                        aux2=tolower(cadenas[j][i]);
                    else
                    {
                        if(aux2==tolower(cadenas[j][i]) && j==cadenas.size()-1)
                        {
                            cadena+=aux2;
                        }
                        else if(aux2!=tolower(cadenas[j][i]))
                        {
                            control = true;
                            break;
                        }
                        if(aux2==tolower(cadenas[j][i]) && i==minimo-1 && j==cadenas.size()-1)
                        {
                            control = true;
                        }
                    }
                    //debug(aux2);

                }
                //debug(control);
                if(control)
                {
                    if(cadena.size()>0)
                        cout<<cadena<<endl;
                    else
                        cout<<"*\n";
                    break;
                }
            }
        }
        //debug(minimo);

    }


    return 0;
}
