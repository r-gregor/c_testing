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
	char *mystring;
	uint32_t delim_pos;
	uint32_t string_len;
} CsvStringParts;


void get_string_parts(CsvStringParts *line, char *string);
int get_delim_position(char *line, char delim);
void display_fst_part(CsvStringParts *line);
void display_scd_part(CsvStringParts *line);
void print_csv_string_info(CsvStringParts *line);
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

	return 0;
} /* end main */

/*
 * initialize CsvStringParts struct with line info
 */
void get_string_parts(CsvStringParts *line, char *string) {
	line->mystring = string;
	line->string_len = strlen(string);
	line->delim_pos = get_delim_position(string, ';');
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
void display_fst_part(CsvStringParts *line) {
	printf("'");
	for(int i=0; i < line->delim_pos; i++) {
		printf("%c", line->mystring[i]);
	}
	printf("'");
	printf("\n");
}

/*
 * prinf second string part from delimiter ';' till end
 */
void display_scd_part(CsvStringParts *line) {
	printf("'");
	for(int i=line->delim_pos + 1; i < line->string_len; i++) {
		printf("%c", line->mystring[i]);
	}
	printf("'");
	printf("\n");
}

/*
 * display single line info
 */
void print_csv_string_info(CsvStringParts *line) {
	// printf("String: '%s'\n", line->mystring);
	printf("Delimiter position at: '%d'\n", line->delim_pos);
	printf("First part:            "); display_fst_part(line);
	printf("Second part:           "); display_scd_part(line);
	printf("---\n");
}

/*
 * printout info for each of the lines in a strings array
 * len = number of elements (lines) in an array
 */
void get_csv_info_from_array(char *csv_strings[], size_t len) {
	for(int j=0; j < len; j++) {
		CsvStringParts line1;
		get_string_parts(&line1, csv_strings[j]);
		printf("String: '%s'\n", line1.mystring);
		if (line1.delim_pos == -1) {
			printf("[ERROR] delimiter NOT found\n---\n");
		} else if (line1.delim_pos == -1 || line1.delim_pos == 0 || line1.delim_pos >= line1.string_len - 1) {
			printf("[ERROR] delimiter NOT in the middle of string\n---\n");
		} else {
			print_csv_string_info(&line1);
		}
	}
}

/*
 * printout info for single string
 * len = number of elements (lines) in an array
 */
void get_csv_info_from_string(char *string) {
	CsvStringParts line1;
	get_string_parts(&line1, string);
	printf("String: '%s'\n", line1.mystring);
	if (line1.delim_pos == -1) {
		printf("[ERROR] delimiter NOT found\n---\n");
	} else if (line1.delim_pos == -1 || line1.delim_pos == 0 || line1.delim_pos >= line1.string_len - 1) {
		printf("[ERROR] delimiter NOT in the middle of string\n---\n");
	} else {
		print_csv_string_info(&line1);
	}
}

