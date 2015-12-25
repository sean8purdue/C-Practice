/* copy string array state's elements to argv 
 */


#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;

	// make out own array
	char *states[] = {
		"California", "Oregon", 
		"Washington", "Texas"
	};
	int num_states = 4;

	for(i = 0; i < num_states; i++) {

		argv[i+1] = states[i];

		printf("state %d: %s\n", i, states[i]);
		
		printf("arg %d: %s\n", i+1, argv[i+1]);

	}

//	for (i = 1; i < argc; i++) {
//		printf("arg %d: %s\n", i, argv[i]);
//	}

	return 0;
}
