#include <stdio.h>
#include <string.h>

#define MAX_LINES 5
#define MAX_LINE_LENGTH 200


void display_tokens(char *line);
char lines[MAX_LINES][MAX_LINE_LENGTH];

int main() {

	char lines[MAX_LINES][MAX_LINE_LENGTH] = {
		"Date,Expl1,Expl2,Num,Whatever",
		"2021/11/04,\"Gregor Redelonghi\",\"Valvasorjeva ulic 5\",196.65,Hello you!",
		"2021/01/01,Some cool stuf,\"Jada jada jada ...\",105800,Not MY problem",
		"2022/02/02,Jaba'dHut,Little Yoda,805,Nan",
		"2021/12/31,Happy New Year!,Welcome,1,You are FIRST!"
	};

	for (int i=0; i < MAX_LINES; i++) {
		display_tokens(lines[i]);
	}
	
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

