/* While-Loop And Boolean Expressions

 */

#include <stdio.h>

int main(int argc, char *argv[]) 
{
	int i = 1;
	while(i < argc) {
		printf("arg %d: %s\n", i, argv[i]);
		i++;
	}

	return 0;	

}
