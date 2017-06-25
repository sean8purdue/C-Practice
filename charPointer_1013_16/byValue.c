#include <stdio.h>

void byval_func(int[]);
void byval_char(char[]);

int main () {
    int x[10];
    int y;

    for (y=0; y<3;   y++)
        x[y] = y;

    printf("in main &x = %p\n", &x);
    printf("in main &x[0] = %p\n", &x[0]);
    printf("in main &x[1] = %p\n", &x[1]);
    printf("in main &x[2] = %p\n", &x[2]);

    /* Call byval_func() ,passing the x array by value. */
    byval_func(x);
    
    // change array contents in arrayPass()
    printf("in main x = %d\n", x[0]);
    printf("in main x[1] = %d\n", x[1]);
    printf("\n");

    // char array test
    char c[3] = {'a', 'b', 'c'};
    printf("in main &c = %p\n", &c);
    printf("in main &c[0] = %p\n", &c[0]);
    printf("in main &c[1] = %p\n", &c[1]);
    printf("in main &c[2] = %p\n", &c[2]);

    byval_char(c);
}

/* The byval_function receives an integer array by value. */
void byval_func(int i[]) {
    int y;
    /* print the content: of the integer array. */
    for (y=0; y<3;  y++) 
        printf("%d\n", i[y]);

    printf("in byval i = %p\n", i);
    printf("in byval &i = %p\n", &i);
    printf("in byval &i[0] = %p\n", &i);
    printf("in byval &i[1] = %p\n", &i[1]);
    printf("in byval &i[2] = %p\n", &i[2]);
    
    // change original array contents
    i[0] = 21;
    i[1] = 22;
}

void byval_char(char ch[]) {
    for (int i = 0; i < 3; i++) {
        printf("in byval char[%d] = %c\n", i, ch[i]);
    }
    /*i = 5; // test i can't be used out of for scope*/

    printf("in byval ch = %p\n", ch);
    printf("in byval &ch = %p\n", &ch);
    printf("in byval ch[0] = %c, &ch[0] = %p\n", ch[0], &ch);
    printf("in byval ch[1] = %c, &ch[1] = %p\n", ch[1], &ch[1]);
    printf("in byval ch[2] = %c, &ch[2] = %p\n", ch[2], &ch[2]);
}
