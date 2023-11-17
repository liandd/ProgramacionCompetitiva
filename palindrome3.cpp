#include<bits/stdc++.h>
const char* reversa="A   3  HIL JM O   2TUVWXY51SE Z  8";
const char* output[]={"is not a palindrome.","is a regular palindrome.",
					"is a mirrored string.","is a mirrored palindrome."};
					
char r(char ch){
	if (isalpha(ch))
		return reversa[ch-'A'];
	else 
		return reversa[ch-'0'+25];
}
int main(){
	char s[30];
	while (scanf("%s",s)!=EOF) {
		int p=1,m=1;
		int tam=strlen(s);
		for (int i=0;i<(tam+1)/2;i++){  //NOTAPALINDROME
			if (s[i]!=s[tam-1-i]) {
				p=0;
			}
			if (r(s[i])!=s[tam-1-i])
				m=0;
		}
		printf("%s -- %s\n\n",s,output[p+2*m]);
	}
	return 0;
}
