/*
 * Sequinary - GNY Regional 2021 - Fred PIckel
 */
#include <stdio.h>

int main()
{
	unsigned __int64 whole, num, denom;
	unsigned long w;
	int cur;
	char c;
	c = getchar();
	cur = c - '0';
	if((cur < 1) || (cur > 2)) {
		fprintf(stderr, "first char %c (0x%02x) is not 1 or 2\n", c, c);
		return -1;
	}
	num = cur;
	denom = 1;
	while((c = getchar()) != '\0') {
		cur = c - '0';
		if((cur < 0) || (cur > 2)) {
			break;
		}
		denom *= 2;
		num = 3*num + denom*cur;
	}
	while(((num & 1) == 0) && (denom > 1)) {
		num >>= 1; denom >>= 1;
	}
	if(num >= denom) {
		whole = num/denom;
		num -= whole*denom;
		w = (unsigned long)whole;
		if(num == 0) {
			printf("%llu\n", whole);
		} else {
			printf("%llu ", whole);
			printf("%llu/", num);
			printf("%llu", denom);
		}
	} else {	// cannot happen?
		printf("%llu /%llu\n", num, denom);
	}
	return 0;
}	
