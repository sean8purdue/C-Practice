#include <stdlib.h>
#include <stdio.h>

int main () {

	char *mess = NULL;
	mess = (char*) malloc(100);
	
    *mess = 33;
	free(mess);
    mess = NULL;

    *mess = 53; //[1]    802 segmentation fault  ./free
    printf("*mess is \t%d\n", *mess);
}

