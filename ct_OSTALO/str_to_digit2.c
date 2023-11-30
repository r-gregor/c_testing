/* Example using strcat by TechOnTheNet.com */

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[])
{
   /* Define a temporary variable */
   char example[100];

   char *str1 = "TechOnTheNet.com ";

   /* Copy the first string into the variable */
   //strcpy(example, "TechOnTheNet.com ");
   strcpy(example, str1);

   /* Concatenate the following two strings to the end of the first one */
   strcat(example, "is over 10 ");
   strcat(example, "years old.");

   /* Display the concatenated strings */
   printf("%s\n", example);

   return 0;
}