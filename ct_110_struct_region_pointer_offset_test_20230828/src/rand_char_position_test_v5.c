/*
 * v5
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define LINE_LEN 32
#define LINES_NUM 32
#define EMPTY_SPOT '.'

void print_name_chars(char *name, char empty_spot, size_t curr_char);
void display_name_in_memory(char *name, int lines_num, int line_len);
void hl(size_t n);
void header(size_t line_len);
void footer(size_t line_len);

/* Main */
int main(int argc, char **argv) {

	display_name_in_memory("TADEJA MALI REDELONGHI", LINES_NUM, LINE_LEN);

	return 0;
} // end Main

/* 
 * print each char from string name at position curr_char as long as
 * curr_charr position is not over string name length, otherways
 * print EMPTY_SPOT character
 */
void print_name_chars(char *name, char empty_spot, size_t curr_char) {
	if (curr_char < strlen(name)) {
		if (name[curr_char] == ' ') {
			printf("%2c ", empty_spot);
		} else {
			printf("%2c ", name[curr_char]);
		}
	} else {
		printf("%2c ", empty_spot);
	}
}

/*
 * display each character of name at random spot one per line
 */
void display_name_in_memory(char *name, int lines_num, int line_len) {
	srand(time(0));
	int line_start = 0;
	int name_len = strlen(name);

	if (name_len >= lines_num) {
		fprintf(stderr, "Name string to long\n");
		exit(1);
	}

	header(LINE_LEN);

	size_t curr_char = 0;
	for (int i=0; i < LINES_NUM; i++) {
		int curr_pos = line_start + rand() % LINE_LEN;
		for (int j=0; j < LINE_LEN; j++) {
			if (j == curr_pos) {
				print_name_chars(name, EMPTY_SPOT, curr_char);
				curr_char++;
			} else {
				printf("%2c ", EMPTY_SPOT);
			}
		}
		printf("\n");
	}

	footer(LINE_LEN);
}


/* horizontal line n-times dash "-" */
void hl(size_t n) {
	for (int i = 0; i < n -1; i++) {
		printf("-");
	}
	printf("-\n");
}

/* header */
void header(size_t line_len) {
	printf("Displaying entire memory region folded on 32-nd position\n(32 x 32 = 1024 positions)\n\n");
	/* header */
	int hdr;
	for (hdr = 0; hdr < line_len - 1; hdr++) {
		printf("%02d ", hdr);
	}
	printf("%0d\n", hdr);
	
	hl((line_len * 3) - 1);
}

/* footer */
void footer(size_t line_len) {
	hl((line_len * 3) - 1);

	int ftr;
	for (ftr = 1; ftr < line_len; ftr++) {
		printf("%02d ", ftr);
	}
	printf("%0d\n\n", ftr);
}

