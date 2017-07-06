#include "memdump.h"

void memdump(char * p , int len) {
	// Add your code here.
	int i;
	int j;
	for (i=0; i < len; i++) {
		printf("0x%08x: ",(unsigned char)p);

		int n = len - i;
		if ( n > 16 ) n = 16;
		for (j = 0; j < n; j++) {
			printf("%02x ", *(unsigned char *) (p+j) );
		}
		for (;j<16;j++) {
			printf("   ");
		}
		for (j = 0; j < n; j++) {
			printf("%c", ((*p)>=32 && (*p) <= 127)?*p:'.');
			p ++;
			i ++;
		}
		printf("\n");
	}
}
