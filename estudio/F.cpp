#include <bits/stdc++.h>
using namespace std;

int main (){

  string word;

  getline (cin, word);

  string codigo[] = { "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.",
    "", "", "", "", "", "", "",
    ".-", "-...", "-.-.",			//ABC
    "-..", ".", "..-.",			//DEF
    "--.", "....", "..",			//GHI
    "·---", "-.-", ".-..",			//JKL
    "--", "-.", "---",
    ".--.", "--.-", ".-.",
   "...", "-", "..-",
    "...-", ".--", "-..-",
    "-.--", "--.."
  };

  string p1 ="", p2 ="";
  
  for (int i = 0; i < word.length (); i++){
      int valor = word[i] - (word[i] < 91 ? 48 : 80);
      if(valor < 0 || valor > 42) {
          cout<<"NO \n"; 
          return 0;
      }
      p1 += codigo[valor];
  }

  p2  = p1;
  reverse(p2.begin(),p2.end());
  cout<<((p1 == p2) ? "YES" : "NO")<<"\n";

  return 0;
}
