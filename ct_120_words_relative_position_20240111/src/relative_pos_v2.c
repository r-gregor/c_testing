/*
 * relative_pos_v2.c
 * 20240111_01 (en)
 * 20240111_02 (en) -- v2
 */
#include <stdio.h>
#include <string.h>

size_t next_spc_position(char *subline);
size_t words_count(char *line);
void print_relative_lines(char *line);

int main(void) {

	char *lines[] = {"GREGOR REDELONGHI IN TADEJA MALI REDELONGHI",
		             "Zala Mark Špela Tadeja Gregor",
					 "Januar Februar Marec April Maj Junij Julij Avgust September Oktober November December"
	};

	for (int i = 0; i < sizeof(lines) / sizeof(lines[0]); ++i) {
		print_relative_lines(lines[i]);
	}


	return 0;
}

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
	size_t curr_pos2 = 0;
	size_t count2 = 0;
	char *ln2 = line;
	while(1) {
		count2++;
		printf("iteration %02ld: %s\n", count2, ln2);

		/* set poiner to space character */
		curr_pos2 = next_spc_position(ln2);
		if (curr_pos2 == 0) {
			break;
		}
		/* set pointer to character next to space (next word) */
		ln2 += curr_pos2 + 1;
	}
	printf("---\n");
}

