#include <stdlib.h>
#include <stdio.h>

int main () {

	char *mess = NULL;
	mess = (char*) malloc(100);
	
    *mess = 33;
	free(mess);
    mess = NULL;

    *mess = 53;
    printf("*mess is \t%d\n", *mess);
}

