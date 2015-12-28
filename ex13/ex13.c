/* Switch Statement
 
 */
#include <stdio.h>

int main(int argc, char *argv[])
{
	if(argc != 2) {
		printf("ERROR: you need one argument\n");
		return 1;
	}	

	int i = 0;
	for(i = 0; argv[1][i] != '\0'; i++) {
		char letter = argv[1][i];
	
		switch(letter) {
			case 'a':
			case 'A':
				printf("%d: 'A'\n", i);
			break;
//			break;
/* sean@seanlinux:~/git/sec/ex13$ ./ex13 aie
0: 'A'
0: 'E'
1: 'I'
2: 'E'
 */

			case 'e':
			case 'E':
				printf("%d: 'E'\n", i);
			break;

			case 'i':
			case 'I':
				printf("%d: 'I'\n", i);
			break;

			case 'o':
			case 'O':
				printf("%d: 'O'\n", i);
			break;

			case 'u':
			case 'U':
				printf("%d: 'U'\n", i);
			break;
		
			case 'y':
			case 'Y':
			// only when the third letter of the first argument is y or Y, then print them out. Ignore the first 2 letters, even they might be y or Y.
				if(i > 2) {
					printf("%d: 'Y'\n", i);
			}
			break;

			default:
				printf("%d: %c is not a vowel\n", i, letter);
			

			//default:
			//	printf("%d: %c is not a vowel\n", i, letter);
/* 
 sean@seanlinux:~/git/sec/ex13$ ./ex13 aiedsa
0: 'A'
1: 'I'
2: 'E'
5: 'A'
 */
		}
	}

	return 0;
}
