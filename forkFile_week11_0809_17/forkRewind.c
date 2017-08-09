#include <unistd.h>
#include <sys/types.h>
#include <errno.h> 
#include <stdio.h> 
#include <stdlib.h>

int main() {
    pid_t child_PID;
    int i = 0;

    FILE *fp;

    fp = fopen("./sharedfile", "w+");
    if (fp == NULL) {
        printf("failed to open ./sharedfile \n");
        return(1);
    }

    for (i = 0; i < 100; i++) {
        fprintf(fp, "%d\n",i);
    }

    child_PID = fork();

    if (child_PID < 0) {
        fprintf(stderr, "\n Fork failed\n");
        return 1;
    }

    if ( child_PID == 0 ) {
        rewind(fp);
        fprintf(fp, "%d", -20000000);
        /*fprintf(fp, "%d\n", -20000000);*/
        return 0;
        } else {
        fprintf(fp, "%d\n", 1000);
    }
    return 0;

}
