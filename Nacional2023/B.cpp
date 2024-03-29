#include<bits/stdc++.h>
using namespace std;
string commonPrefix(const string &str1, const string &str2) {
    int len1 = str1.length();
    int len2 = str2.length();
    int minLength = min(len1, len2);
    string result;
    for (int i = 0; i < minLength; i++) {
        if (str1[i] == str2[i]) {
            result += str1[i];
        } else {
            break;
        }
    }
    return result;
}
string findLongestCommonPrefix(vector<string> &strs) {
    if (strs.empty()) {
        return "";
    }
    string prefix = strs[0];
    for (int i = 1; i < strs.size(); i++) {
        prefix = commonPrefix(prefix, strs[i]);
        if (prefix.empty()) {
            break;
        }
    }
    return prefix;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin>>n && n){
        vector<string> palabras;
        while(n--){
            string str;
            cin>>str;
            string palabraEnMinusculas;
            for (int i = 0; i < str.size(); i++) {
                char letra = tolower(str[i]);
                palabraEnMinusculas += letra;
            }
            palabras.push_back(palabraEnMinusculas);
        }
        string lcp = findLongestCommonPrefix(palabras);
        if (!lcp.empty()) {
            cout<<lcp<<"\n";
        } else {
            cout<<"*\n";
        }
    }

    return 0;
}
