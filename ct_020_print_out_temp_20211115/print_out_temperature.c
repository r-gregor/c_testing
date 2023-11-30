#include <stdio.h>
#include <stdlib.h>


void usage(char *arg);

int main(int argc, char **argv) {

	if (argc != 2) {
		usage(argv[0]);
	}
	
	printf("The temperature is %.2f°C\n", atof(argv[1]));


	return 0;
}



void usage(char *arg) {
	printf("\n\tUsage:\t%s <temperature [float]>\n\n", arg);
	exit(1);
}

