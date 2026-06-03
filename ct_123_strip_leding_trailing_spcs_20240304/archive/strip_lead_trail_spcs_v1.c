/* strip_lead_trail_spcs_v1.c
 * v1
 * 20240301_01 (en)
 */

#include <stdio.h>
#include <string.h>


char *remove_leading_spcs(char *line);

int main(void) {

	char *line1 = "   GREGOR REDELONGHI IN TADEJA REDELONGHI";
	char *reduced1  = NULL;

	printf("Original line1: \"%s\", number of characters: %ld\n", line1, strlen(line1));

	printf("\nRemoving leading spaces from line1:\n");
	reduced1 = remove_leading_spcs(line1);
	printf("Cleand line1: \"%s\", number of characters: %ld\n", reduced1, strlen(reduced1));

	return 0;
}

char *remove_leading_spcs(char *line) {
	char* first = NULL;
	if (*line == ' ') {
		while (*line == ' ') line++;
		first = line;
	} else {
		first = line;
	}
	return first;
}

