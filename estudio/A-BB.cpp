#include <bits/stdc++.h>

using namespace std;

int main(){


int T1=0, F1=0, S1=0, P1=0, C1=0;

int T2=0, F2=0, S2=0, P2=0, C2=0;

int total1, total2;

cin>>T1>>F1>>S1>>P1>>C1;
cin>>T2>>F2>>S2>>P2>>C2;

total1=(T1*6)+(F1*3)+(S1*2)+(P1*1)+(C1*2);
total2=(T2*6)+(F2*3)+(S2*2)+(P2*1)+(C2*2);

cout<<total1<<" "<<total2<<endl;
}
