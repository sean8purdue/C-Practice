#include <stdio.h>

//extern declaration tell that the variable is defined in another file
extern void subFuc();

int main() {
    printf("%s \n", __FILE__);
    printf("%d \n", __LINE__);
    printf("\n");
    subFuc();
}
