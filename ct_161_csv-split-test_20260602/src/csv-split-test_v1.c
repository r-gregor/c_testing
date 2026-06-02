/*
 * fname: csv-split-test.c
 * v1_20260601
 * last: 20260601
 */
#include <stdio.h>
#include <string.h>
#include <stdint.h>

typedef struct CsvStringParts {
	char *line;
	uint32_t delim_pos;
	uint32_t string_len;
} CsvStringParts;


// CsvStringParts get_string_parts(char *string);
void get_string_parts(CsvStringParts *str_parts, char *string);
uint32_t get_delim_position(char *line);
void display_fst_part(CsvStringParts *str_parts);
void display_scd_part(CsvStringParts *str_parts);
void csv_string_info(CsvStringParts *str_parts);

int main(int argc, char **argv) {

	char *line = "https://github.com/r-gregor;Gregor Redelonghi´s github account";

	CsvStringParts str_parts1;
	get_string_parts(&str_parts1, line);
	csv_string_info(&str_parts1);

	return 0;
}


void get_string_parts(CsvStringParts *str_parts, char *string) {
	str_parts->line = string;
	str_parts->string_len = strlen(string);
	str_parts->delim_pos = get_delim_position(string);
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

void display_fst_part(CsvStringParts *str_parts) {
	printf("'");
	for(int i=0; i < str_parts->delim_pos; i++) {
		printf("%c", str_parts->line[i]);
	}
	printf("'");
	printf("\n");
}

void display_scd_part(CsvStringParts *str_parts) {
	printf("'");
	for(int i=str_parts->delim_pos + 1; i < str_parts->string_len; i++) {
		printf("%c", str_parts->line[i]);
	}
	printf("'");
	printf("\n");
}

void csv_string_info(CsvStringParts *str_parts) {
	printf("String: '%s'\n", str_parts->line);
	printf("Delimiter position at: %d\n", str_parts->delim_pos);
	printf("First part:  "); display_fst_part(str_parts);
	printf("Second part: "); display_scd_part(str_parts);
	printf("\n");
}

