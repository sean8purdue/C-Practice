/* While-Loop And Boolean Expressions

 */

#include <stdio.h>

int main(int argc, char *argv[]) 
{
	int i = argc-1;
	while(i > 0) {
		printf("arg %d: %s\n", i, argv[i]);
		i--;
	}

	return 0;	

}
