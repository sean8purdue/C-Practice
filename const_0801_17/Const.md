# Const

## 1 const variable

1. cannot assign to or modify variable 'y' with const-qualified type 'const int'

```cpp
    const int y = 1;
    // compile error: try to modify y
    y = 2;

```

2. const variables must be initialized when define, since we cannot change it's value in following

```cpp
    const int c;        			// compile error
    int * const ptr;				// compile error
    const int* const ptr1;		// compile error
	
	// OK
	 const int d = 10;
	 int e = 20;
	 
	 int * const ptr = &e;
	 const int * ptr2 = &d;
	 const int* const ptr1 = &d;

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
    (*p1)++;  // compile error, try to modify const data
    *p1 = 2;  // compile error, try to assign to const data
    printf("%d\n", *p1); //print x: 2;

    int z = 3;
    // change pointer p1 point to different value
    p1 = &z;
    printf("%d\n", *p1); //print z: 3;
    (*p1)++;  // compile error, try to modify const data
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

### 2.3 pointer is const, data is not

Delcaration `int * const p8` means, we want an int pointer, point to a `non const variable`. But this pointer itself cannot point to other `int variables`. Like initially we have `int * const p8 = x' `int b, we cannot change `p8 = &b`.

We can use this pointer `p8` to change the value it pointed to, like `*p8 = 800`, `*p8++`.

#### 2.3.1 const pointer point to non-const variable

const pointer point to const variable will cause compile error.

```cpp
   const int a = 5;
   int b = 8;

    // test 2.3 pointer is const, data is not
    // compile error: cannot initialize a variable of type
    // 'int *const' with an rvalue of type 'const int *'
    int * const p7 = &a;  // compile error: const int a;
    int * const p8 = &x;  // OK since : int x
        
    (*p8)++;
    printf("modify x with int * const pointer p8: %d\n", x);
    *p8 = 200;
    printf("modify x with int * const pointer p8: %d\n", x);

```

#### 2.3.2 const pointer cannot be modified to point to another varibale

```cpp
    // test 2.3.2: const pointer cannot be modified to point to another varibale
    int b = 8;
    p8 = &b; // compile error
       
```

const pointer must be initialized when define, since it we cannot change it's value after difine.

```cpp
    int * const p9; // compile error: must initialized const pointer when define.

    const int* const p9; // compile error
    const int* const p9 = &a;
```

### 2.4 data and pointer are both const

```cpp
    const int d = 8;
    const int* const p9 = &d;
```

### 2.5 Key
If const is one the left of *, data is const

If const is on the right of *, pointer is const

```cpp
		const int d = 8;
		
		// data is const
		int const *p9 = &d;  // donnot use this format, make confusion!!!!!!
		// same as 
		const int *p9 = &d;
		
		int e = 9;
		// pointer is const
		int * const p9 = &e;
```

Why use const:  

1. Guards against inadvertent write to the variable
2. Self documenting
3. Enables compiler to do more optimiztion, making code tighter
4. const means the variable can be put in Read Only Memory (Data or BSS section)

