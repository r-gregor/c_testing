/*
 * fname: csv-split-test.c
 * v1_20260601
 * v2_20260601 run on array of csv strings ...
 * v3_20260601 put everything into function ...
 * v4_20260602 [ERROR] messages if delimiter not found or not in the middle of string
 * last: 20260602
 */
#include <stdio.h>
#include <string.h>
#include <stdint.h>

typedef struct CsvStringParts {
	char *line;
	uint32_t delim_pos;
	uint32_t string_len;
} CsvStringParts;


void init_string_parts(CsvStringParts *str_parts, char *string);
int get_delim_position(char *line, char delim);
void display_fst_part(CsvStringParts *str_parts);
void display_scd_part(CsvStringParts *str_parts);
void print_csv_string_info(CsvStringParts *str_parts);
void get_csv_info_from_array(char *csv_strings[], size_t len);
void get_csv_info_from_string(char *strings);

/* MAIN */
int main(int argc, char **argv) {

	char *csv_strings[]={"https://github.com/r-gregor;Gregor Redelonghi´s gitHUB account",
		"https://gitlab.com/r-gregor;Gregor Redelonghi´s gitLAB account",
		"A sm ti reku, da se lepo obnaši? Ti pa nič.",
		"https://github.com/tsoding;Mr. Zozin´s gitHUB account",
		"A sm ti reku, da se lepo obnaši? Ti pa nič.;",
		"Berthold Strolzenburgher;Just a funny conversion of Arnold Schwarzenegger´s name ...",
		";A sm ti reku, da se lepo obnaši? Ti pa nič.",
	};

	/* from array of strings */
	printf("---\n");
	size_t len = sizeof(csv_strings) / sizeof(csv_strings[0]);
	get_csv_info_from_array(csv_strings, len);

	/* from single string */
	get_csv_info_from_string("https://www.edaboard.com/threads/reading-a-csv-file-in-c.380838;Reading a csv file in C");
	get_csv_info_from_string(";Arrrghh yet another error!");

	return 0;
} /* end main */

/*
 * initialize CsvStringParts struct with line info
 */
void init_string_parts(CsvStringParts *str_parts, char *string) {
	str_parts->line = string;
	str_parts->string_len = strlen(string);
	str_parts->delim_pos = get_delim_position(string, ';');
}

/*
 * get the position (offset) of delimiter ';'
 */
int get_delim_position(char *line, char delim) {
	uint32_t count = 0;
	uint32_t line_len = strlen(line);
	for (int i = 0; i < line_len; i++) {
		if (line[i] == delim) {
			return count;
		} else {
			count++;
		}
	}

	if (count >= line_len) {
		return -1;
	}
	return -1;
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
	// printf("String: '%s'\n", str_parts->line);
	printf("Delimiter position at: '%d'\n", str_parts->delim_pos);
	printf("First part:            "); display_fst_part(str_parts);
	printf("Second part:           "); display_scd_part(str_parts);
	printf("---\n");
}

/*
 * printout info for each of the lines in a strings array
 * len = number of elements (lines) in an array
 */
void get_csv_info_from_array(char *csv_strings[], size_t len) {
	for(int j=0; j < len; j++) {
		CsvStringParts str_parts1;
		init_string_parts(&str_parts1, csv_strings[j]);
		printf("String: '%s'\n", str_parts1.line);
		if (str_parts1.delim_pos == -1) {
			printf("[ERROR] delimiter NOT found\n---\n");
		} else if (str_parts1.delim_pos == 0 || str_parts1.delim_pos >= str_parts1.string_len - 1) {
			printf("[ERROR] delimiter NOT in the middle of string\n---\n");
		} else {
			print_csv_string_info(&str_parts1);
		}
	}
}

/*
 * printout info for single string
 * len = number of elements (lines) in an array
 */
void get_csv_info_from_string(char *string) {
	CsvStringParts str_parts1;
	init_string_parts(&str_parts1, string);
	printf("String: '%s'\n", str_parts1.line);
	if (str_parts1.delim_pos == -1) {
		printf("[ERROR] delimiter NOT found\n---\n");
	} else if (str_parts1.delim_pos == 0 || str_parts1.delim_pos >= str_parts1.string_len - 1) {
		printf("[ERROR] delimiter NOT in the middle of string\n---\n");
	} else {
		print_csv_string_info(&str_parts1);
	}
}

