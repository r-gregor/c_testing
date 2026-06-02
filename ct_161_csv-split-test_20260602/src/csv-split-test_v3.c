/*
 * fname: csv-split-test.c
 * v1_20260601
 * v2_20260601 run on array of csv strings ...
 * v3_20260601 put everything into function ...
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


void get_string_parts(CsvStringParts *str_parts, char *string);
uint32_t get_delim_position(char *line);
void display_fst_part(CsvStringParts *str_parts);
void display_scd_part(CsvStringParts *str_parts);
void print_csv_string_info(CsvStringParts *str_parts);
void get_csv_info(char *csv_strings[], size_t len);

/* MAIN */
int main(int argc, char **argv) {

	char *csv_strings[]={"https://github.com/r-gregor;Gregor Redelonghi´s gitHUB account",
		"https://gitlab.com/r-gregor;Gregor Redelonghi´s gitLAB account",
		"https://github.com/tsoding;Mr. Zozin´s gitHUB account",
		"Berthold Strolzenburgher;Just a funny conversion of Arnold Schwarzenegger´s name ...",
	};

	printf("---\n");
	size_t len = sizeof(csv_strings) / sizeof(csv_strings[0]);
	get_csv_info(csv_strings, len);

	return 0;
} /* end main */

/*
 * initialize CsvStringParts struct with line info
 */
void get_string_parts(CsvStringParts *str_parts, char *string) {
	str_parts->line = string;
	str_parts->string_len = strlen(string);
	str_parts->delim_pos = get_delim_position(string);
}

/*
 * get the position (offset) of delimiter ';'
 */
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

/*
 * prinf first string part up to delimiter ';'
 */
void display_fst_part(CsvStringParts *str_parts) {
	printf("'");
	for(int i=0; i < str_parts->delim_pos; i++) {
		printf("%c", str_parts->line[i]);
	}
	printf("'");
	printf("\n");
}

/*
 * prinf second string part from delimiter ';' till end
 */
void display_scd_part(CsvStringParts *str_parts) {
	printf("'");
	for(int i=str_parts->delim_pos + 1; i < str_parts->string_len; i++) {
		printf("%c", str_parts->line[i]);
	}
	printf("'");
	printf("\n");
}

/*
 * display single line info
 */
void print_csv_string_info(CsvStringParts *str_parts) {
	printf("String: '%s'\n", str_parts->line);
	printf("Delimiter position at: '%d'\n", str_parts->delim_pos);
	printf("First part:            "); display_fst_part(str_parts);
	printf("Second part:           "); display_scd_part(str_parts);
	printf("---\n");
}

/*
 * printout info for each of the lines in a strings array
 * len = number of elements (lines) in an array
 */
void get_csv_info(char *csv_strings[], size_t len) {
	for(int j=0; j < len; j++) {
		CsvStringParts str_parts1;
		get_string_parts(&str_parts1, csv_strings[j]);
		print_csv_string_info(&str_parts1);
	}
}

