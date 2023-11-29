#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **seznam;
int count;

int main(int argc, char **argv) {
	
	seznam = malloc(sizeof(char *) * 10);

	char *string1 = malloc(sizeof(char) * 20);
	char string2[] = "KuKU LeLE!";

	strcpy(string1, string2);

	printf("String string1: \"%s\"\n", string1);

	char *s3 = malloc(sizeof(char)* 20);
	strcpy(s3, "Gregor Redelonghi");

	char *s4 = malloc(sizeof(char)* 20);
	strcpy(s4, "Tadeja Mali Redelonghi");

	seznam[count++] = s3;
	seznam[count++] = s4;

	for (int i=0; i<count; i++) {
		printf("line %d: %s\n", i, *(seznam + i));
	}

	return 0;
}

