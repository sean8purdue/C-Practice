#include <stdio.h>
#include <iostream>
using namespace std;

#define CMD 100

void cmdRef(char &);
void cmdPtr(char *);
void cmdPtr1(char *);

//void cmdRef1(char &);
//char * getCmd1();

int main() {
    char ref;
    cmdRef(ref);
    cout << ref << endl;

    char ptrChar;
    char *ptr = &ptrChar;
    cmdPtr(ptr);
    cout << "in main ptrChar: " << ptrChar << endl;
    // print nothing (null)

    cmdPtr1(ptr);
    cout << "in main ptrChar: " << ptrChar << endl;
    // print C
}

void cmdRef(char& refArg) {
    char inCmdRef;

    //refArg = &inCmdRef;
    // compile error

    refArg = 'A';
}

void cmdPtr(char *ptrArg) {
    char inCmdPtr;
    ptrArg = &inCmdPtr;
    *ptrArg = 'B';
    cout << "in function cmdPtr(): inCmdPtr: " << inCmdPtr << endl; 
}

void cmdPtr1(char *ptrArg) {
    *ptrArg = 'C';
    cout << "in function cmdPtr1(): *ptrArg: " << *ptrArg << endl; 
}
