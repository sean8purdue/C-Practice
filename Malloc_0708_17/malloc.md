# Malloc Learning

## Use a freed pointer
After we free a pointer, we can still use it, but this is wrong and dangerous!! Free just tell the computer we do not want this memoryaddress, you can allocate these region in heap to other malloc() call in the future.

In the file `free.c`, we `free(mess)`, but we can still assign 33 to `*mess`, and print its content.

```
➜  Malloc_0708_17 git:(dev) ✗ ./a.out
*mess is 	53
```

The dangerous is if the following malloc reuse the memory address which mess point to, our previous value 33 will be overwrite without any notice.

The best practice is to assign null to the pointer `mess = null` in this case. Then if we want to assign to mess, it will have error.
