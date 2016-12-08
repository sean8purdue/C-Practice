#include <stdio.h>
#include <string.h>

int main()
{
   char src[40];
   char dest[100];

#if 0
   char *str;
   // cannot strcpy here, since char *str point to nothing.
   strcpy(str, "This is tutorialspoint.com");
#endif

  
   memset(dest, '\0', sizeof(dest));
   strcpy(src, "This is tutorialspoint.com");
   strcpy(dest, src);

   printf("Final copied string : %s\n", src);
   printf("Final copied string : %s\n", dest);
   
   return(0);
}
