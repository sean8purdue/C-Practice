#include <stdio.h>
#include <string.h>

int main()
{
	char *p = "hello";
	char q[] = "hello"; // no need to count this

	printf("%zu\n", sizeof(p)); // => size of pointer to char -- 4 on x86, 8 on x86-64
	printf("%zu\n", sizeof(q)); // => size of char array in memory -- 6 on both

	// size_t strlen(const char *s) and we don't get any warnings here:

	printf("%zu\n", strlen(p)); // => 5
	printf("%zu\n", strlen(q)); // => 5

	return 0;
}
