#include<iostream>
using namespace std;

int main()
{

    int c, n;

    cin >> c >> n;
    int minutes[n+1];
    for(int i=1; i<=n; i++)
        cin >> minutes[i];

    bool matriz[2][c+1][c+1];
    for(int j=0; j<=c; j++)
    {
        for(int k=0; k<=c; k++)
        {
            matriz[0][j][k] = false;
        }
    }
    matriz[0][c][c] = true;

    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=c; j++)
        {
            for(int k=0; k<=c; k++)
            {
                matriz[1][j][k] = matriz[0][j][k];
                if (j + minutes[i] > 0 && j + minutes[i] <= c && matriz[0][j+minutes[i]][k]) // j+minutes[i]>0 checks for overflow
                    matriz[1][j][k] = true;
                if (k + minutes[i] > 0 && k + minutes[i] <= c && matriz[0][j][k+minutes[i]])
                    matriz[1][j][k] = true;;
            }
        }
        for(int j=0; j<=c; j++)
        {
            for(int k=0; k<=c; k++)
            {
                matriz[0][j][k] = matriz[1][j][k];
            }
        }
    }

/*
    cout << "CD 0"<<endl;

    for(int j=0; j<=c; j++)
    {
        for(int k=0; k<=c; k++)
        {
            cout<<matriz[0][j][k]<<"-";
        }
        cout<<endl;
    }

    cout << "CD 1"<<endl;

    for(int j=0; j<=c; j++)
    {
        for(int k=0; k<=c; k++)
        {
            cout<<matriz[1][j][k]<<"-";
        }
        cout<<endl;
    }*/
    // search diagonals of last slice of matriz for minimal empty space
    bool found = false;
    int cd1 = 0, cd2 = 0;
    for(int empty=0; empty<=2*c; empty++)  		// empty = remaining minutes not used on two CDs combined
    {
        for(int i=max(0, empty-c); i<=c; i++)
        {
            int j=empty-i;
            if (j < i)
                break;
            if (matriz[0][i][j])
            {
                found = true;
                cd1 = c-i;
                cd2 = c-j;
            }
        }
        if (found)
            break;
    }
    cout << cd1 << " " << cd2 << endl;

}
