#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINES 15

char **seznam;
int count;

void addToArray(char *);

int main(int argc, char **argv) {
	
	seznam = malloc(sizeof(char *) * MAX_LINES);

	addToArray("Gregor Redelonghi");
	addToArray("Tadeja Mali Redelonghi");
	addToArray("Zala Redelonghi");
	addToArray("Mark Redelonghi");
	addToArray("Špela Redelonghi");
	addToArray("Sisi Redelonghi");

	for (int i = count; i < count+10; i++) {
		if (count >= MAX_LINES) {
			printf("Sorry. Can't write past %d lines.\n", MAX_LINES);
			break;
		}
		addToArray("Phony Name Test ...");
	}

	printf("\nDisplaying Array contents.\n");
 	for (int i=0; i<count; i++) {
		printf("line%3d: %s\n", i, *(seznam + i));
	}

	return 0;
}

void addToArray(char *name) {
	seznam[count++] = name;
}

