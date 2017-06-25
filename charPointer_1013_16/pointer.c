#include <stdio.h>

int main() {
    int x;
    int *y;
    int **z;

    x = 5;
    y = &x;
    z = &y;

    printf("x = %d \n", x);
    printf("&x = %p\n", &x);

    printf("*y = %d \n", *y);
    printf("y = %p\n", y);
    printf("&y = %p\n", &y);
    
    printf("**z = %d \n", **z);
    printf("z = %p\n", z);
    printf("&z = %p\n", &z);

}
