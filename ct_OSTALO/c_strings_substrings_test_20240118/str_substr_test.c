/*
 * str_substr_test.c
 * 20240118_01 (en)
 */

#include <stdio.h>
#include <string.h>


int main(void) {

	char *string1 = "ABCDEFGHIJKLMNOPQRSTVWXYZ";
	printf("char *string1 = \"ABCDEFGHIJKLMNOPQRSTVWXYZ\";\n");
	printf("Full string1:             %30s\n", string1);
	printf("char *subs1 = string1;\n");
	char *subs1 = string1;
	printf("Full subs1:               %30s\n", subs1);
	printf("string1 5 chars forward:  %30s\n", string1 + 5);
	string1 += 5;
	printf("After setting the pointer to: string1 + 5\n");
	printf("Full string1:             %30s\n", string1);

	/* 
	// NO GO --> segfault
	// string1[5] = '#';
	*(string1 + 5) = '#';
	printf("string1 5 chars forward:  %30s\n", string1);
	*/

	/*
	// NO GO --> segfault
	// subs1[12] = '@';
	*(subs1 + 12) = '@';
	printf("Full subs1:                %30s\n", subs1);
	*/
	printf("Cannot change single char in string1  or subs1 --> segfault\n");

	printf("---\n");

	char string2[] = "ABCDEFGHIJKLMNOPQRSTVWXYZ";
	printf("char string2[] = \"ABCDEFGHIJKLMNOPQRSTVWXYZ\";\n");
	printf("Full string2:             %30s\n", string2);
	printf("string2 5 chars forward:  %30s\n", &string2[5]);
	printf("Substring subs2 starts at 5-th char of string2 ...\n");
	printf("char *subs2 = &string2[5];\n");
	char *subs2 = &string2[5];
	printf("Full string2:             %30s\n", string2);
	printf("Full subs2:               %30s\n", subs2);
	printf("string2 char at [5]:      %30c\n", string2[5]);
	printf("Changing string2[10] to '#' ...\n");
	string2[10] = '#';
	printf("Full string2:             %30s\n", string2);
	printf("string2 10 chars forward: %30s\n", (char *)&string2 + 10);

	printf("Changing *(subs2 + 12) to '@' ...\n");
	*(subs2 + 12) = '@';
	printf("Full subs2:               %30s\n", subs2);


	return 0;
}
