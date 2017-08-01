# Const

## 1 const variable

1. cannot assign to or modify variable 'y' with const-qualified type 'const int'

```cpp
    const int y = 1;
    // compile error: try to modify y
    y = 2;

```

## 2 const with pointer

### 2.1 data is const, pointer is not const
Data is const, data is pointed by the pointer, cannot change data value.

Pointer is not const, can change pointer value, which means point can point to different value'.  
**Note1:** Even change `p1` point to different value, the new value pointed by p1 is still not modified, in below case, `z`'s value is still not modified by p1. 
 
The declaration `const int *p1 ` means, we want an int pointer, and we don't want to change the value (which is pointed by the pointer) using this pointer. But we might still change the value with other `non const pointer` or `variable name`, if the variable is not declared as `const variable`.

**Note2:** Even we cannot change `x` or `z` values by `p1`, but we can change their value by directly use their names. Like `x = 20`, `z = 30`. Because `x` or `z` is not declared as a const variable like `const int y`.


```cpp
    // Test2: const with pointer
    const int *p1 = &x; //data is const, pointer is not const
    
    // 2.1.1 data is const, data is pointed by pointer is const
    *p1++;  // compile error, try to modify const data
    *p1 = 2;  // compile error, try to assign to const data
    printf("%d\n", *p1); //print x: 2;

    int z = 3;
    // change pointer p1 point to different value
    p1 = &z;
    printf("%d\n", *p1); //print z: 3;
    *p1++;  // compile error, try to modify const data
    *p1 = 30;  // compile error, try to assign to const data
```

```cpp
    // Test2.1.2
    x = 20;
    z = 30;
    // still can modify x and z by variable name, since they are not declared as const variable.
    printf("still can modify x with name: %d\n", x); // x:20
    printf("still can modify z with name: %d\n", z); // z:30

    // compile error assign a `const int *` to `int *`
    //int *p2 = p1;

    // change z value by a `non const int *`
    int *p3 = &z;
    *p3 = 300;
    printf("modify z with another non const int pointer: %d\n", z); // z:300
```

### 2.2 const variable with non-const pointer

Compile error when try to assign non-const pointer to const variable.

```cpp
    // test 2.2 const variable with non-const pointer
    const int a = 5;
    int *p5 = &a; // compile error
    const int *p6 = &a;  // OK
```
