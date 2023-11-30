#include <stdio.h>
#include <string.h>

void display_tokens(char *line);


int main() {
	char line[200] = "What, Am, I, doing, here?";
	char line2[200] = "2021/11/04,\"Gregor Redelonghi\", \"Valvasorjeva ulic 5\", 196.65, Hello you!";
	
	display_tokens(line);
	display_tokens(line2);


	return 0;
}


void display_tokens(char *line) {
	char *token;

	token = strtok(line, ",");

	while (token != NULL) {
		printf("%-25s", token);
		token = strtok(NULL, ",");
	}
	printf("\n");
}

