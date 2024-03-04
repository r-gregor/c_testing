/* strip_lead_trail_spcs_v2.c
 * v2
 * 20240304_02 (en)
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *remove_leading_spcs(char *line);
char *remove_trailing_spcs(char *line, char *result2);

int main(void) {

	char *line1 = "   GREGOR REDELONGHI IN TADEJA REDELONGHI";
	char *line2 = "GREGOR REDELONGHI IN TADEJA REDELONGHI           ";
	char *line3 = "   GREGOR REDELONGHI IN TADEJA REDELONGHI           ";

	printf("Original line1: \"%s\", number of characters: %ld\n", line1, strlen(line1));
	printf("Original line2: \"%s\", number of characters: %ld\n", line2, strlen(line2));
	printf("Original line3: \"%s\", number of characters: %ld\n", line3, strlen(line3));

	char *reduced1 = NULL;
	printf("\nRemoving leading spaces from line1:\n");
	reduced1 = remove_leading_spcs(line1);
	printf("Cleand line1: \"%s\", number of characters: %ld\n", reduced1, strlen(reduced1));



	char *reduced2 = malloc(256);
	printf("\nRemoving trailing spaces from line2:\n");
	remove_trailing_spcs(line2, reduced2);
	printf("Cleand line2: \"%s\", number of characters: %ld\n", reduced2, strlen(reduced2));

	return 0;
}

char *remove_leading_spcs(char *line) {
	char *first = NULL;
	if (*line == ' ') {
		while (*line == ' ') line++;
		first = line;
	} else {
		first = line;
	}
	return first;
}


char *remove_trailing_spcs(char *line, char *result2) {
	strcpy(result2, line);
	int pos = strlen(result2) - 1;
	while (result2[pos] == ' ') {
		result2[pos] = '\0';
		pos--;
	}
	return result2;
}

