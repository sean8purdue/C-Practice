#include <stdio.h>
#include <iostream>
using namespace std;

#define CMD 100

void cmdRef(char &);
void cmdPtr(char *);

//void cmdRef1(char &);
//char * getCmd1();

int main() {
    char ref[10] = "";
    char *prt = ref;
}

void cmdRef(char& refArg) {
    char inCmdRef;

}

void cmdPtr(char *ptrArg) {
}
