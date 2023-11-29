/*
 * struct_region_offset_v1.c
 */

#include <stdio.h>
#include <string.h>

#define ENG_ALPHABET_CHARS 26
#define MAX_BUFF_ELEMENTS 1025
#define CHARS_PER_LINE 64
#define crt___ printf("---\n");

typedef struct Region Region;

struct Region {
	size_t cursor;
	char *data;
};

/* static region for data container */
char buffer[MAX_BUFF_ELEMENTS];

void show_first_n(Region *r, size_t n);
void populate_with_alphabet(Region *r);
int show_nth(Region *r, size_t n);
void show_all(Region *r);
void set_elements(Region *r);

/* Main */
int main(int argc, char **argv) {

	Region container = {0};
	container.cursor = 0;
	container.data = buffer;

	/* null out entire region */
	memset(container.data, 0, MAX_BUFF_ELEMENTS);

	/* set value of third and 6-th element */
	*(container.data + 2) = 'X';
	*(container.data + 5) = 'Y';

	/* display first 10 */
	show_first_n(&container, 10);
	crt___
	populate_with_alphabet(&container);
	show_first_n(&container, ENG_ALPHABET_CHARS);
	show_first_n(&container, ENG_ALPHABET_CHARS + 11);
	crt___
	show_nth(&container, 6);
	show_nth(&container, 900);
	show_nth(&container, 1026);
	crt___
	memset(container.data, 0, MAX_BUFF_ELEMENTS);
	printf("After null-ing out entire region:\n");
	show_nth(&container, 6);
	show_nth(&container, 900);
	show_nth(&container, 1026);
	crt___
	set_elements(&container);
	show_all(&container);

	return 0;
} // end Main


/* display first n elements */
void show_first_n(Region *r, size_t n) {
	int i = 0;
	for (; i < n; i++) {
		char e = *(r->data + i);
		if (e == 0) {
			printf("%c ", '.');
		} else {
			printf("%c ", *(r->data + i));
		}
	}
	printf("%c\n", *(r->data + i));
}

/* populate with alphabet in first 26-spots */
void populate_with_alphabet(Region *r) {
	for (int j = 0; j < ENG_ALPHABET_CHARS; j++) {
		*(r->data + j) = 'a' + j;
	}
}

/* show n-th element */
int show_nth(Region *r, size_t n) {
		if (n > MAX_BUFF_ELEMENTS) {
			fprintf(stderr, "Element %ld out of buffer bounds!\n", n);
			return -1;
		}
		char e = *(r->data + n);
		if (e == 0) {
			printf("%ld-th element: %c\n",n + 1 , '.');
		} else {
			printf("%ld-th element: %c\n",n + 1 , *(r->data + n));
		}

	return 1;
}

/* show all MAX_BUFF_ELEMENTS */
void show_all(Region *r) {
	int i;
	for (i = 0; i < MAX_BUFF_ELEMENTS; i++) {
		char e;
		if (*(r->data + i) == 0) {
			e = '.';
		} else {
			e = *(r->data + i);
		}

		if (i == 0) continue;
		if ((i % CHARS_PER_LINE) != 0) {
			printf("%c ", e);
		} else {
			printf("%c\n", e);
		}
	}
	printf("%c\n", *(r->data + i));
}

void set_elements(Region *r) {
	*(r->data + 16) = 'G';
	*(r->data + 24) = 'R';
	*(r->data + 128) = 'E';
	*(r->data + 224) = 'G';
	*(r->data + 360) = 'O';
	*(r->data + 720) = 'R';
}

