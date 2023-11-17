/*
 * ICPC Greater NY Regional
 * Letterle problem 2021
 * Solution: John Buck
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define		MAX_LINE	64
#define		MAX_GUESS	7
#define		NUM_LETTER	5

char szLetterle[MAX_LINE];
char szTest[MAX_LINE];
char szGuess[MAX_LINE];
char szResult[NUM_LETTER + 1];

int main(int argc, char **argv)
{
	int i, j, c;
	char *s;

	if(::fgets(&(szLetterle[0]), sizeof(szLetterle), stdin) != NULL){
		for(i = 0; i < MAX_GUESS; i++){
			if(::fgets(&(szGuess[0]), sizeof(szGuess), stdin) == NULL){
				fprintf(stdout, "LOSER\n");
				break;
			}
			for(c = 0, j = 0; j < NUM_LETTER; j++){
				if(szLetterle[j] == szGuess[j]){
					c++;
					szResult[j] = 'G';
					szTest[j] = '.';
					/* Erase letter so we don't match later */
					szGuess[j] = '.';
				} else {
					szTest[j] = szLetterle[j];
					szResult[j] = 'X';
				}
			}
			if(c == NUM_LETTER){
				printf("WINNER\n");
				break;
			}
			if(i == MAX_GUESS - 1){
				printf("LOSER\n");
				break;
			}
			for(j = 0; j < NUM_LETTER; j++){
				if(szGuess[j] != '.' && (s = strchr(&(szTest[0]), szGuess[j])) != NULL){
					*s = '.';
					szResult[j] = 'Y';
				}
			}
			printf("%5.5s\n", &(szResult[0]));
		}
	}
	return(0);
}
