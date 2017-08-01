# Const

## 1 const variable

1. cannot assign to or modify variable 'y' with const-qualified type 'const int'

```cpp
    const int y = 1;
    // compile error: try to modify y
    y = 2;

```