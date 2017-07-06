# Learn Basic Header File

## include one header file
In main we want to call `get_double()`, we write the declaration of  `get_double()` in the header file of  `get_double.h`.

```c
get_double.h:

double get_double(char *prompt, double min, double max);

```

We can also write `#include <stdio.h>` in this header file, and in this case we don't need to write `#include <stdio.h>` in front of our main function.

Even we write `#include <stdio.h>` in front of our main function, and `get_double.h`, it will not import `#include <stdio.h>` twice. Since include files should protect against multiple inclusion through the use of macros that "guard" the files. Note that for C++ compatibility and interoperatibility reasons, do not use underscores '_' as the first or last character of a header guard (see below)

```
#ifndef sys_socket_h
#define sys_socket_h  /* NOT _sys_socket_h_ */
#endif 
```

So I prefer to write the depending libary in each .c file, since they will not be multiple inclusion.

## Share a function by header file

The dependency tree is as below:

![MacDown logo](https://github.com/sean8purdue/C-Practice/blob/dev/functionPointer_0705_17/makfileT/dependencyTree.png)

```makefile
geom: geom.o get_double.o
	gcc -o geom geom.o get_double.o

geom.o: geom.c
	gcc -c geom.c

get_double.o: get_double.c
	gcc -c get_double.c

tip: tip.o get_double.o
	gcc tip.o get_double.o -o tip

tip.o: tip.c
	gcc -c tip.c

clean:
	rm -f *.o geom tip
```
If we type `make' in this case, only geom will be build, tip will not be build. We have to use `make tip` to build tip.

We need add `all: geom tip` to use `make` build all targets as geom and tip. 

```bash
➜  makfileT git:(dev) ✗ make
gcc -c geom.c
gcc -c get_double.c
gcc -o geom geom.o get_double.o
gcc -c tip.c
gcc tip.o get_double.o -o tip
```