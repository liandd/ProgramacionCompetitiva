#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    long long n, myPos, liftPos, myTime, liftTime;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> myPos >> liftPos >> myTime >> liftTime;
        if(myTime <= liftTime){
            cout << myPos*myTime << endl;
        }
        else if(myPos <= liftPos){
            if(myPos*myTime < liftPos*liftTime)
                cout << myPos*myTime << endl;
            else
                cout << liftPos*liftTime << endl;
        }
        else if(2*liftTime < myTime){
            cout << liftTime*(myPos - liftPos + myPos) << endl; 
        }
        else{
            cout << myTime*(myPos - liftPos) + liftTime*liftPos << endl;
        }
    }

    return 0;
}