#include <stdio.h>
#include <string.h>
#include <stdint.h>

/* test for _Generic keyword (C11) inside a macro
 * from: http://www.robertgamble.net/2012/01/c11-generic-selections.html#more
 */

/* Get the name of a type */
#define typename(x) _Generic((x), _Bool: "_Bool", \
char: "char", \
signed char: "signed char", \
unsigned char: "unsigned char", \
short int: "short int", \
unsigned short int: "unsigned short int", \
int: "int", \
unsigned int: "unsigned int", \
long int: "long int", \
unsigned long int: "unsigned long int", \
long long int: "long long int", \
unsigned long long int: "unsigned long long int", \
float: "float", \
double: "double", \
long double: "long double", \
char *: "pointer to char", \
void *: "pointer to void", \
int *: "pointer to int", \
default: "other")

void test_typename(void) {
	size_t s;
	ptrdiff_t p;
	intmax_t i;

	int ai[3] = {0};

	printf("size_t is '%s'\n", typename(s));
	printf("ptrdiff_t is '%s'\n", typename(p));
	printf("intmax_t is '%s'\n", typename(i));

	printf("character constant is '%s'\n", typename('0'));
	printf("0x7FFFFFFF is '%s'\n", typename(0x7FFFFFFF));
	printf("0xFFFFFFFF is '%s'\n", typename(0xFFFFFFFF));
	printf("0x7FFFFFFFU is '%s'\n", typename(0x7FFFFFFFU));
	printf("array of int is '%s'\n", typename(ai));
}

int main(int argc, char **argv) {

    test_typename();

	return 0;
}

