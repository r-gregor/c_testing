/*
 * filename: custom_string_type_test_v2.c
 * v2: make_string() returns compound statement
 * 20240122_02 (en)
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct string {
	size_t len;
	char *contents;
} String_t;

String_t make_string(char *line);
void print_string(String_t *str);
size_t get_str_len(String_t *str);

int main(void) {

	char name[20] = "Hula Hula!";

	String_t s1 = make_string("Gregor Redelonghi");
	String_t s2 = make_string(name);

	printf("String s1: "); print_string(&s1);
	printf("Length of s1: %ld\n", get_str_len(&s1));
	printf("---\n");
	printf("String s2: "); print_string(&s2);
	printf("Length of s2: %ld\n", get_str_len(&s2));
	printf("---\n");

	return 0;
}


/*
 * converts a string into String_t type (struct)
 * end returns a struct
 */
String_t make_string(char *line) {
	size_t len = strlen(line);
	return (String_t) { .len = len, .contents = line }; // v2 - COMPOUND STATEMENT !!
}

void print_string(String_t *str) {
	for (size_t i=0; i < str->len; i++) {
		printf("%c", str->contents[i]);
	}
	printf("\n");
}

/*
 * returns the length of contenst of String_t str
 * NOT the sizeof(String_t)!
 */
size_t get_str_len(String_t *str) {
	return str->len;
}

