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

	// test3
   char ch[] = "Hello"; /* OK; Creating an array of 6 bytes to store
                         * 'H', 'e', 'l', 'l', 'o', '\0'
                         */
   char *p1 = ch;       /* OK; Creating a pointer that points to the
                         * "Hello" string.
                         */
   char *p2 = p1;       /* OK; Creating a second pointer that also
                         * points to the "Hello" string.
                         */
   char *p3 = p1;       /* OK; Assigning a pointer-to-char to a 
                         * pointer-to-char variables.
                         */
   printf("ch : %s\n", ch);   /* OK */
   printf("p1 address [%p] value is %s\n", p1, p1);  /* Fixed format specifiers */
   printf("p2 address [%p] value is %s\n", p2, p2);  /* Fixed format specifiers */
   printf("p3 address [%p] value is %s\n", p3, p3);  /* Fixed format specifiers */

   	// test4
	// Reference
	//http://stackoverflow.com/questions/25653034/the-difference-between-char-and-char
	//http://stackoverflow.com/questions/10186765/char-array-vs-char-pointer-in-c
	//
	 char c = 'H';                    // A character
   char* pC = &c;                   // A pointer to a single character; IS NOT A STRING
   //
   // An array of characters; IS NOT A STRING
   char cArray[] = { 'H', 'e', 'l', 'l', 'o' };
   
   // An array of characters with a trailing NULL charcter; THIS IS A C-STYLE STRING
   char cString[] = { 'H', 'e', 'l', 'l', 'o', '\0' };  
   // You could also replace the '\0' with 0 or NULL, ie:
   //char cString[] = { 'H', 'e', 'l', 'l', 'o', (char)0 };
   //char cString[] = { 'H', 'e', 'l', 'l', 'o', NULL };
   
   // A C-style string; the '\0' is added automatically for you
   const char* myString = "Hello world!"; 

   printf("%s\n", myString);        // OK; Prints a string stored in a variable
   printf("%s\n", "Ducks rock!");   // OK; Prints a string LITERAL; Notice the use of DOUBLE quotes, " "
   printf("%s\n", cString);         // OK; Prints a string stored in a variable

   printf("%c\n", c);               // OK; Prints a character
   printf("%c\n", *pC);             // OK; Prints a character stored in the location that pC points to
   printf("%c\n", 'J');             // OK; Prints a character LITERAL; Notice the use of SINGLE quotes, ' '

   /* The following are wrong, and your compiler should be spitting out warnings or even not allowing the
    * code to compile. They will almost certainly cause a segmentation fault. Uncomment them if you
    * want to see for yourself by removing the "#if 0" and "#endif" statements.
    */

#if 0
   printf("%s\n", c);               // WRONG; Is attempting to print a character as a string, similar
                                    // to what you are doing.
   printf("%s\n", *pC);             // WRONG; Is attempting to print a character as a string. This is
                                    // EXACTLY what you are doing.
   printf("%s\n", cArray);          // WRONG; cArray is a character ARRAY, not a C-style string, which is just
                                    // a character array with the '\0' character at the end; printf
                                    // will continue printing whatever follows the end of the string (ie:
                                    // random memory, junk, etc) until it encounters a zero stored in memory.
#endif
    return 0;
}
