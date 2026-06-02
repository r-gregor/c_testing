/*
 * fname: csv-split-test.c
 * v1_20260601
 * v2_20260601 run on array of csv strings ...
 * last: 20260601
 */
#include <stdio.h>
#include <string.h>
#include <stdint.h>

typedef struct CsvStringParts {
	char *mystring;
	uint32_t delim_pos;
	uint32_t string_len;
} CsvStringParts;


// CsvStringParts get_string_parts(char *string);
void get_string_parts(CsvStringParts *line, char *string);
uint32_t get_delim_position(char *line);
void display_fst_part(CsvStringParts *line);
void display_scd_part(CsvStringParts *line);
void csv_string_info(CsvStringParts *line);

int main(int argc, char **argv) {

	char *lines[]={"https://github.com/r-gregor;Gregor Redelonghi´s gitHUB account",
		"https://gitlab.com/r-gregor;Gregor Redelonghi´s gitLAB account",
		"https://github.com/tsoding;Mr. Zozin´s gitHUB account",
	};

	for(int j=0; j < 3; j++) {
		CsvStringParts line1;
		get_string_parts(&line1, lines[j]);
		csv_string_info(&line1);
	}




	return 0;
}


void get_string_parts(CsvStringParts *line, char *string) {
	line->mystring = string;
	line->string_len = strlen(string);
	line->delim_pos = get_delim_position(string);
}

uint32_t get_delim_position(char *line) {
	uint32_t count = 0;
	uint32_t line_len = strlen(line);
	for (int i = 0; i < line_len; i++) {
		if (line[i] == ';') {
			return count;
		} else {
			count++;
		}
	}

	if (count == line_len - 1) {
		printf("[ERROR] no delimiter found\n");
		return 0;
	}
	return 0;
}

void display_fst_part(CsvStringParts *line) {
	printf("'");
	for(int i=0; i < line->delim_pos; i++) {
		printf("%c", line->mystring[i]);
	}
	printf("'");
	printf("\n");
}

void display_scd_part(CsvStringParts *line) {
	printf("'");
	for(int i=line->delim_pos + 1; i < line->string_len; i++) {
		printf("%c", line->mystring[i]);
	}
	printf("'");
	printf("\n");
}

void csv_string_info(CsvStringParts *line) {
	printf("String: '%s'\n", line->mystring);
	printf("Delimiter position at: %d\n", line->delim_pos);
	printf("First part:  "); display_fst_part(line);
	printf("Second part: "); display_scd_part(line);
	printf("---\n");
}

