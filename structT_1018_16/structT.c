#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
	char *name;
	int age;
	int height;
	int weight;
};

void memdump(char * p , int len) {
	// Add your code here.
	int i;
	int j;
	for (i=0; i < len; i++) {
		/*printf("0x%08x: ", p);*/
		// print the pointer address, not the value of pointer
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

struct Person *Person_create(char *name, int age, int height, int weight)
{
	struct Person *who = malloc(sizeof(struct Person));
	assert(who != NULL);

	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;

	return who;
}

void Person_destroy(struct Person *who)
{
	assert(who != NULL);
	// Test1_Leak Test
	/*free(who->name);*/

	free(who->name);
	free(who);
}

void Person_print(struct Person *who)
{
	printf("Name: %s\n", who->name);
	printf("\tAge: %d\n", who->age);
	printf("\tHeight: %d\n", who->height);
	printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char *argv[])
{
	// make two people structures
	struct Person *joe = Person_create(
			"Joe Alex", 32, 64, 140);
	struct Person *frank = Person_create(
			"Frank Blank", 20, 72, 180);

	// Test2 create struct on Stack
	struct Person stackP;
	stackP.name = "Stack Person";
	stackP.age = 5;
	printf("StackP is at memory location %p:\n", &stackP);
	printf("StackP.name is at memory location %p:\n", &stackP.name);
	printf("Address StackP.age is at memory location %p:\n", &stackP.age);
	/*memdump( (char *)stackP);*/
	memdump((char *)&stackP, 64);
	Person_print(&stackP);

	// print them out and where they are in memory
	printf("Joe is at memory location %p:\n", joe);
	printf("Joe.name is at memory location %p:\n", joe->name);
	Person_print(joe);
	printf("Frank is at memory location %p:\n", frank);
	Person_print(frank);
	// make everyone age 20 years and print them again
	joe->age += 20;
	joe->height -= 2;
	joe->weight += 40;
	Person_print(joe);
	frank->age += 20;
	frank->weight += 20;
	Person_print(frank);

	// destroy them both so we clean up
	Person_destroy(joe);
	Person_destroy(frank);

	return 0;
}
