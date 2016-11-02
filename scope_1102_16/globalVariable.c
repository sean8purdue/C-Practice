#include <stdio.h>

void print1(char *p1) {
	printf("%s\n", p1);
	printf("print2 print g1: %d\n", g1);
}

int g1 = 1;

void print2(char *p2) {
	printf("%s\n", p2);
	printf("print2 print g1: %d\n", g1);
}

int main() {
	printf("main print g1: %d\n", g1);
	printf("Hello\n");
	print1("print1");
	print2("print2");
}
