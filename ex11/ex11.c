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

	char *states[] = {
		"California", "Oregon",
		"Washington", "Texas"
	};

	int num_states = 4;
	//int i = 0;
	// error: redefinition of ‘i’
	i = 1;

	while(i < num_states) {
		printf("state %d: %s\n", i, states[i]);
		i++;

		// if forget i++, then will have unlimited loop,
		// since i will always be 1, 
	
	}

	return 0;	

}
