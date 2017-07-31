#include <stdio.h>
#include <iostream>
using namespace std;

#define CMD 100

void getCmd(char *);
char * getCmd1();

void getCmdRef(char&);
void getCmdRef1(char &);

int main() {
    char cmdRef;
    //getCmdRef(cmdRef);
    //cout << cmdRef << endl;

    char *ref1;
    //getCmdRef1(&ref1);
}

void getCmdRef(char& cmdRef) {
    //cmdRef = (char *) malloc( CMD * sizeof(char) );
    //memset(cmdRef , '\0', sizeof(*cmdRef ));
    //strcpy(cmdRef , "hello world");
    cmdRef = 's';



}

void getCmdRef1(char& ref1) {

}

void getCmd(char *nCmd) {
    nCmd = (char *) malloc( CMD * sizeof(char) );
    memset(nCmd, '\0', sizeof(*nCmd));
    strcpy(nCmd, "hello world");
}

char * getCmd1() {
    char * cmd = (char *) malloc( CMD * sizeof(char) );
    memset(cmd, '\0', sizeof(*cmd));
    strcpy(cmd, "hello world");
    return cmd;
}

