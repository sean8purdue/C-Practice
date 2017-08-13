#include <stdio.h>

int main(void)
{
    /*char  word[20];*/
    char  wod[3];
    char  word[3];
    wod[0] = 'a';
    wod[1] = 'b';
    wod[2] = '\0';
    printf("%s\n", wod);
    /*if (scanf("%20s", word) == 1)*/
    if (scanf("%s", word) == 1)
        puts(word);
        puts(wod);
    return 0;
}
