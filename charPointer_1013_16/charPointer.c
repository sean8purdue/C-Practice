#include <stdio.h>

int main()
{
	// test1
	char * _outFile;
	_outFile = 0; 
	printf("%s\n", _outFile); // print Null;

	// test2
	char * _inFile;
	_inFile = "Hello World"; 
	printf("%s\n", _inFile); // print Hello World;


    /*char ch[] = "Hello";*/
    /*char *p2 = p1;*/
    /*char *p3 = *p1;*/
    /*printf("ch : %s\n", ch);*/
    /*printf("p1 address [%d] value is %s\n", p1, *p1);*/
    /*printf("p2 address [%d] value is %s\n", p2, *p2);*/
    return 0;
}
