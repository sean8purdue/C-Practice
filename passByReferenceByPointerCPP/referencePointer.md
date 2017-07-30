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

```c
char * getCmd();
```