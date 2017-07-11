// Usefulness of system() utility function.

#include <stdlib.h>
#include <stdio.h>

#define FULLPATHLS "/bin/hostname"

int main() {

    char fullpathls[] = FULLPATHLS;

    system(FULLPATHLS);
    system(fullpathls);

    //system("/Users/Sean/Desktop/hello");
    //system("~/Desktop/hello");
    //system("./hello");
    //system("$PWD/hello");

}
