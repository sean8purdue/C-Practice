# Static Variable Scope

## Local Static Variable
The scope of local static variable is still local. Like below: The static variable `static int a = 1`, the scope of a is just in for, and it will stay in Data section, next iteration, it will become 2, 3, 4, 5, 6, 7

**Note**: The static variable can only be initialized once, when first defined usually.

```C
    for(int i; i < 5; i++) {
        static int a = 1;

        a++;
    }

    // error
    return a++;

```

```
➜  scope_1102_16 git:(dev) ✗ gcc staticScope.c
staticScope.c:25:12: error: use of undeclared identifier 'a'
    return a++;
           ^
1 error generated.
```
