# define Preprocessor

## 1. for debug

compile with `gcc –D DEBUG typeDefineDebug.c `

```c
#ifdef DEBUG
#define DPRINT(s) fprintf(stderr, "%s\n", s)
#else
#define DPRINT(s)
#endif
```

Check with `gcc -D DEBUG typeDefineDebug.c -E` the `typeDefineDebug.c` will expand to

```c
int main() {
    char s[10] = "hello";
    fprintf(__stderrp, "%s\n", s);
    printf("A: %d\n", 1);
}

```

If compile with `gcc typeDefineDebug.c `, `gcc typeDefineDebug.c -E` the program will expand to 

```c
int main() {
    char s[10] = "hello";
             ;
    printf("A: %d\n", 1);
}
```

**Note:** Empty define is allowed in C, in above case, `DPRINT` was expand to `empty`, but it's still defined. Check with

```c
#ifdef DPRINT
#define A 1
#else
#define A 0
#endif
```

will print A : 1, no matter compile with `gcc typeDefineDebug.c` or `gcc –D DEBUG typeDefineDebug.c`.

## 2 double define error
 can't double define `DPRINT`, will overwrite DPRINT(s).

define only define `DPRINT`, not distinguish beween `DPRINT(s)` `DPRINT(d)`.


```c
#define DPRINT(s) fprintf(stderr, "%s\n", s)
#define DPRINT(d) fprintf(stderr, "%d\n", d)
#else
#define DPRINT(s)
```

## 3 different between #if and #ifdef 

Use #if Not #ifdef

Use #if MACRO not #ifdef MACRO. Someone might write code like:  

```c
#ifdef DEBUG
        temporary_debugger_break();
#endif
```
Someone else might compile the code with turned-of debug info like:  
`cc -c lurker.cc -DDEBUG=0`  
Alway use `#if`, if you have to use the preprocessor. This works fine, and does the right thing, even if DEBUG is not defined at all (!)

```c
#if DEBUG
        temporary_debugger_break();
#endif
```

If you really need to test whether a symbol is defined or not, test it with the defined() construct, which allows you to add more things later to the conditional without editing text that's already in the program:

```c
#if !defined(USER_NAME)
 #define USER_NAME "john smith"
#endif
```

## 4 #if 0
Using #if 0

The easiest way to do this is with an `#if 0` block:

```c
   void 
   example()
   {
      great looking code

      #if 0
      lots of code
      #endif
    
      more code
    }
```
You can't use `/**/` style comments because comments can't contain comments and surely a large block of your code will contain a comment, won't it?

## 5 double define in separate files (cs240 lab5)

- Double define in separate files (directory: esh2defineTest)

`#define NAME "supereth"`  
In your code `NAME` is not a variable. It's a pre-processor symbol, which means the text `NAME` will be replaced everywhere in the input with the string "supreeth". This happens per-file, so it doesn't make sense to talk about it being "external".

If a particular C file is compiled without that #define, any use of NAME will remain as-is.

You can not use extern with macro. but if you want your macro seen by many C files, put your macro definition  `#define NAME "supereth"` in a header file like `def.h` then include your def.h in your C code and then you can use your macro in your C file in all other C file if you include def.h


1\. define same value in separate files

`#define CMD 100` in `esh.c` file, then

`#define CMD 100` in `getCmd.c` file. No conflict.

2\. define different values in separate files

`#define CMD 100` in `esh.c` file, then in file `esh.c` `CMD` is 100.

`#define CMD 50` in `getCmd.c` file. No conflict. in file `getCmd.c` `CMD` is 50.

3\. \#ifndf test in getCmd.c

```c
in esh.c:
#define CMD 100

in getCmd.c: 
#ifndef CMD
#define CMD 50
#endif
```

in `getCmd.c`, `CMD` is still 50, not 100 defined in `esh.c`.

```c
in esh.c:
#ifndef CMD
#define CMD 100
#endif

in getCmd.c: 
#ifndef CMD
#define CMD 50
#endif
```
in `esh.c`, `CMD` is 100; in `getCmd.c`, `CMD` is still 50, not 100 defined in `esh.c`.


```c
in esh.c:
#ifndef CMD
#define CMD 100
#endif

in getCmd.c: 
#define CMD 60
#ifndef CMD
#define CMD 50
#endif
```
in `esh.c`, `CMD` is 100; in `getCmd.c`, `CMD` is still 60.