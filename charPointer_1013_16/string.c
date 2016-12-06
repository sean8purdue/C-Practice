#include <stdio.h>
#include <string.h>

int main()
{
	char *p = "hello";
	char q[] = "hello"; // no need to count this

	printf("%zu\n", sizeof(p)); // => size of pointer to char -- 4 on x86, 8 on x86-64
		  // Since pointer size is 4 bytes on x86, 8 bytes on x86-64

	printf("%zu\n", sizeof(q)); // => size of char array in memory -- 6 on both

	// size_t strlen(const char *s) and we don't get any warnings here:
	// It seems like there also is an Null in the end of char *p = "hello";
	printf("%zu\n", strlen(p)); // => 5
	printf("%zu\n", strlen(q)); // => 5

	return 0;
}
