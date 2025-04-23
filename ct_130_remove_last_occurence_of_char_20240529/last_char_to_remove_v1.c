/*
 * last_char_to_remove_v1.c
 */
#include <stdio.h>
#include <string.h>

int main(void) {

	char *line = "Microsoft";
	size_t line_len = strlen(line);
	char new_line[line_len];
	memset(new_line, '\0', line_len);
	char to_remove = 'o';

	size_t pos = line_len - 1;
	while (line[pos] != to_remove) {
		pos--;
	}

	/* my solution */
	size_t i = 0;
	size_t j = 0;
	while(i < line_len) {
		if (i == pos) {
			i++;
		} else {
			new_line[j] = line[i];
			i++;
			j++;
		}
	}

#if 0
	/* from:  Remove Last Occurrence Of A Character From A String | C Programming Example | Portfolio Courses
	 *        https://www.youtube.com/watch?v=_3-R2l0mh7w
	 * NO NEED for new_line it updates the original itself, so have to  print original before the next
	 * loop ...
	 */
	if (pos >= 0) {
		while (pos < line_len) {
			line[pos] = line[pos + 1];
			pos++;
		}
	}
#endif

	printf("                                   Original:   \"%s\"\n", line);
	printf("             Index of last occurence of 'o':    %ld\n", pos);
	printf("     Original without last occurence of 'o':   \"%s\"\n", new_line);

	return 0;
}

