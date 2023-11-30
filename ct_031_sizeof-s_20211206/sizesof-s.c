#include <stdio.h>
#include <string.h>

typedef struct Box {

	int ID;               /* 4 bytes */
	int age;              /* 4 bytes */
	long sallary;         /* 8 bytes */
	char address[100];    /* 100 bytes */

} Box;


int main() {

	printf("Size of int       = %lu bytes\n", sizeof(int));
	printf("Size of long      = %lu bytes\n", sizeof(long));
	printf("Size of double    = %lu bytes\n", sizeof(double));
	printf("Size of long long = %lu bytes\n", sizeof(long long));

	printf("\n");
	printf("Size of Box structure                 = %lu bytes\n", sizeof(Box));
	printf("\tSize of int Box.ID            =   %lu bytes\n", sizeof(((Box *)0)->ID));
	printf("\tSize of int Box.age           =   %lu bytes\n", sizeof(((Box *)0)->age));
	printf("\tSize of long Box.sallary      =   %lu bytes\n", sizeof(((Box *)0)->sallary));
	printf("\tSize of char Box.address[100] = %lu bytes\n", sizeof(((Box *)0)->address));

	char *full_name = "Gregor Redelonghi"; /* 17 chars between the quotes */
	char full_name2[] = "Gregor Redelonghi"; /* 17 chars between the quotes */

	printf("\n");
	printf("char *full_name    = \"Gregor Redelonghi\"; ... char *pointer\n");
	printf("char  full_name2[] = \"Gregor Redelonghi\"; ... char array[]\n");
	printf("\n");
	printf("The string: \"'G', 'r', 'e', 'g', 'o', 'r', ' ', 'R', 'e', 'd', 'e', 'l', 'o', 'n', 'g', 'h', 'i', '\\0'\"\n");
	printf("              1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18\n");
	printf("\n");
	

	printf("sizeof(full_name)  =  %lu bytes ... pointer size\n", sizeof(full_name));
	printf("sizeof(full_name2) = %lu bytes ... 17 chars in string + terminal \'\\0\'\n", sizeof(full_name2));
	printf("strlen(full_name)  = %lu bytes ... 17 chars in string without terminal \'\\0\'\n", strlen(full_name));
	printf("strlen(full_name2) = %lu bytes ... 17 chars in string without terminal \'\\0\'\n", strlen(full_name2));
	printf("\n");

	getchar();

	return 0;
}
