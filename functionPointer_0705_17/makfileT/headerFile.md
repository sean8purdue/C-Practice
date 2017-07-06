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

![MacDown logo](https://macdown.uranusjr.com/static/images/logo-160.png)

![MacDown logo](https://github.com/sean8purdue/C-Practice/blob/dev/functionPointer_0705_17/makfileT/dependencyTree.png)