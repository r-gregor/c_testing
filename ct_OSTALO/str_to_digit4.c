/* Example using strcat by TechOnTheNet.com */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, const char * argv[])
{
   /* Define a temporary variable */
   char example[8];
   char *str = "ggggggg12345678";


   char c1[20] = "G";
   char c2 = 'r';
   char *c3 = "egoR";
   for (int i = 0; i < strlen(str);i++) {
      printf("%c\n", *(str + i));
   }
   
   strncat(c1, &c2, 1);
   printf("%s\n", c1);
   strncat(c1, c3, 4);
   printf("%s\n", c1);

   char *nms = "ddd1234eee";
   int j = 0;
   while (nms[j] != '\0') {
      strncat(c1, &(nms[j]), 1);
      printf("%s\n", c1);
      j++;
   }
   printf("\n");



   return 0;
}