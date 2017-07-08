#include <stdlib.h>
#include <stdio.h>

int main () {
	char *mess = NULL;
	char *mint = NULL;
	mess = (char*) malloc(100);
	printf("mess is \t%p\n", mess);
	printf("&mess is \t%p\n", &mess);
	mint = mess;
	free(mess);
	free(mint);
}
