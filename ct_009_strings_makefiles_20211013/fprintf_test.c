#include <stdio.h>
#include <stdlib.h>

int main () {
   FILE * fp;

   fp = fopen ("file.txt", "w+");
   fprintf(fp, "%s %s %s %d\n", "We", "are", "in", 2012);
   fprintf(fp, "%s %s %s %d\n", "I", "am", "GROOT", 2021);
   
   fclose(fp);
   
   return 0;
}
