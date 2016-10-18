#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void memdump(char * p , int len) {
	// Add your code here.
	int i;
	int j;
	for (i=0; i < len; i++) {
		printf("%p: ", p);

		int n = len - i;
		if ( n > 16 ) n = 16;
		for (j = 0; j < n; j++) {
			printf("%02x ", *(unsigned char *) (p+j) );
		}
		for (;j<16;j++) {
			printf("   ");
		}
		for (j = 0; j < n; j++) {
			printf("%c", ((*p)>=32 && (*p) <= 127)?*p:'.');
			p ++;
			i ++;
		}
		printf("\n");
	}
}

struct X{
	char a;
	int i;
	char b;
	int *p;
};

struct List {
	char * str;
	struct List * next;
};

char *p;

int main() {
	char str[20];
	int a = 5;
	int b = -5;
	double y = 12;
	struct X x;
	struct List * head;
	/*p = (char *)head;*/
	/*printf("p=0x%x\n", (unsigned char *) p);*/
	printf("\n");

	x.a = 'A';
	x.i = 9;
	x.b = '0';
	x.p = &x.i;
	strcpy(str, "Hello world\n");
	printf("&str=%p\n", &str);
	memdump(str, 65);
	printf("\n");

	printf("&a=%p\n", &a);
	printf("&b=%p\n", &b);
	printf("&y=%p\n", &y);
	printf("&x=%p\n", &x);
	printf("&head=%p\n", &head);

	printf("&x.a=%p\n", &x.a);
	printf("&x.i=%p\n", &x.i);
	printf("x.i=%d\n", x.i);
	printf("&x.b=%p\n", &x.b);
	printf("&x.p=%p\n", &x.p);
	printf("&head=%p\n", &head);

	memdump((char *) &x.a, 64);
	head = (struct List *) malloc(sizeof(struct List));
	head->str=strdup("Welcome 01 ");
	head->next = (struct List *) malloc(sizeof(struct List));
	head->next->str = strdup("to 0123456789abcde ");
	head->next->next = (struct List *) malloc(sizeof(struct List));
	head->next->next->str = strdup("cs250");
	head->next->next->next = NULL;
	printf("\n");
	memdump((char *) &head, 64);
	printf("\n");
	printf("head=0x%x\n", head);
	/*printf("head=0x%s\n", head);*/
	printf("head->str=0x%x\n", head->str);
	/*printf("head->str=%s\n", head->str);*/
	printf("head->next=0x%x\n", head->next);
	/*printf("head->next=%s\n", head->next);*/
	/*printf("head->=0x%p\n", head->next);*/
	printf("head->next->str=%x\n", head->next->str);
	printf("head->next->next=%x\n", head->next->next);
	printf("head->next->next->str=%x\n", head->next->next->str);
	printf("head->next->next->next=%x\n", head->next->next->next);
	memdump((char*) head, 128);
}
