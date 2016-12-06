#include <stdio.h>

#include "header.h"

int main(int argc, char *argv[])
{
	/*int i = 0;*/
	/*// go through each string in argv*/
	/*// why am I skipping argv[0]?*/
	/*for(i = 1; i < argc; i++) {*/
		/*printf("arg %d: %s\n", i, argv[i]);*/
	/*}*/

	// Test1
	// let's make our own array of strings
	char *states[] = {
		"California", "Oregon",
		"Washington", "Texas"
	};
	printf("states[1] = %p\n", states[1]);
	memdump( (char *)states[1], 64);
	printf("\n");
	printf("&states[1] = %p\n", &states[1]);
	memdump( (char *)&states[1], 64);

	printf("states[2] = %p\n", states[2]);
	memdump( (char *)states[2], 64);
	printf("\n");
	printf("&states[2] = %p\n", &states[2]);
	memdump( (char *)&states[2], 64);

	int num_states = 4;
	int i;
	for(i = 0; i < num_states; i++) {
		printf("state %d: %s\n", i, states[i]);
	}

	// Test2
	// the string contents "test2" is in Read only Data section.
	// the pointer t2 itself is on stack, print it by &t2;
	printf("\n");
	char * t2 = "test2";
	printf("t2 = %p\n", t2);
	memdump( (char *)t2, 64);

	printf("\n");
	printf("&t2 = %p\n", &t2);
	memdump( (char *)&t2, 64);


	return 0;

}
