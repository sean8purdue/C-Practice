/*#include <atdio.h>*/
#include <stdio.h>

void byval_func(int[]);

int main () {
    int x[10];
    int y;

    for (y=0; y<3;   y++)
        x[y] = y;

    printf("in main &x[0] = %p\n", &x);
    printf("in main &x[1] = %p\n", &x[1]);
    printf("in main &x[2] = %p\n", &x[2]);

    /* Call byval_func() ,passing the x array by value. */
    byval_func(x);
}

/* The byval_function receives an integer array by value. */
void byval_func(int i[]) {
    int y;
    /* print the content: of the integer array. */
    for (y=0; y<3;  y++) 
        printf("%d\n", i[y]);

    printf("in byval i = %p\n", i);
    printf("in byval &i[0] = %p\n", &i);
    printf("in byval &i[1] = %p\n", &i[1]);
    printf("in byval &i[2] = %p\n", &i[2]);
}
