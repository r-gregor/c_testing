/* strip_lead_trail_spcs_v4.c
 * v4
 * 20240304_04 (en)
 */

#include <stdio.h>
#include <string.h>

char *strip_leading_trailing_spcs3(char *source);
void pprnt(char *line);

int main(void) {

	printf("Space \" \" is denoted as \"~\" for better visibility.\n\n");
	char *line4 = "   GREGOR REDELONGHI in TADEJA MALI REDELONGHI           ";

	printf("Original line4: ");
	pprnt(line4);
	printf("chars num:      %ld\n", strlen(line4));

	char *reduced4 = NULL;
	printf("\nStripping leading and trailing spaces from line4:\n");
	reduced4 = strip_leading_trailing_spcs3(line4);

	printf("Cleand line4: ");
	pprnt(reduced4);
	printf("chars num:    %ld\n", strlen(reduced4));

	return 0;
}

char *strip_leading_trailing_spcs3(char *source) {
	static char dest[256];
	if (*source == ' ') {
		while (*source == ' ') source++;
	}

	/* instead of strcpy() */
	char *result = dest;
	while (*source != '\0') {
		*result++ = *source++;
	}

	int pos = strlen(dest) - 1;
	while (dest[pos] == ' ') {
		dest[pos] = '\0';
		pos--;
	}

	return dest;
}

void pprnt(char *line) {
	printf("\"");
	while(*line != '\0') {
		if (*line == ' ') {
			printf("~");
		} else {
			printf("%c", *line);
		}
		line++;
	}
	printf("\"\n");
}

