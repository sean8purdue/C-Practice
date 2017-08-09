#include <unistd.h>
#include <sys/types.h>
#include <errno.h> 
#include <stdio.h> 
#include <stdlib.h>

int global_v=0;

int main() {
    pid_t child_PID;
    int local_v = 0;

    child_PID = fork();

    if (child_PID < 0) {
        fprintf(stderr, "\n Fork failed\n");
        return 1;
    }

    if ( child_PID == 0 ) {
        printf("\nin Child process, global_v is \t%d local_v is \t%d", global_v, local_v);
    } else {
        global_v = 1;
        local_v = 1;
        printf("\nin Parent process, global_v is \t%d local_v is \t%d", global_v, local_v);
    }

    return 0;
}
