#include <stdio.h>
#include <string.h>


int main(int argc, char **argv, char *envp[]) {

	int index = 0;

	while(envp[index] != 0) {
		printf("L-%03d: %s\n", index, envp[index]);
		index++;
	}

	printf("Number of ENVs: %d\n", index);

	return 0;
}
