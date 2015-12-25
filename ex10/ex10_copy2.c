/* copy argv to string array state's elements
   there is one problem, when argc is higher than num_states,
   cann't copy the redundant argvs to states array.
   How ot set varied arrays?
   ??????????????
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

		states[i] = argv[i+1];

		printf("arg %d: %s\n", i+1, argv[i+1]);

		printf("state %d: %s\n", i, states[i]);
	}

//	for (i = 1; i < argc; i++) {
//		printf("arg %d: %s\n", i, argv[i]);
//	}

	return 0;
}
