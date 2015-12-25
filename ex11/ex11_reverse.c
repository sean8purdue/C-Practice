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

	char *var[argc];
	i = 1;
	while(i < argc) {
		var[i] = argv[i];
		printf("var %d: %s\n", i, var[i]);
		i++;
	}

	return 0;	

}
