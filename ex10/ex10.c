#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;

	// go through each string in argv
	// why am I skipping argv[0]?
	/* The OS passes each command line argument
	   as a string in the argv array. 
	   The program's name (./ex10) is at 0,
	   with the rest coming after it.*/

	// passing the first argument(the program's name)
	/* sean@seanlinux:~/git/sec/ex10$ ./ex10 te se
	   arg 0: ./ex10
	   arg 1: te
	   arg 2: se
	 */
	// for (i = 0; i < argc; i++) {

	for (i = 1; i < argc; i++) {
		printf("arg %d: %s\n", i, argv[i]);
	}
	

	// make out own array
	char *states[] = {
		"California", "Oregon", 
		"Washington", "Texas"
	};
	int num_states = 4;

	for(i = 0; i < num_states; i++) {
		printf("state %d: %s\n", i, states[i]);
	}

	return 0;
}
