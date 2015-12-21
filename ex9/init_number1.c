#include <stdio.h>

int main(int argc, char *argv[])
{
	/* I didn't have to give all 4 elements of the arrays to initialize them. This is a short-cut that C has where, if you set just one element, it'll fill the rest in with 0.
	 */
	int numbers[4] = {1};
	char name[4] = {'a'};
	// test non initialized number and character array
	int numbers1[3];
	char name1[3];

	// print non initialized number out
	// result: numbers1: 1 0 4196077  random numbers
	printf("numbers1: %d %d %d\n",
			numbers1[0], numbers1[1],
			numbers1[2]);

	// first, print them out raw
	printf("numbers: %d %d %d %d\n",
			numbers[0], numbers[1],
			numbers[2], numbers[3]);

	// result: random numbers
	printf("name1: %d %d %d\n",
			name1[0], name1[1],
			name1[2]);
	// result: non-sense charater
	printf("name1: %c %c %c\n",
			name1[0], name1[1],
			name1[2]);
	/*
	   sean@seanlinux:~/git/sec/ex9$ ./init_number1 
numbers1: 1 0 4196157
numbers: 1 0 0 0
name1: -56 -63 118
name1: � � v
name: 97 0 0 0
name: a
	 */
//<<<<<<< HEAD
	// To compare_print integer type of character array
	printf("name: %d %d %d %d\n",
			name[0], name[1],
			name[2], name[3]);

//=======
//>>>>>>> 5987dc8e8346fa6382bbfc8b7e70267396e425cd
	printf("name: %c %c %c %c\n",
			name[0], name[1],
			name[2], name[3]);
	return 0;
}
