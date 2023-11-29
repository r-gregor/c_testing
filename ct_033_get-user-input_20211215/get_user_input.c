#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LNGHT 256

int main(int argc, char **argv) {
	
	char *str = malloc(sizeof(char *) * MAX_LINE_LNGHT);
	char *multiwordstr = malloc(sizeof(char *) * MAX_LINE_LNGHT);
	int num;
	char temp; /* needed to clear the buffer after getting an int */


	printf("Get user input using 'scanf()'\n");
	printf("Enter text (single word) and an integer: ");
	scanf("%s %d", str, &num);

	/* clearing the buffer after getting an integer */
	scanf("%c", &temp);
	printf("Enter text (multiple words and numbers): ");
	scanf("%[^\n]", multiwordstr);
	printf("\n");

	printf("Line-1: \"%s, %d\"\n", str, num);
	printf("Line-2: \"%s\"\n", multiwordstr);

	printf("\n");
	printf("Get user input using 'fgets()'\n");

	/* clearing the buffer after getting an integer */
	scanf("%c", &temp);
	printf("Enter text (multiple words and numbers / 2): ");
	fgets(multiwordstr, MAX_LINE_LNGHT, stdin);

	/* removing a newline (\n) at the end of string from user input */
	multiwordstr[strlen(multiwordstr)-1] = '\0';
	printf("Line-3: \"%s\"\n", multiwordstr);

	free(str);
	free(multiwordstr);

	return 0;
}

