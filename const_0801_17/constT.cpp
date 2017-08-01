#include <stdio.h>

int main() {
    // const test 1: const variable
    int x = 1;
    x = 2; // modify x is ok
    printf("%d\n", x);

    const int y = 1;
    // compile error: try to modify y
    y = 2;
}
