#include <stdio.h>

int main() {
	const char *s1 = "Const String1";
	const char *s2 = "Const String2";

	printf("Const String1 is \"%s\".\n", s1);
	printf("Const String2 is \"%s\".\n", s2);

	// const char* means that the contents of the string are constant. You can have different pointers referring to the same constant memory. 
	// In other words, the pointers are different variables with the same value. Remember that the value of a pointer is the address of the memory to which it refers.
	
	// change s1, let s1 point to s2
	s1 = s2;
	printf("After change s1: Const String1 is \"%s\".\n", s1);

}
