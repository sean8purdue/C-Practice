/* Using Functions
 */
#include <stdio.h>
#include <ctype.h>

// forward declarations
int can_print_it(char ch);
void print_letters(char arg[]);
        
void print_arguments(int argc, char *argv[])
{
	int i = 0;
    
	for(i = 0; i < argc; i++) {
		print_letters(argv[i]);
	}
}

void print_letters(char arg[])
{
    int i = 0;
    for(i = 0; arg[i] != '\0'; i++) {
    	char ch = arg[i];
	
	if(can_print_it(ch)) {
		printf("'%c' == %d ", ch, ch);
	}
    }
    printf("\n");
}

int can_print_it(char ch)
{
	return isalpha(ch) || isblank(ch);
}

int main(int argc, char *argv[])
{
	//print_arguments(argc+1, argv);
	/* when call print_arguments inside main,
	   adding 1 to argc, so that it goes past
	   the end of argv arrya

Result: Segmentation fault
sean@seanlinux:~/git/sec/ex14$ ./ex14 arg
'e' == 101 'x' == 120 
'a' == 97 'r' == 114 'g' == 103 
Segmentation fault (core dumped)
sean@seanlinux:~/git/sec/ex14$ 
	 */
	print_arguments(argc, argv);
	return 0;
}
