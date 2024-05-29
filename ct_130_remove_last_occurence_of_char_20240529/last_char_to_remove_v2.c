/*
 * last_char_to_remove_v2.c
 * put remove logic into function
 */
#include <stdio.h>
#include <string.h>

size_t remove_last_occ(char *line, char to_remove);

int main(void) {

	char line[] = "Microsoft";
	char to_remove = 'o';
	printf("%45s   \"%s\"\n", "Original:", line);
	size_t pos = remove_last_occ(line, to_remove);
	printf("%40s '%c':    %ld\n","Index of last occurence of",to_remove, pos);
	printf("%40s '%c':   \"%s\"\n", "Original without last occurence of",to_remove, line);

	return 0;
}

size_t remove_last_occ(char *line, char to_remove) {
	size_t line_len = strlen(line);

	size_t pos = line_len - 1;
	while (line[pos] != to_remove) {
		pos--;
	}

	size_t result = pos;

	if (pos >= 0) {
		while (pos < line_len) {
			line[pos] = line[pos + 1];
			pos++;
		}
	}

	return result;
}

