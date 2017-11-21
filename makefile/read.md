# Makefile examples and documents

1. https://www.gnu.org/software/make/manual/make.html

## gamepad examples

There are two makefiles in the `gamepadTest` directory.
The `Makefile` in the root directory of the project root is an example for a small project. Which include some key concepts as below:

- Variables like   
	`SOURCEDIR=./src`  
	`INCLUDEDIR=./headers`  
	`LIBS=-I$(INCLUDEDIR) -lpthread -lrt`
	
- Special variables like  
  `$@` - the first argument of left hand side  
  `$<` - the first argument of right hand side  
  `$^` - list all arguments on the right hand side  
  `$%.o` - match each file ending in `.o`  
  `$%.c` - match each file ending in `.c`  
  
- execute shell commands  
	`mkdir -p $(BUILDDIR)`
	
- execute different parts of Makefile in order   
  `all: dir gamepad` - first execute `dir` part, then execute `gamepad` part, where `dir` and `gamepad` are the left hand side names followed by `:`.

Makefile:

```makefile
SOURCEDIR=./src
INCLUDEDIR=./headers
BUILDDIR=./build

CC=gcc
CFLAGS=-std=11 -0s

CXX==g++
CXXFLAGS=-std=14 -0s

LIBS=-I$(INCLUDEDIR) -lpthread -lrt

OBJ=$(BUILDDIR)/print.o $(BUILDDIR)/gamepadHandler.o $(BUILDDIR)/gamepadEventHandler.o

all: dir gamepad

gamepad: $(OBJ)
	$(CC) -o $(BUILDDIR)/$@ $^ $(LIBS)

$(BUILDDIR)/%.o: $(SOURCEDIR)/%.c
	$(CC) -c -o $@ $<

dir:
	mkdir -p $(BUILDDIR)

clean:
	rm -rfv $(BUILDDIR) 
```

## local Makefile

There is another `Makefile` in the subdirectory `src`, which is the complete form of Makefile.

It generates each obj files by explicitly specify each dependency of each object file, including `.c` and `.h` files.

And then link all the obj files to one excutable file.

Makefile:

```Makefile
LIBS=-I../headers/ -lpthread -lrt

all: gamepad

gamepad: print.o gamepadHandler.o gamepadEventHandler.o
	gcc -o gamepad print.o gamepadHandler.o gamepadEventHandler.o $(LIBS)

print.o: print.c
	gcc -c print.c

gamepadHandler.o: gamepadHandler.c ../headers/gamepadHandler.h
	gcc -c gamepadHandler.c ../headers/gamepadHandler.h

gamepadEventHandler.o: gamepadEventHandler.c ../headers/gamepadEventHandler.h
	gcc -c gamepadEventHandler.c ../headers/gamepadEventHandler.h

clean:
	rm -rf gamepad *.o
```