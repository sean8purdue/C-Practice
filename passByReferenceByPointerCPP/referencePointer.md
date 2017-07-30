# CPP pass by reference vs pointer

## 1. pass by pointer1
In `main()`: create a `char * cmd`, pass it's value 0 (the address) to subfunction `getCmd(char *)`. The passing process is : main will create a **separate variable `arg1`**, which is a  `char * ` in his Stack top (lower address, since stack grow downward). 
`char * arg1 = cmd;` 

In `getCmd(char *)`, will use this separated variable `char * arg1`, can rename it as `nCmd`. Here `nCMD = NULL`.

If we allocate new space and address to nCmd with malloc, then `nCmd = 3000` assume 3000 is the return value of `malloc`.

But `char * cmd` is still 0, which is not changed by nCmd. That means after returning from `getCmd(char *)`, we `nCmd` will be destroyed, and we will loss the address 3000, and cause memory leak.
 

```c
void getCmd(char *);
int main() {
    char *cmd = NULL;
    cmd = getCmd();
    cout << cmd << endl;
}
void getCmd(char *nCmd) {
	nCmd = (char *) malloc( 100 * sizeof(char) );
	strcpy(nCmd, "hello");
	
}
```
## pass by pointer2

Create a new `char * cmd` in subfunction `getCmd1()`, and return the value of `cmd` back to `main`. Then the value of pointer variable `char * cmd1` will be changed to new value.

And we can also `free(cmd)` to free the mem.

```c
char * getCmd1();

int main() {
// 2 pass by pointer 2
    char *cmd1 = NULL;
    cmd1 = getCmd1();
    fprintf(stderr, "%s\n", cmd1);
    // print hello world
    free(cmd1);
    fprintf(stderr, "%s\n", cmd1);
    // Dangerous!! still print hello world, because free just tell OS, we will not use that mem, but OS might not delete the content start from this addrss.
}

char * getCmd1() {
    char * cmd = (char *) malloc( CMD * sizeof(char) );
    memset(cmd, '\0', sizeof(*cmd));
    strcpy(cmd, "hello world");
    return cmd;
}
```

Safely free the pointer:    // after free assign `cmd1 to NULL`

```c
free(cmd1);
cmd1 = NULL;
```