/*
 * ICPC GNY Regional
 * CIDR "C" solution
 * John Buck
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define	MAX_TADDR	65535
in_addr_t addrs[MAX_TADDR];

int main(int argc, char **argv)
{
	char buf[256], *s;
	in_addr_t b, a, m;
	int n = 0, i, nb;

	if(fgets(&(buf[0]), sizeof(buf), stdin) == NULL){
		return(1);
	}
	n = atoi(&(buf[0]));
	for(i = 0; i < n; i++){
		if(fgets(&(buf[0]), sizeof(buf), stdin) == NULL){
			break;
		}
		/* Ugh - get rid of trailing <nl>, etc. */
		s = &(buf[strlen(buf)]);
		while(--s >= &(buf[0])){
			if(!isspace(*s)){
				break;
			}
			*s = '\0';
		}
		addrs[i] = ntohl(inet_addr(&(buf[0])));
#ifdef DEBUG
		printf("%08x\n", addrs[n]);
#endif
	}
	for(b = 0x80000000, a = 0, nb = 0; a != 0xffffffff; b >>= 1, nb++){
		a |= b;
		m = addrs[0] & a;
#ifdef DEBUG
		printf("%08x %08x %d\n", a, m, nb);
#endif
		for(i = 1; i < n; i++){
			if((addrs[i] & a) != m){
				break;
			}
		}
		if(i < n){
			break;
		}
	}
#ifdef DEBUG
	printf("%08x %d\n", a & ~b, nb);
#else
	printf("%d\n", nb);
#endif
	return(0);
}
