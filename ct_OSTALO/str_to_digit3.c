/* Example using strcat by TechOnTheNet.com */

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[])
{
   /* Define a temporary variable */
   char example[8];

   char *str1 = "1234";
   char *str2 = "5678";

   /* Copy the first string into the variable */
   //strcpy(example, "TechOnTheNet.com ");
   strcpy(example, str1);

   /* Concatenate the following two strings to the end of the first one */
   strcat(example, str2);


   /* Display the concatenated strings */
   printf("%s\n", example);

   return 0;
}