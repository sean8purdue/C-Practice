#include <stdio.h>

void subFuc();

int main() {
    printf("%s \n", __FILE__);
    printf("%d \n", __LINE__);
    printf("\n");
    subFuc();
}
