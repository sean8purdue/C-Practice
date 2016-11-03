#include <stdio.h>

char * str2 = "global string for all\n";

void print1(char *p1) {
	printf("%s\n", p1);
	//can't access globale variable g1 which declared after
	/*printf("print2 print g1: %d\n", g1);*/
	printf("Print1 print str1: %s\n", str2);
	//
	//can't access globale variable str1 which declared after
	/*printf("Print2 print str1: %s\n", str1);*/
}

int g1 = 1;
char * str1 = "global string";

void print2(char *p2) {
	printf("%s\n", p2);
	printf("Print2 print str1: %s\n", str1);
	printf("print2 print g1: %d\n", g1);
}

int main() {
	printf("main print g1: %d\n", g1);
	printf("main print str1: %s\n", str1);
	printf("main print str2: %s\n", str2);

	str1 = "main change global str1";
	str2 = "main change str2\n";

	printf("call function print1 & print2\n");
	print1("print1");
	print2("print2");
}
