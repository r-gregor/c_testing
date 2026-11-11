/*
 * fname: new-custom-c-strlen-function.c
 * from: https://www.youtube.com/shorts/XeQlVdCz9Gs
 */

#include <stdio.h>
#include <string.h>

typedef unsigned long long int   nsize_t;
typedef          long long int  nssize_t;

/* === function declarations === */
nsize_t cstr_len1(const char* cstr);
nsize_t cstr_len2(const char* cstr);

/* === MAIN === */
int main(int argc, char **argv) {

	char *mystring1 = "Gregor Redelonghi, Valvasorjeva ulica 5";
	char *mystring2 = "Tadeja Mali Redelonghi, Valvasorjeva ulica 5";

	printf("string1 contents: '%s'\n", mystring1);
	printf("string1 length:   '%lld'\n", cstr_len1(mystring1));
	printf("---\n");
	printf("string2 contents: '%s'\n", mystring2);
	printf("string2 length:   '%lld'\n", cstr_len2(mystring2));

	printf("\n");
	return 0;
}

/* === function definitions === */
nsize_t cstr_len1(const char* cstr) {
	nsize_t len = 0;
	for (; *cstr; cstr++, len++);
	return len;
}

nsize_t cstr_len2(const char* cstr) {
	nsize_t len = 0;
	while(*cstr) {
		cstr++;
		len++;
	}
	return len;
}

