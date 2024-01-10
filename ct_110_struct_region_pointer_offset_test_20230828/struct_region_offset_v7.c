/*
 * struct_region_offset_v7.c
 * v3: function hl() for horizontal line instead of #define CRT___
 * v3: redefine show_all() to dsiplay 32x32 with header and footer
 *     header from 00 till 31 and footer fron 01 till 32
 * v3: redefine set_elements() to write name and surname
 * v4: randomize set_elements() function
 * v5: change get_name_chars() to return '.' if char is ' '          -- (20240108_03)
 * v5: change get_name_chars() to return 0 if char is ' '            -- (20240108_04)
 * v6: bigger buffer and name NOT cut off at the 32-nd line          -- (20240108_05)
 * v6: test for element outside buffer bounds (> 4069)               -- (20240108_06)
 * v7: implement functions for region initialization                 -- (20240109_07)
 * v7: added +1 in curr_pos to ensure single char per line           -- (20240110_08)
 *     changed type from int to size_t for all counts and positions  -- (20240110_08)
 * ---
 * 20230831_01 (d)
 * 20240108_02 (en)
 * 20240108_03 (en)
 * 20240108_04 (en)
 * 20240108_05 (d)
 * 20240109_06 (en)
 * 20240109_07 (en) -- v7
 * 20240110_08 (en)
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h> // for clr and srand()
#include <time.h>   // for srand()

#define ENG_ALPHABET_CHARS 26
#define MAX_BUFF_ELEMENTS 4096
#define CHARS_PER_LINE 32
#define EMPTY_SPOT '.'

/* static memory region for data container */
char buffer[MAX_BUFF_ELEMENTS];

typedef struct Region Region;

struct Region {
	size_t cursor;
	char *data;
};

/* function definitions */
Region initialize_region();
void set_value_of_element(Region *r, size_t position, char value);
void null_out_mregion(Region *r);
void show_first_n(Region *r, size_t n);
void populate_with_alphabet(Region *r);
void show_nth(Region *r, size_t n);
void show_all(Region *r);
void set_elements_from_string(Region *r, char *name);
char get_name_chars(char *name, size_t curr_char);
void hl(size_t n);
void clr();



size_t lines_num = 0;


/* Main */
int main(int argc, char **argv) {

	clr();
	
	/* initial setup of memory region */
	// v7
	Region container = initialize_region();

	/* null out entire region */
	null_out_mregion(&container);

	/* set value of third and 6-th element */
	// v7
	set_value_of_element(&container, 3, 'X');
	set_value_of_element(&container, 6, 'Y');
	set_value_of_element(&container, 4123, 'Z');

	/* display first 20 */
	int offset1 = 20;
	printf("\nDisplaying first %d positions:\n", offset1);
	show_first_n(&container, offset1);

	hl(3); // ---

	printf("Populating firts 26 positions with ENG alphabet (overriding previous ones) ...\n");
	populate_with_alphabet(&container);
	int offset2 = 50;
	printf("Displaying first %d positions:\n", offset2);
	// show_first_n(&container, ENG_ALPHABET_CHARS + (offset2 - ENG_ALPHABET_CHARS));
	show_first_n(&container, offset2);

	hl(3); // ---

	show_nth(&container, 6);
	show_nth(&container, 900);
	show_nth(&container, 1024);
	show_nth(&container, 5000);

	hl(3); // ---

	null_out_mregion(&container);
	printf("After null-ing out entire region:\n");
	show_nth(&container, 6);
	show_nth(&container, 900);
	show_nth(&container, 1024);
	show_nth(&container, 5000);

	hl(3); // ---

	printf("Populating random positions with characters from name and surname ...\n");
	printf("Press any key to continue ...\n");
	getchar();

	clr();

	set_elements_from_string(&container, "GREGOR REDELONGHI IN SPELA REDELONGHI");
	show_all(&container);

	return 0;
} // end Main

/* initialize region */
Region initialize_region() {
	Region r;
	r.cursor = 0;
	r.data = buffer;
	return r;
}

/* display first n elements */
void show_first_n(Region *r, size_t n) {
	int i = 0;
	for (; i < n; i++) {
		char e = *(r->data + i);
		if (e == 0) {
			printf("%c ", EMPTY_SPOT);
		} else {
			printf("%c ", *(r->data + i));
		}
	}
	printf("%c\n", *(r->data + i));
}

/* populate with ENG alphabet in first 26-spots */
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
			printf("%ld-th position: %c\n",n + 1 , EMPTY_SPOT);
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

	printf("Displaying populated memory region folded on 32-nd position\n\n"); // v6
	/* header */
	int hdr;
	for (hdr = 0; hdr < CHARS_PER_LINE - 1; hdr++) {
		printf("%02d ", hdr);
	}
	printf("%0d\n", hdr);
	
	hl((CHARS_PER_LINE * 3) - 1);
	
	/* main part: iterating trough all values */
	int i;


	// for (i = 0; i < MAX_BUFF_ELEMENTS; i++) {
	for (i = 0; i < (lines_num * CHARS_PER_LINE) + 1; i++) { // v6
		char e;
		if (*(r->data + i) == 0) {
			e = EMPTY_SPOT;
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

/*
 * for each char in name set spot in memory region one per line of length CHARS_PER_LINE
 * if number of spots is larger than namber of chars in name, set spot to '0'
 */
void set_elements_from_string(Region *r, char *name) {
	srand(time(0));
	size_t line_start = 0;
	size_t curr_char = 0;
	size_t name_len = strlen(name); // v6
	// size_t lines_num = (MAX_BUFF_ELEMENTS - 1) / CHARS_PER_LINE;
	lines_num = name_len;

	for (int i=0; i < lines_num; i++) {

		/* +1 in curr_pos, or there were two chars on single line if
		 * one was at the last position
		 */
		size_t curr_pos = line_start + rand() % CHARS_PER_LINE + 1;
		*(r->data + curr_pos) = get_name_chars(name, curr_char);
		curr_char++;
		line_start += CHARS_PER_LINE;
	}
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

/* 
 * return each char from string name at position curr_char as long as
 * curr_char position is not over string name length, otherways
 * return '0' character
 */
char get_name_chars(char *name, size_t curr_char) {
	if (curr_char < strlen(name)) {
		if (name[curr_char] == ' ') {
			// return 1;
			// return '.';
			return 0;
		} else {
			return name[curr_char];
		}
	} else {
		return 0;
	}
}

/*
 * set value for specific position in memory region
 */
void set_value_of_element(Region *r, size_t position, char value) {
	printf("Setting value '%c' for position: %ld\n", value, position);
	if (position > MAX_BUFF_ELEMENTS) {
		fprintf(stderr, "Element %ld out of buffer bounds!\n", position);
	} else {
		*(r->data + position - 1)  = value;
	}
}

