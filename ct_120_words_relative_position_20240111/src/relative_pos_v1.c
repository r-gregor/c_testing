/*
 * relative_pos_v1.c
 * 20240111_01 (en)
 */
#include <stdio.h>
#include <string.h>

size_t next_spc_position(char *subline);
size_t words_count(char *line);

int main(void) {

	char line[] = "GREGOR REDELONGHI IN TADEJA MALI REDELONGHI";
	printf("line:         %s\n", line);
	printf("---\n");

	/* with for loop */
	size_t curr_pos = 0;
	size_t count = 0;
	char *ln = line;

	/* number of words in line */
	size_t words_cnt = words_count(line);

	for (int i = 0; i < words_cnt; ++i) {
		count++;
		printf("iteration %2.ld: %s\n", count, ln);

		/* set poiner to space character */
		curr_pos = next_spc_position(ln);
		if (curr_pos == 0) {
			break;
		}

		/* set pointer to character next to space (next word) */
		ln += curr_pos + 1;
	}
	printf("---\n");

	/* with while loop */
	size_t curr_pos2 = 0;
	size_t count2 = 0;
	char *ln2 = line;
	while(1) {
		count2++;
		printf("iteration %2.ld: %s\n", count2, ln2);

		/* set poiner to space character */
		curr_pos2 = next_spc_position(ln2);
		if (curr_pos2 == 0) {
			break;
		}
		/* set pointer to character next to space (next word) */
		ln2 += curr_pos2 + 1;
	}
	printf("---\n");

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

