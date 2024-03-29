#include <bits/stdc++.h>
using namespace std;
int main(){
    string str;
    bool isCorrect;
    while (cin >> str){
        vector<char>s;
        isCorrect=true;
        for (int i=0; i<str.size(); ++i){
            if (str[i]=='('){
            	s.push_back(str[i]);
			}
            if (str[i]==')'){
                if (s.empty()){
                    isCorrect=false;
                    break;
                }
                if (s.back()=='('){
                	s.pop_back();
				}
            }
        }
        if (isCorrect==false){
        	cout << "incorrect" << endl;
		}else{
            if (s.empty()){
            	cout << "correct" << endl;
			}else{
				cout << "incorrect" << endl;
			}
        }
    }
    return 0;
}
