#include <iostream>
using namespace std;

#define CMD 100

char * getCmd();
//void getCmdRef(char&);

int main() {
    char *cmd;
    cmd = getCmd();
    cout << cmd << endl;
    free(cmd);

    //char *cmdRef;
}

char * getCmd() {
    char * cmd = (char *) malloc( CMD * sizeof(char) );
    char c;
    int i = 0;
    // get user input string with getchar
    while ( (c = getchar()) != '\n' && (i < (CMD-1))   ) {
        cmd[i++] = c; 
    }
    cmd[i] = '\0';
    return cmd;
}

//void getCmd(char& cmdRef) {
    //cmdRef = (char *) malloc( CMD * sizeof(char) );
    //char c;
    //int i = 0;
    //// get user input string with getchar
    //while ( (c = getchar()) != '\n' && (i < (CMD-1))   ) {
        //cmdRef[i++] = c; 
    //}
    //cmdRef[i] = '\0';
//}
