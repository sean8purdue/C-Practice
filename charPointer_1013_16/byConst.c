#include <stdio.h>

void byConst(char * const);
void constArray(char const *);

int main() {
    char ch1[3] = {'a', 'b', 'c'};
    const char ch2[3] = {'g', 'h', 'k'};

    // const pointer point to char array
    byConst(ch1);
    for (int i = 0; i < 3; i++) {
        printf("in byConst %c\n", *(ch1 + i));
    }

    printf("\nConst Array Test\n");
    // const array
    constArray(ch2);

}

void byConst(char * const ch) {
    for (int i = 0; i < 3; i++) {
        printf("in byConst %c\n", *(ch+i));
        *(ch+i) = 'Y';
    }
}

void constArray(char const * ch) {
    for (int i = 0; i < 3; i++) {
        printf("in byConst %c\n", *(ch+i));

        /**(ch+i) = 'Y'; // compile error when compile*/
    }
}
