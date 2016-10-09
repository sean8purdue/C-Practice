# atoi() Learn 1008_16

[Reference](https://www.tutorialspoint.com/c_standard_library/c_function_atoi.htm)


The C library function **int atoi(const char *str)** converts the string argument str to an integer (type int).

- **str** -- This is the string representation of an integral number. 

 Like "156", that also means, this string just contain **number character**. 

This function returns the converted integral number as an int value. If no valid conversion could be performed, it returns zero. 

Like "1a56" the string contains non number charcater.

## Test2

- Use the value to do mathmatical caculation.

~~~C
sum = val + 1;
~~~

Mixed number character and non-number character: atoi() will return 0;

- 987a9 will return 987 as an integer, can be used to do mathmatical caculation.

- a987 will return 0;

- a987b24 will return 0;

~~~
String value = 98993489, Int value = 98993489
String value = 98993489, Int value(sum) = 98993490
String value = Can't transfer string, Int value = 0
String value = 987a9, Int value = 987
String value = 987a9, Int value(sum) = 988
String value = a987, Int value = 0
String value = a987b24, Int value = 0~~~ 