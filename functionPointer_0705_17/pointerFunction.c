#include <stdio.h>
#include "memdump.h"

int twice(int);
int runfunc(int (*g)(), int);

int main() {
    int x, y;
    int (*f) (int);

    x = 3;
    y = twice(x);
    printf("result = %d\n", y);

    f = &twice;
    x = 4;
    y = (*f)(x);
    printf("result = %d\n", y);

    x = 5;
    y = runfunc(&twice, x);
    printf("result = %d\n", y);

    x = 6;
    y = runfunc(f, x);
    printf("result = %d\n", y);

    // try to print the function code
    int len = 50;
    memdump( (char *)f, len );

    /*printf("%08x\n", *(unsigned char *)f);*/
    /*printf("%x\n", *(unsigned char *)f);*/
    /*printf("%x\n", (unsigned char )(f-1));*/
    /*printf("%x\n", (unsigned char )(f-2));*/

    /*printf("0x%08x: ",p)*/
    /*printf("%02x ", *(unsigned char *) (p+j) );*/

}

int twice(int a) {
    return 2*a;
}

int runfunc(int (*h)(), int a) {
    int b;
    b = (*h)(a);
    return b;
}

