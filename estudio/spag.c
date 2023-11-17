/*
 * Spaghetti - GNY Regional 2021 - Fred Pickel
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#undef TEST
char inbuf[256];
int main()
{
	int truck_cap, boat_cap, venice_min, maestr, trucks, boats, total;
#ifdef TEST
	while(1) {
#endif
	if(fgets(&(inbuf[0]), 255, stdin) == NULL) {
		fprintf(stderr, "read failed on dimensions\n");
		return -2;
	}
	if(sscanf(&(inbuf[0]), "%d %d %d %d",
		&truck_cap, &boat_cap, &venice_min, &maestr) != 4) {
		fprintf(stderr, "scan failed on input probability\n");
		return -3;
	}
	if((truck_cap <= 0) || (truck_cap > 100)) {
		fprintf(stderr, "truck cap %d not in range 0 ... 100\n", truck_cap);
		return -4;
	}
	if((boat_cap <= 0) || (boat_cap > 20)) {
		fprintf(stderr, "boat cap %d not in range 0 ... 20\n", boat_cap);
		return -5;
	}
	if((venice_min < 0) || (venice_min > 100)) {
		fprintf(stderr, "truck cap %d not in range 0 ... 100\n", venice_min);
		return -6;
	}
	if((maestr < 0) || (maestr > 100)) {
		fprintf(stderr, "truck cap %d not in range 0 ... 100\n", maestr);
		return -7;
	}
	trucks = (venice_min + maestr + truck_cap -1)/truck_cap;
	total = truck_cap*trucks;
	if(((total - maestr) % boat_cap) != 0) {
		printf("No solution.\n");
	} else {
		boats = (total - maestr)/boat_cap;
		if(trucks == 1) {
			printf("We need 1 truck and ");
		} else {
			printf("We need %d trucks and ", trucks);
		}
		if(boats == 1) {
			printf("1 boat.\n");
		} else {
			printf("%d boats.\n", boats);
		}
	}
#ifdef TEST
	}
#endif
	return 0;
}



