# type define

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
