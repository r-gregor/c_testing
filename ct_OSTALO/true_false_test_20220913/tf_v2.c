#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/** v2 */
bool tf(char *);

int main(int argc, char **argv) {
	
	char ans[3];

	while(1) {
		printf("\nEnter YES or NO: (or q/Q to quit)  ");
		scanf("%s", ans);

		if (strcmp(ans, "q") == 0 || strcmp(ans, "Q") == 0)
			break;
		
		if (tf(ans)) {
			printf("TRUE ...\n");
			break;
		} else {
			printf("FALSE!\n");
		}
	}

	return 0;
}

bool tf(char *ans) {
	if (strcmp(ans, "YES") == 0)
		return true;
	else
		return false;
}

