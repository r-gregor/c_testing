#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

void snake_say(char *line, size_t len);

#define MAX_LINE_LEN 80

int main(int argc, char **argv) {

	if (argc != 2) {
		printf("You must supply a line of text between parenthesis!\n");
		return -1;
	}

	if (strlen(argv[1]) > MAX_LINE_LEN) {
		printf("Line of text must be up to %d characters!\n", MAX_LINE_LEN);
		return -1;
	}

	char line[MAX_LINE_LEN];
	strcpy(line, argv[1]);

	snake_say(line, strlen(line));

	return 0;
}


void snake_say(char *line, size_t len) {
	char *LAMBDA = "\u03BB";
	printf("\n\t ");
	printf(".");
	for (int i=0; i < len; i++) {
		printf("-");
	}
	printf(".");
	printf("\n");
	printf("\t( %s )\n", line);
	printf("\t ");
	printf("˙");
	for (int i=0; i < len; i++) {
		printf("-");
	}
	printf("˙");
	printf("\n");
	printf("\t     \\\n");
	printf("\t      \\\n");
	printf("\t       __\n");
	printf("\t      {oo}\n");
	printf("\t      (__)\\\n");
	printf("\t        %s \\\\\n", LAMBDA);
	printf("\t          _\\\\___\n");
	printf("\t         (______)_\n");
	printf("\t        (_________)Oo°\n");
	printf("\n");
}


