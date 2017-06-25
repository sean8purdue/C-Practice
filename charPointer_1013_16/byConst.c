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

    // run time error
    // Cast const char array to char array test
    // in byConst g
    // [1]    6933 bus error  ./a.out
    printf("\nCast const char array to char array test\n");
    byConst( (char *) ch2);
    for (int i = 0; i < 3; i++) {
        printf("in byConst %c\n", *(ch2 + i));
    }

}

// not usually used
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
