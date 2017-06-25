#include <stdio.h>

void byConst(char * const);

int main() {
    char ch1[3] = {'a', 'b', 'c'};
    const char ch2[3] = {'g', 'h', 'k'};

    byConst(ch1);
    for (int i = 0; i < 3; i++) {
        printf("in byConst %c\n", *(ch1 + i));
    }

}

void byConst(char * const ch) {
    for (int i = 0; i < 3; i++) {
        printf("in byConst %c\n", *(ch+i));
        *(ch+i) = 'Y';
    }
}
