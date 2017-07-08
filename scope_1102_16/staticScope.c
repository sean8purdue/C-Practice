#include <stdio.h>
int func1(void);

int main() {
    int x;

    x = func1();

    /*x = func1();*/
    /*printf("%d\n", x);*/

    /*x = func1();*/
    /*printf("%d\n", x);*/

    return 0;
}

int func1() {
    for(int i; i < 6; i++) {
        static int a = 1;

        a++;
        printf("%d\n", a);
    }
    /*return a++;*/
    return 0;
}
