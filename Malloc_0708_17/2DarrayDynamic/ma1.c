#include <stdio.h>

#define WIDTH 5
#define HEIGHT 3


int main ()
{
    int jimmy [HEIGHT][WIDTH];
    int n,m;

  for (n=0; n<HEIGHT; n++)

    for (m=0; m<WIDTH; m++)
    {
          jimmy[n][m]=(n+1)*(m+1);
        }

    printf("%p\n", &jimmy);
    printf("%p\n", jimmy);
    printf("%p\n", &jimmy[0]);

    for (n = 0; n < HEIGHT; n++)
        for (m = 0; m < WIDTH; m++) {
            if (m % WIDTH != 0)
                printf("%d  ", jimmy[n][m]);
            else
                printf("%d\n", jimmy[n][m]);
        }
}

