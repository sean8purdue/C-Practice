#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void memdump(char * p , int len) {
	// Add your code here.
	int i;
	int j;
	for (i=0; i < len; i++) {
		printf("0x%08x: ", (unsigned int)p);

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

int main(void)
{
    /*char  word[20];*/
    char  wod[3];
    char  word[5];
    wod[0] = 'a';
    wod[1] = 'b';
    wod[2] = '\0';

    word[0] = '2';
    word[1] = '3';
    word[2] = '3';
    word[3] = '3';
    word[4] = '3';

    memdump((char *)word, 64);

    printf("%s\n", wod);
    /*if (scanf("%20s", word) == 1)*/
    if (scanf("%s", word) == 1) {
	    memdump((char *)word, 64);
	    puts(word);
	    puts(wod);
    }
    return 0;
}
