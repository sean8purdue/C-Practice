#include <stdlib.h>
#include <stdio.h>

int main () {
	char *mess = NULL;
	int *mint = NULL;
	mess = (char*) malloc(100);
	printf("mess is \t%p\n", mess);
	printf("&mess is \t%p\n", &mess);
	
    free(&mess);

	/*printf("*mess is \t%c\n", *mess);*/
}
