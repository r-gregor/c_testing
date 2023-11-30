/*
 * single_struct_serialization_test_v1.c
 * from: c_howto_array-of-structs-serialization-multif_20230921.txt
 *       https://stackoverflow.com/questions/15707933/how-to-serialize-a-struct-in-c
 *       [**1]
 * 20230925_01 (en)
 * 20230926_01 (en)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct A {
	int a;
	char *str;
} test_struct_t;

/*
 * construct char buffer to store (pack/serialize) struct into
 * serialize (memcpy ...)
 * return pointer to char buffer
 */
char *serialize(test_struct_t t) {
	int str_len = strlen(t.str);

	/* size of struct: size of 2 ints + size of string */
	int size = 2 * sizeof(int) + str_len;

	/* add +1 to size for string termination '\0' */
	char *buf = malloc(sizeof(char) * (size+1));

	memcpy(buf, &t.a, sizeof(int));                      // at offset 0:         t.a
	memcpy(buf + sizeof(int), &str_len, sizeof(int));    // at offset 0+int:     string length
	memcpy(buf + sizeof(int) * 2, t.str, str_len);       // at offset 0+int+int: string value
	buf[size] = '\0';                                    // OR memset to 0 entire buf beforehand!

	return buf;
}


/*
 * initialite receiving struct t
 * deserialize data into struct t from buffer
 * return struct t
 */
test_struct_t deserialize(char *buf) {
	/* receiving struct t */
	test_struct_t t;

	memcpy(&t.a, buf, sizeof(int));

	int str_len;
	memcpy(&str_len, buf+sizeof(int), sizeof(int));

	t.str = malloc(sizeof(char) * (str_len+1));
	memcpy(t.str, buf+2*sizeof(int), str_len);
	t.str[str_len] = '\0';

	return t;
}

/* MAIN */
int main() {
	char str[15] = "Hello, world!";

	test_struct_t t;
	t.a = 123;
	t.str = malloc(strlen(str) + 1);
	strcpy(t.str, str);
	printf("original values: %d %s\n", t.a, t.str);

	char *buf = serialize(t);
	test_struct_t new_t = deserialize(buf);
	printf("new values: %d %s\n", new_t.a, new_t.str);

	return 0;
} // end MAIN

