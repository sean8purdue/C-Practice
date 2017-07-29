//compile with gcc –D DEBUG program.c

#include <stdio.h>

#ifdef DEBUG
#define DPRINT(s) fprintf(stderr, "%s\n", s)
#else
#define DPRINT(s)
#endif

#ifdef DPRINT
#define A 1
#else
#define A 0
#endif

int main() {
    char s[10] = "hello";
    DPRINT(s);
    printf("A: %d\n", A);
}

