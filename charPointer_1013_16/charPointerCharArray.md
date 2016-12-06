# char *, char []

Can someone explain why this works with the pointer: [Reference](http://stackoverflow.com/questions/6803387/why-can-a-string-be-assigned-to-a-char-pointer-but-not-to-a-char-array)

~~~c
char * str1;

str1 = "Hello1";

str1 = "new string";

// but not this
char str2 [] = "hello";
str2 = "four";

// or this
char str3 [];
str3 = "hello";
str3 = "hello";
~~~

### Why it works with pointers:

When you say `char * str1` in C, you are allocating a pointer in the memory. When you write `str1 = "Hello"`;, you are creating a string literal in memory and making the pointer point to it. When you create another string literal `"new string"` and assign it to `str1`, all you are doing is changing where the pointer points.

### Why it doesn't work with arrays:

When you say `char str2 [] = "Hello"`, you are creating a string literal and putting it in the array during its definition. It is ok to not give a size, as the array calculates it and appends a `'\0'` to it. You cannot reassign anything to that array without resizing it. That is why `str2 = "four"` will not work.

In case of `str3`, it is the same case. You haven't defined the size of the array in the definition, so it calculated its size to be 0. You cannot assign anything new without resizing the array.

### Another Answer

An array and a pointer are different things, that's why. You can assign to a pointer, but you can't assign to an array. A special exception is made for initialization of char arrays with string literals.

~~~c
char a[] = "Hello"; //initialize a char array with string literal. Special case, OK
char* p = "Hello"; //initializa a pointer with an array(which gets converted to pointer)
p = "My";   //assign pointer to point to another value. OK
a = "My";   //error, arrays cannot be assigned to. Use `strcpy`
~~~

String literals (such as "Hello") have type `char[N]` where N is number of characters (including the terminating `'\0'`). An array can be converted to a pointer to its first element, but arrays and pointers are not the same thing, whatever some bad books or teachers may say.

