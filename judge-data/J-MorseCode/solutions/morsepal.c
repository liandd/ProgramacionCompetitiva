/*
 * Morsecode Palindromes - GNY Regional 2021 - Fred Pickel
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

//#define TEST
#define MAX_CHARS 80
char morse[5*MAX_CHARS + 16], morserev[5*MAX_CHARS + 16];
char *lettab[26] =
{
	".-", "-...", "-.-.", "-..", ".",	//A
	"..-.", "--.", "....", "..", ".---",	//F
	"-.-", ".-..", "--", "-.", "---",	//K
	".--.", "--.-", ".-.", "...", "-",	//P
	"..-", "...-", ".--", "-..-", "-.--",	//U
	"--..",	//Z
};

int letlen[26] = {
	2, 4, 4, 3, 1, 4, 3, 4, 2, 4,
	3, 4, 2, 2, 3, 4, 4, 3, 3, 1,
	3, 4, 3, 4, 4, 4
};

char *numtab[26] =
{
	"-----",
	".----",
	"..---",
	"...--",
	"....-",
	".....",
	"-....",
	"--...",
	"---..",
	"----.",
};

int tomorse(char *pb)
{
	int len, outlen = 0;
	char c, *cp;
	while((c = *pb++) != 0) {
		if((c >= 'A') && (c <= 'Z')) {
			cp = lettab[c - 'A'];
			len = letlen[c - 'A'];
		} else if((c >= 'a') && (c <= 'z')) {
			cp = lettab[c - 'a'];
			len = letlen[c - 'a'];
		} else if((c >= '0') && (c <= '9')) {
			cp = numtab[c - '0'];
			len = 5;
		} else {
			continue;	// ignore everything else
		}
		strncpy(&(morse[outlen]), cp, len);
		outlen += len;
	}
	morse[outlen] = 0;
	return outlen;
}

int morse_rev(int len)
{
	int i;
	char *pci, *pco;
	pci = &(morse[len-1]);
	pco = &(morserev[0]);
	for(i = 0; i < len ; i++) {
		*pco++ = *pci--;
	}
	morserev[len] = 0;
	return 0;
}

char inbuf[MAX_CHARS + 32];
int main()
{
	int len, res;
#ifdef TEST
	while(1) {
#endif
	if(fgets(&(inbuf[0]), MAX_CHARS + 30, stdin) == NULL) {
		fprintf(stderr, "read failed on input data\n");
		return -2;
	}
	inbuf[MAX_CHARS + 30] = 0;
	len = tomorse(&(inbuf[0]));
	morse_rev(len);
	res = strncmp(&(morse[0]), &(morserev[0]), len);
	if(res == 0 && morse[0] != '\0') {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
#ifdef TEST
	}
#endif
	return 0;
}

