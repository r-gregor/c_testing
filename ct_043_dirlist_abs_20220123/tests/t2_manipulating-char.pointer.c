#include <stdio.h>
#include <stdlib.h>

int num2 = 2;

int main(int argc, char **argv) {

	char *line1 = "0123456789";
	printf("line1:        %15s\n", line1);
	printf("initial num2: %15d\n", num2);

	printf("\nLoop:\n");
	int j = 0;
	while(line1[j] != '\0') {
		printf("Char line1[%d]: %c\n", j, line1[j]);
		printf("num2: %d\n", num2);
		num2++;
		j++;
	}


	return 0;
}

