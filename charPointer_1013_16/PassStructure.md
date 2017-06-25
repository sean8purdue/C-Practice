# Passing Structure by Value and Reference

There are 2 ways to pass Structure in C, one is passing by value, the contents of structure object were copy to the fuction parameter. 

The other way is passing by reference, only the address of structure was copy to the function parameter.

## Passing by Value

~~~c
void printBook(struct Books book) {
    printf("in printBook %s\n", book.name);
    printf("in printBook %s\n", book.auther);
    printf("in printBook %d\n", book.id);

    printf("in printBook &book = %p\n", &book);
    printf("in printBook &book.id = %p\n", &book.id);
    printf("in printBook &book.name = %p\n", &book.name);
    printf("in printBook &book.auther = %p\n", &book.auther);
}
~~~
Result is:

~~~
in main &book1 = 0x7fff54ce7a10
in main &book1.id = 0x7fff54ce7a10
in main &book1.name = 0x7fff54ce7a14
in main &book1.auther = 0x7fff54ce7a17
in printBook nm
in printBook a
in printBook 1
in printBook &book = 0x7fff54ce79a0
in printBook &book.id = 0x7fff54ce79a0
in printBook &book.name = 0x7fff54ce79a4
in printBook &book.auther = 0x7fff54ce79a7
~~~

## Passing by reference
~~~c
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
~~~

Result is:

~~~
in show nm
in show a
in show 1
in show &bookPtr = 0x7fff54ce79a8
in show bookPtr= 0x7fff54ce7a10
in show &bookPtr -> id = 0x7fff54ce7a10
in show &bookPtr -> name = 0x7fff54ce7a14
in show &bookPtr -> auther = 0x7fff54ce7a17
~~~