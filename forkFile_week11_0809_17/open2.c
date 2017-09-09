#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

    int filedesc = open("ex.txt", O_RDWR | O_APPEND);
    if(filedesc < 0)
        return 1;
    printf("open1 = %d\n", filedesc);

    if(write(filedesc,"1 Th will be output to testfile.txt\n", 36) != 36) {
        write(2,"There was an error writing to testfile.txt\n", 36);
        return 1;
    }

    int filedesc2 = open("ex.txt", O_RDWR | O_APPEND);
    if(filedesc2 < 0)
        return 1;
    printf("open2 = %d\n", filedesc2);

    if(write(filedesc2,"2 Th will be output to testfile.txt\n", 36) != 36) {
        write(2,"There was an error writing to testfile.txt\n", 36);
        return 1;
    }
}
