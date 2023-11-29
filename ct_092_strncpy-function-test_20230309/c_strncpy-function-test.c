#include <stdio.h>
#include <string.h>

/* BEWARE [BW1]
 * strncpy() DOES NOT add closing '\0' char
 * it must be added manually !!
 */

int get_chars_num(char *);
void display_all_chars(char *, int);
void print_char(char);

int main(int argc, char **argv) {

	// 2 0 2 3 0 3 0 9 \0 -- characters
	// 0 1 2 3 4 5 6 7 8  -- position (index)
	char *tmpstmp = "20230309";

	printf("           tmpstmp: \"%s\"\n", tmpstmp);
	printf("   strlen(tmpstmp): %ld\n", strlen(tmpstmp));
	printf("chars in (tmpstmp): %d\n", get_chars_num(tmpstmp));
	printf("   chars in string: "); display_all_chars(tmpstmp, get_chars_num(tmpstmp));

	printf("               ---\n");

	char yr[5];
	strncpy(yr, tmpstmp, 4);
	yr[4] = '\0'; // [BW1]
	printf("              Year: \"%s\"\n", yr);
	printf("        strlen(yr): %ld\n", strlen(yr));
	printf("     chars in (yr): %d\n", get_chars_num(yr));
	printf("   chars in string: "); display_all_chars(yr, get_chars_num(yr));

	printf("               ---\n");

	char mm[3];
	/*
	printf("tmpstmp + 0 = %zu; value = %c\n", (size_t) (tmpstmp + 0), *(tmpstmp + 0));
	printf("tmpstmp + 4 = %zu; value = %c\n", (size_t) (tmpstmp + 4), *(tmpstmp + 4));
	printf("tmpstmp + 5 = %zu; value = %c\n", (size_t) (tmpstmp + 5), *(tmpstmp + 5));
	*/
	strncpy(mm, tmpstmp + 4, 2);
	mm[2] = '\0'; // [BW1]
	printf("             Month: \"%s\"\n", mm);
	printf("        strlen(mm): %ld\n", strlen(mm));
	printf("     chars in (mm): %d\n", get_chars_num(mm));
	printf("   chars in string: "); display_all_chars(mm, get_chars_num(mm));

	printf("               ---\n");

	char dd[3];
	strncpy(dd, tmpstmp + 6, 2);
	dd[2] = '\0'; // [BW1]
	printf("               Day: \"%s\"\n", dd);
	printf("        strlen(dd): %ld\n", strlen(dd));
	printf("     chars in (dd): %d\n", get_chars_num(dd));
	printf("   chars in string: "); display_all_chars(dd, get_chars_num(dd));

	// TEST
	printf("---\n");
	char *line = "abcdefghijklmno"; // 15 chars
	printf("char *line     = \"%s\"; // 15 chars\n", line);
	printf("sizeof line: %ld -- size of pointer\n", sizeof(line));
	printf("sizeof *line: %ld -- size of first element of line (1 byte)\n", sizeof(*line));
	printf("sizeof &line: %ld -- size of pointer to first element\n", sizeof(&line));

	printf("---\n");
	char line2[16] = "abcdefghijklmno"; // 15 chars
	printf("char line2[16] = \"%s\"; // 15 chars\n", line2);
	printf("sizeof line2: %ld -- size of char array\n", sizeof(line2));
	printf("sizeof *line2: %ld -- size of first element of line (1 byte)\n", sizeof(*line2));
	printf("sizeof &line2: %ld -- size of pointer to first element\n", sizeof(&line2));

	return 0;
}


int get_chars_num(char *str) {
	int num = 0;
	while(str[num] != '\0') {
		num++;
	}
	return num + 1;
}


void display_all_chars(char *str, int num) {
	printf("[");
	for(int i=0; i < num - 1; i++) {
		print_char(str[i]);
		printf(", ");
	}
	print_char(str[num - 1]);
	printf("]\n");

}

void print_char(char c) {
	if (c == '\0') {
		printf("%s", "\\0");
	} else {
		printf("%c", c);
	}
}

