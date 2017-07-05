#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int **A = malloc(3 * sizeof(int *));
    printf("%p %p\n", &A, A);

    for (int i = 0; i < 3; i++) {
        A[i] = malloc(5 * sizeof(int *));
    }
  
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            A[i][j] = i * 10 + j;
            printf("%p ", &(A[i][j]));
        }
        printf("\n");
    }

    int B[3][3];
    printf("%p %p \n", &B, &(B[0][0]));
}

