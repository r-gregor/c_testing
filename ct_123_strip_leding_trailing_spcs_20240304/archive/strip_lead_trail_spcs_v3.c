/* strip_lead_trail_spcs_v3.c
 * v3
 * 20240304_03 (en)
 */

#include <stdio.h>
#include <string.h>
// #include <stdlib.h>

void strip_leading_trailing_spcs(char *sourc, char* dest);
void strip_leading_trailing_spcs2(char sourc[], char* dest);
void pprnt(char *line);

int main(void) {

	printf("Space \" \" is denoted as \"~\" for better visibility.\n\n");
	char *line3 = "   GREGOR REDELONGHI in TADEJA MALI REDELONGHI           ";
	char *line4 = "   GREGOR REDELONGHI in TADEJA MALI REDELONGHI           ";

	printf("Original line3: ");
	pprnt(line3);
	printf("chars num:      %ld\n", strlen(line3));

	// char *reduced3 = malloc(256);
	char reduced3[256];
	printf("\nStripping leading and trailing spaces from line3:\n");
	strip_leading_trailing_spcs(line3, reduced3);

	printf("Cleand line3: ");
	pprnt(reduced3);
	printf("chars num:    %ld\n", strlen(reduced3));

	printf("\n---\n");

	printf("Original line4: ");
	pprnt(line4);
	printf("chars num:      %ld\n", strlen(line4));

	char reduced4[256];
	printf("\nStripping leading and trailing spaces from line4:\n");
	strip_leading_trailing_spcs2(line4, reduced4);

	printf("Cleand line4: ");
	pprnt(reduced4);
	printf("chars num:    %ld\n", strlen(reduced4));

	return 0;
}

void strip_leading_trailing_spcs(char *sourc, char* dest) {
	if (*sourc == ' ') {
		while (*sourc == ' ') sourc++;
	}

	strcpy(dest, sourc);
	int pos = strlen(dest) - 1;
	while (dest[pos] == ' ') {
		dest[pos] = '\0';
		pos--;
	}
}

void strip_leading_trailing_spcs2(char sourc[], char* dest) {
	if (*sourc == ' ') {
		while (*sourc == ' ') sourc++;
	}

	strcpy(dest, sourc);
	int pos = strlen(dest) - 1;
	while (dest[pos] == ' ') {
		dest[pos] = '\0';
		pos--;
	}
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
