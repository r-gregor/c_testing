#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_out(char **materials);

int main() {

	/* v1: an array of pointers with litteral asignment -- OK! */
	// char *materials[ ] = { "iron",  "copper", "gold"};

	/* v2: double char pointer with litteral asignment -- does NOT work!*/
	// char **materials = { "iron",  "copper", "gold"};

	/* v3: double char pointer with explicit asignment -- OK! */
	char **materials = malloc(sizeof(char *) * 3);
	materials[0] = "iron";
	materials[1] = "copper";
	materials[2] = "gold";

	print_out(materials);
	
	free(materials);
	return 0;
}


void print_out(char **materials) {

	printf("Please remember these materials :\n");
	int i ;
	for (i = 0; i < sizeof(materials); i++) {
		printf("%s\n", materials[i]);}
}

