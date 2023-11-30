/*
 * struct_region_offset_v3.c
 * v3: function hl() for horizontal line instead of #define CRT___
 * v3: redefine show_all() to dsiplay 32x32 with header and footer
 *     header from 00 till 31 and footer fron 01 till 32
 * v3: redefine set_elements() to write name and surname
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h> // for clr

#define ENG_ALPHABET_CHARS 26
#define MAX_BUFF_ELEMENTS 1025
#define CHARS_PER_LINE 32

typedef struct Region Region;

struct Region {
	size_t cursor;
	char *data;
};

/* static memory region for data container */
char buffer[MAX_BUFF_ELEMENTS];

/* function definitions */
void null_out_mregion(Region *r);
void show_first_n(Region *r, size_t n);
void populate_with_alphabet(Region *r);
void show_nth(Region *r, size_t n);
void show_all(Region *r);
void set_elements(Region *r);
void hl(size_t n);
void clr();


/* Main */
int main(int argc, char **argv) {

	clr();
	
	/* initial setup of memory region */
	/* TODO: allocator initialization function */
	Region container = {0};
	container.cursor = 0;
	container.data = buffer;

	/* null out entire region */
	null_out_mregion(&container);

	/* set value of third and 6-th element */
	printf("Setting value for 3-rd and 6-th position ...\n");
	*(container.data + 2) = 'X';
	*(container.data + 5) = 'Y';

	/* display first 10 */
	int offset1 = 10;
	printf("Displaying first %d positions:\n", offset1);
	show_first_n(&container, offset1);

	hl(3); // ---

	printf("Populating firts 26 positions with ENG alphabet (overriding previous ones) ...\n");
	populate_with_alphabet(&container);
	int offset2 = 50;
	printf("Displayinh first %d positions:\n", offset2);
	show_first_n(&container, ENG_ALPHABET_CHARS + (offset2 - ENG_ALPHABET_CHARS));

	hl(3); // ---

	show_nth(&container, 6);
	show_nth(&container, 900);
	show_nth(&container, 1026);

	hl(3); // ---

	null_out_mregion(&container);
	printf("After null-ing out entire region:\n");
	show_nth(&container, 6);
	show_nth(&container, 900);
	show_nth(&container, 1026);

	hl(3); // ---

	printf("Populating random positions with characters from name and surname ...\n");
	printf("Press any key to continue ...\n");
	getchar();

	clr();

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

/* populate with EN alphabet in first 26-spots */
void populate_with_alphabet(Region *r) {
	for (int j = 0; j < ENG_ALPHABET_CHARS; j++) {
		*(r->data + j) = 'a' + j;
	}
}

/* show n-th element */
void show_nth(Region *r, size_t n) {
	if (n > MAX_BUFF_ELEMENTS) {
		fprintf(stderr, "Element %ld out of buffer bounds!\n", n);
	} else {
		char e = *(r->data + n);
		if (e == 0) {
			printf("%ld-th position: %c\n",n + 1 , '.');
		} else {
			printf("%ld-th position: %c\n",n + 1 , *(r->data + n));
		}
	}
}

/* 
 * show all MAX_BUFF_ELEMENTS in 32x32 array with header and footer
 * header from 00 till 31
 * footer from 01 till 32
 */
void show_all(Region *r) {
	printf("Displaying entire memory region folded on 32-nd position\n(32 x 32 = 1024 positions)\n\n");
	/* header */
	int hdr;
	for (hdr = 0; hdr < CHARS_PER_LINE - 1; hdr++) {
		printf("%02d ", hdr);
	}
	printf("%0d\n", hdr);
	
	hl((CHARS_PER_LINE * 3) - 1);
	
	/* main part: iterating trough all values */
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
			printf("%2c ", e);
		} else {
			printf("%2c\n", e);
		}
	}

	/* footer */
	hl((CHARS_PER_LINE * 3) - 1);

	int ftr;
	for (ftr = 1; ftr < CHARS_PER_LINE; ftr++) {
		printf("%02d ", ftr);
	}
	printf("%0d\n\n", ftr);
}

/* insert individual character of name and surname into [random] consequent
 * positions in the memory region
 */
void set_elements(Region *r) {
	/* TODO: randomize position of each character in line
	 *       in each run
	 */
	
	*(r->data + 16) = 'G';
	*(r->data + 38) = 'R';
	*(r->data + 88) = 'E';
	*(r->data + 98) = 'G';
	*(r->data + 180) = 'O';
	*(r->data + 262) = 'R';

	*(r->data + 416) = 'R';
	*(r->data + 501) = 'E';
	*(r->data + 626) = 'D';
	*(r->data + 702) = 'E';
	*(r->data + 717) = 'L';
	*(r->data + 821) = 'O';
	*(r->data + 855) = 'N';
	*(r->data + 907) = 'G';
	*(r->data + 964) = 'H';
	*(r->data + 1010) = 'I';
}

/* null-ing: set all elements of memory region to 0 */
void null_out_mregion(Region *r) {
	memset(r->data, 0, MAX_BUFF_ELEMENTS);
}

/* horizontal line n-times dash "-" */
void hl(size_t n) {
	for (int i = 0; i < n -1; i++) {
		printf("-");
	}
	printf("-\n");
}

/* clear the screen */
void clr() {
	system("@cls||clear");
}

