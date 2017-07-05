#include <stdio.h>
#include <string.h>

#define WIDTH 5
#define HEIGHT 6

int jimmy [HEIGHT][WIDTH];
int n,m;

int main ()
{
    int tmp[HEIGHT][WIDTH]; 
    memcpy(tmp, jimmy, sizeof(tmp));

  for (n=0; n<HEIGHT; n++)
    for (m=0; m<WIDTH; m++)
    {
          jimmy[n][m]=(n+1)*(m+1);
        }

    printf("%p\n", &tmp);
    printf("%p\n", tmp);
    printf("%p\n", &tmp[0]);
    printf("%p\n", &tmp[1]);
    printf("%p\n", &tmp[2]);
    printf("%p\n", &tmp[3]);
    printf("%p\n", &tmp[4]);

    printf("\n");
    printf("%p\n", &tmp[0][0]);
    printf("%p\n", &tmp[0][1]);
    printf("%p\n", &tmp[0][2]);
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

