# Pointer to Function and Makefile

## Question: 
1. [Q1](#1): print the code which by the fuction poiner point to.

## 1. Pointer to function

- Standard usage:

```c
int twice(int);
int runfunc(int (*g)(), int);


    int (*f) (int);
    f = &twice; \\if we use f = twice, it aslo works, but recommend to use &twice.
    
    y = (*f)(x); \\if we use y = f(x), also works, but recommend to use (*f)(x), to say f is a function pointer

```

- memdump the code, which was pointed by function pointer.
	<h3 id="1"></h3>
	Since we know the address of function, so I was wondering if we could print the code which is pointed by function pointer, which is located in the Text section, it's a read only section. I guess it's still can be read and print out.
	
	I can print the content, but the problem is I don't know the content is the code or not.
	
	```bash
	➜  functionPointer_0705_17 git:(dev) ✗ ./pointerFunc
	result = 6
	result = 8
	result = 10
	result = 12
	0x000000b0: 55 48 89 e5 89 7d fc 8b 7d fc c1 e7 01 89 f8 5d UH...}..}......]
	0x000000c0: c3 66 66 66 66 66 66 2e 0f 1f 84 00 00 00 00 00 .ffffff.........
	0x000000d0: 55 48 89 e5 48 83 ec 20 48 89 7d f8 89 75 f4 48 UH..H.. H.}..u.H
	
	```