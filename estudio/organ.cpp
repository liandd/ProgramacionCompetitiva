#include <iostream>

using namespace std;

int main()
{

    int y, fa[9]{1,2,6,24,120,720,5040,4032,362880};

    std::cin >> y;
    std::string x = "";

    while(y!=0){
        for(int i = 8; i >=0;--i){
            if(y >= fa[i]){
                x = std::to_string(i+1) + x;
                y -= fa[i];
                break;
            }
        }
    }
    std::cout << x << "\n";
    return 0;
}