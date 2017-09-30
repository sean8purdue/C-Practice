 #include <stdio.h>

 /*char ch = 'C';*/

 int main() {
     int ch = 'C';
         /*char * p = (char*) &ch;*/
         char * p = (char*) &ch + 1;
         *p = 65;
         /*char * p = &ch;*/

         printf("%c, %d, %p, %c \n", *p, *p, p, ch);
         printf("%c", ch);
 }
