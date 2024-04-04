/*
 * relative_pos_v3.c
 * 20240111_01 (en)
 * 20240111_02 (en) -- v2
 * 20240404_03 (en) -- v3
 */
#include <stdio.h>
#include <string.h>
#include "mf_strip_reduce_str_spcs.h" // v3

size_t next_spc_position(char *subline);
size_t words_count(char *line);
void print_relative_lines(char *line);

/* MAIN */
int main(void) {

	char *lines[] = {
		"GREGOR REDELONGHI IN TADEJA MALI REDELONGHI",
		"Zala Mark Špela Tadeja Gregori Sisi",
		"Januar Februar Marec April Maj Junij Julij Avgust September Oktober November December",
		"   first second      third  fourth              fifth    "
	};
	char *clean_line = NULL;
	for (int i = 0; i < sizeof(lines) / sizeof(lines[0]); ++i) {
		printf("Original line: \"%s\"\n", lines[i]);
		clean_line = mf_strip_reduce(lines[i]); // v3
		print_relative_lines(clean_line);
		memset(clean_line, 0, MAX_MULT_SPCS_STR_LEN);
	}


	return 0;
} /* END MAIN */

/*
 * find position (offset) to next space char
 * @param subline (string)
 */
size_t next_spc_position(char *subline) {
	size_t pos = 0;
	while (subline[pos] != '\0') {
		pos++;
		if (subline[pos] == ' ') {
			return pos;
		}
	}
	return 0;
}

/*
 * get number of words in line (delim = space)
 * @param line (string)
 */
size_t words_count(char *line) {
	size_t i = 0;
	size_t cnt = 0;
	while (line[i] != '\0') {
		if (line[i] == ' ') {
			cnt++;
		}
		i++;
	}
	return cnt + 1;
}

void print_relative_lines(char *line) {
	size_t curr_pos = 0;
	size_t count = 0;
	char *ln = line;
	while(1) {
		count++;
		printf("iteration %02ld: %s\n", count, ln);

		/* set poiner to space character */
		curr_pos = next_spc_position(ln);
		if (curr_pos == 0) {
			break;
		}
		/* set pointer to character next to space (next word) */
		ln += curr_pos + 1;
	}
	printf("---\n");
}

