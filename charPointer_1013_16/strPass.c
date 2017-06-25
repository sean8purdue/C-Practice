#include <stdio.h>
#include <string.h>

struct Books {
    int id;
    char name[3];
    char auther[2];
};

void printBook(struct Books book) {
    printf("in printBook %s\n", book.name);
    printf("in printBook %s\n", book.auther);
    printf("in printBook %d\n", book.id);

    printf("in printBook &book = %p\n", &book);
    printf("in printBook &book.id = %p\n", &book.id);
    printf("in printBook &book.name = %p\n", &book.name);
    printf("in printBook &book.auther = %p\n", &book.auther);
}

void showBook(struct Books * bookPtr) {
    printf("in show %s\n", bookPtr -> name);
    printf("in show %s\n", bookPtr -> auther);
    printf("in show %d\n", bookPtr -> id);

    printf("in show &bookPtr = %p\n", &bookPtr);
    printf("in show bookPtr= %p\n", bookPtr);
    printf("in show &bookPtr -> id = %p\n", &bookPtr -> id);
    printf("in show &bookPtr -> name = %p\n", &bookPtr -> name);
    printf("in show &bookPtr -> auther = %p\n", &bookPtr -> auther);

}

void arrayPass(int mark[], int size) {
    int ct;
    for (ct = 0; ct < size; ct++) {
        printf("in arrayPass Element at %d is %d\n", ct, mark[ct]);
    }

    printf("in arrayPass mark = %p\n", mark);
    printf("in arrayPass mark[1] = %p\n", &mark[1]);
    printf("in arrayPass mark[2] = %p\n", &mark[2]);
}


int main() {
    struct Books book1;

    strcpy(book1.name, "nm");
    strcpy(book1.auther, "a");
    book1.id = 1;

    printf("in main &book1 = %p\n", &book1);
    printf("in main &book1.id = %p\n", &book1.id);
    printf("in main &book1.name = %p\n", &book1.name);
    printf("in main &book1.auther = %p\n", &book1.auther);

    // pass struct to function, copy the contents of struct
    printBook(book1);

    // pass the struct pointer to function, copy the address of struct to function
    showBook(&book1);

    printf("\n");
    printf("Pass Array Test\n");
    // pass the array to fuction
    int marks[3] = {12, 10, 8};

    printf("in main marks = %p\n", marks);
    printf("in main marks[1] = %p\n", &marks[1]);
    printf("in main marks[2] = %p\n", &marks[2]);

    arrayPass(marks, 3);


}

