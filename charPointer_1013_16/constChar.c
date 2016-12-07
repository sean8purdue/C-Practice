#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	const char *s1 = "Const String1";
	const char *s2 = "Const String2";

	printf("Const String1 is \"%s\".\n", s1);
	printf("Const String2 is \"%s\".\n", s2);

	// const char* means that the contents of the string are constant. You can have different pointers referring to the same constant memory. 
	// In other words, the pointers are different variables with the same value. Remember that the value of a pointer is the address of the memory to which it refers.
	
	printf("\n");
	// Test1: change s1, let s1 point to s2
	s1 = s2;
	printf("After change s1: Const String1 is \"%s\".\n", s1);

	printf("\n");
	// Test2: change the contents of s4: will fail!!!!
	char *s3 = "Normal String3";
	const char *s4 = "Const String4";

	printf("Normal String3 is \"%s\".\n", s3);
	printf("Const String4 is \"%s\".\n", s4);
	printf("The first Character of String3 is \"%c\".\n", s3[0]);
	printf("The first Character of String4 is \"%c\".\n", s4[0]);

	printf("\n");
	printf("change the contents of s3 and s4\n");


#if 0
	s3[0] = 'A';
	strcpy(s3, "change Str");
	printf("The first Character of String3 is \"%c\".\n", s3[0]);
	// The above statements doesn't work as expected. Since the contents of s3, "Normal String3" is allocated in the READ-Only area of memory - Data Section.
	
	//change the contents of s3 and s4
	//[1]    22774 bus error  ./constChar

#endif
	// Dynamically allocate an string array
	char *ds1;
	const char *dcs1;
	ds1 = (char *)malloc(20 * sizeof(char));
	dcs1 = (const char *)malloc(20 * sizeof(char));

	strcpy(ds1, s3);
	printf("dynamically allocated string ds1 is %s\n", ds1);

	// compile error: cannot change a const char *pointer;
	/*strcpy(dcs1, s3);*/


	ds1[0] = 'A';
	printf("Change the first Character of dynamically allocated string \"%c\".\n", ds1[0]);


	free(ds1);
	//
	// compile error: cannot free a const char *pointer;
	/*free(dcs1);*/

}
