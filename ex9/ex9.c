#include <stdio.h>

int main(int argc, char *argv[])
{
	/* I didn't have to give all 4 elements of the arrays to initialize them. This is a short-cut that C has where, if you set just one element, it'll fill the rest in with 0.
	 */
	int numbers[4] = {0};
	char name[4] = {'a'};

	//first, print them out raw
	printf("numbers: %d %d %d %d\n",
			numbers[0], numbers[1],
			numbers[2], numbers[3]);

	printf("name: %c %c %c %c\n",
			name[0], name[1],
			name[2], name[3]);

	printf("name: %s\n", name);

	// setup the numbers
	numbers[0] = 1;
	numbers[1] = 2;
	numbers[2] = 3;
	numbers[3] = 4;

	// setup the name
	name[0] = 'Z';
	name[0] = 'e';
	name[0] = 'd';
	name[0] = '\0';

	// print them out initially
	printf("numbers: %d %d %d %d\n",
			numbers[0], numbers[1],
			numbers[2], numbers[3]);

	printf("name: %c %c %c %c\n",
			name[0], name[1],
			name[2], name[3]);

	return 0;
}
