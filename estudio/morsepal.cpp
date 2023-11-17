/*
 * Morse Code Palindromes
 * ICPC Greater NY Regional 2021
 * John BUck
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#ifdef _MSC_VER
#define	STRCPY(s, len, t)	strcpy_s(s, len, t)
#else
#define	STRCPY(s, len, t)	strcpy(s, t)
#endif

#define	MAX_INPUT_CHARS		80
/* This is the longest morse code string we'll have (5 is longest code) */
#define	MAX_INPUT_MORSE		(MAX_INPUT_CHARS * 5)

const char *szMorse[] = {
	".-",
	"-...",
	"-.-.",
	"-..",
	".",
	"..-.",
	"--.",
	"....",
	"..",
	".---",
	"-.-",
	".-..",
	"--",
	"-.",
	"---",
	".--.",
	"--.-",
	".-.",
	"...",
	"-",
	"..-",
	"...-",
	".--",
	"-..-",
	"-.--",
	"--..",
	"-----",
	".----",
	"..---",
	"...--",
	"....-",
	".....",
	"-....",
	"--...",
	"---..",
	"----."
};

const char *ctom(char c)
{
	if(isupper(c)){
		return(szMorse[c - 'A']);
	}
	if(islower(c)){
		return(szMorse[c - 'a']);
	}
	if(isdigit(c)){
		return(szMorse[26 + (c - '0')]);
	}
	return("");
}

char szMorseIn[MAX_INPUT_MORSE+1];

int main()
{
	size_t idx = 0, nLen;
	const char *szMChar, *p1, *p2;
	int c;

	while((c = getc(stdin)) != EOF && c != '\n'){
		szMChar = ctom((char)c);
		nLen = strlen(szMChar);
		if(nLen > 0){
			STRCPY(&(szMorseIn[idx]), sizeof(szMorseIn) - idx, szMChar);
			idx += nLen;
		}
	}
	for(p1 = &(szMorseIn[0]), p2 = &(szMorseIn[idx - 1]); p2 >= p1; p2--, p1++){
		if(*p1 != *p2){
			break;
		}
	}
	printf("%s\n", szMorseIn[0] == '\0' || (p2 >= p1) ? "NO" : "YES");
	return(0);
}
