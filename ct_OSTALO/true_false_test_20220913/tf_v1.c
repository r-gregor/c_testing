#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool tf(char *);

int main(int argc, char **argv) {
	
	char ans[3];

	printf("Enter YES or NO: \n");
	scanf("%s", ans);
	
	if (tf(ans)) {
		printf("TRUE ...\n");
	} else {
		printf("FALSE!\n");
	}

	return 0;
}

bool tf(char *ans) {
	if (strcmp(ans, "YES") == 0)
		return true;
	else
		return false;
}

