#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   int val;
   char str[30];
   
   strcpy(str, "98993489");
   val = atoi(str);
   printf("String value = %s, Int value = %d\n", str, val);

   /*Mathmatical Caculation*/
   int sum = 0;
   sum = val + 1;
   printf("String value = %s, Int value(sum) = %d\n", str, sum);

   strcpy(str, "Can't transfer string");
   val = atoi(str);
   printf("String value = %s, Int value = %d\n", str, val);

   // mixed number and non-number characters. return 987
   strcpy(str, "987a9");
   val = atoi(str);
   printf("String value = %s, Int value = %d\n", str, val);
   sum = val + 1;
   printf("String value = %s, Int value(sum) = %d\n", str, sum);

   strcpy(str, "a987");
   val = atoi(str);
   printf("String value = %s, Int value = %d\n", str, val);

   // return 0;
   strcpy(str, "a987b24");
   val = atoi(str);
   printf("String value = %s, Int value = %d\n", str, val);

   return(0);
}
