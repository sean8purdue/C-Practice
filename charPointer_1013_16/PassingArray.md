# C Passing Arrays

When we declare an array as the parameter to a function, we really just get a pointer. Plus, arrays are always automatically passed by reference (e.g., a pointer is passed).

## Pass the array to function test

In the example:

~~~c
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
    int marks[3] = {12, 10, 8};

    printf("in main marks = %p\n", marks);
    printf("in main marks[1] = %p\n", &marks[1]);
    printf("in main marks[2] = %p\n", &marks[2]);

    arrayPass(marks, 3);
}
~~~

Result is:

~~~
in main marks = 0x7fff54ce7a1c
in main marks[1] = 0x7fff54ce7a20
in main marks[2] = 0x7fff54ce7a24
in arrayPass Element at 0 is 12
in arrayPass Element at 1 is 10
in arrayPass Element at 2 is 8
in arrayPass mark = 0x7fff54ce7a1c
in arrayPass mark[1] = 0x7fff54ce7a20
in arrayPass mark[2] = 0x7fff54ce7a24
~~~

We can see the array always pass by address.