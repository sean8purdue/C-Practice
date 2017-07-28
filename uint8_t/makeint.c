#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int makeint(uint8_t *arr) {
    uint8_t *temp = malloc(4);
    temp[0] = arr[3];
    temp[1] = arr[2];
    temp[2] = arr[1];
    temp[3] = arr[0];
    int retval = *(int *)temp;
    free(temp);
    return retval;
}

int main() {
    int i = 0xFFFFFF01;
    printf("%d\n", i);

    uint8_t n8 = i;
    printf("%d\n", n8);

    uint8_t *arr = &n8;
    /*uint8_t *arr = &i;*/
    int ret = makeint(arr);
    printf("%d\n", ret);
    printf("%x\n", ret);

//https://www.badprog.com/c-type-what-are-uint8-t-uint16-t-uint32-t-and-uint64-t
    // testValue
unsigned long long testValue     = 0xFFFFFFFFFFFFFFFF; // 18446744073709551615

// 1 byte -> [0-255] or [0x00-0xFF]
uint8_t         number8     = testValue; // 255
unsigned char    numberChar    = testValue; // 255

// 2 bytes -> [0-65535] or [0x0000-0xFFFF]
uint16_t         number16     = testValue; // 65535
unsigned short    numberShort    = testValue; // 65535

// 4 bytes -> [0-4294967295] or [0x00000000-0xFFFFFFFF]
uint32_t         number32     = testValue; // 4294967295
unsigned int     numberInt    = testValue; // 4294967295

 // 8 bytes -> [0-18446744073709551615] or [0x0000000000000000-0xFFFFFFFFFFFFFFFF]
uint64_t             number64         = testValue; // 18446744073709551615
unsigned long long     numberLongLong    = testValue; // 18446744073709551615


    /*int *a;*/
    /*a = &i;*/
    /*uint8_t *arr;*/
    /*arr = &i;*/
}
