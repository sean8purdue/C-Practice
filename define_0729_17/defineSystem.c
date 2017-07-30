#ifdef __APPLE__
#define SYS 1

#elif __unix__
#define SYS 3

#elif __linux__
#define SYS 5

#else
#define SYS 2

#endif

#include <stdio.h>

int main() {
    printf("%d\n", SYS);
    //print 1 on Mac
    //print 3 on data.cs.purdue.edu, since it's unix
}
