/*  If, Else-If, Else
 
 */
#include <stdio.h>

int main(int argc, char*argv[])
{
	int i = 0;
	
	if (argc == 2) {
		printf("You only have one argument \n");
	//} else if(argc >1 || argc < 4) {
	/* either argc > 1 or arc < 4, will execute the if statemet
	   sean@seanlinux:~/git/sec/ex12$ ./ex12 1 2 3 4 5 6 7 
	   Here is your argvs
	   ./ex12 1 2 3 4 5 6 7 
	 */
	} else if(argc >1 && argc < 4) {
		printf("Here is your argvs\n");

		for(i = 0; i < argc; i++) {
			printf("%s ", argv[i]);
		}
		printf("\n");
	} else {
		printf("You have too many argvs\n");
	}

	return 0;
}
