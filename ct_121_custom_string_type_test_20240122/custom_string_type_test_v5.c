/*
 * filename: custom_string_type_test_v5.c
 * v5: names rearrangement
 * 20240125_05 (en)
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * v5:
 * NString_t --> [N]ew [S]tring type
 * all functions to operate on NString_t are
 * prefixed with 'ns_'
 */
typedef struct string {
	size_t len;
	char *contents;
} NString_t;

NString_t *ns_make_string(char *cstr); // v5
void ns_print_string(NString_t *str);
size_t ns_get_str_len(NString_t *str);

int main(void) {

	NString_t *s1 = ns_make_string("Gregor Redelonghi");
	printf("String s1: "); ns_print_string(s1);
	printf("Length of s1: %ld\n", ns_get_str_len(s1));
	printf("---\n");

	char name[20] = "Hula Hula!";
	NString_t *s2 = ns_make_string(name);
	printf("String s2: "); ns_print_string(s2);
	printf("Length of s2: %ld\n", ns_get_str_len(s2));
	printf("---\n");

	char *nm2 = "gregor redelonghi";
	printf("Length of string \"abcdefg\": %ld\n", ns_get_str_len(&(NString_t){.len = strlen("abcdefg"), .contents = "abcdefg"}));
	printf("Length of string \"%s\": %ld\n", nm2, ns_get_str_len(&(NString_t){.len = strlen(nm2), .contents = nm2}));
	printf("---\n");

	char *nm3 = "Tadeja Mali Redelonghi";
	printf("Length of string \"abcdefghi\": %ld\n", ns_get_str_len((ns_make_string("abcdefghi"))));
	printf("Length of string \"%s\": %ld\n", nm3, ns_get_str_len((ns_make_string(nm3))));
	printf("---\n");

	return 0;
}


/* v5
 * converts a c-string into NString_t type string (struct)
 * and returns a pointer to a struct
 * !! does NOT work with returning a pointer to compound literal !!
 */
NString_t *ns_make_string(char *cstr) {
	size_t len = strlen(cstr);
	static NString_t s; // static --> otherwise returning a pointer to local variable --> segfault
	s.len = len;
	s.contents = cstr;
	return &s;
}

/*
 * prints NString_t string to stdout char by char
 * lenght: just chars of string, NO terminatig char
 */
void ns_print_string(NString_t *str) {
	for (size_t i=0; i < str->len; i++) {
		printf("%c", str->contents[i]);
	}
	printf("\n");
}

/*
 * returns the length of contenst of NString_t str
 * NOT the sizeof(NString_t)!
 */
size_t ns_get_str_len(NString_t *str) {
	return str->len;
}

