// str_test.c

#include <stdio.h>
#include <string.h>

char *get_string();

int main(void) {

	char *out;
	out = get_string();
	printf("Result of get_string(): \"%s\"\n", out);
	for (int i=0; i < 20; i++) {
		char c = *(out + i);
		if (c == '\0' || c == ' ') {
			printf("%c", '.');
		} else {
			printf("%c",c);
		}

	}
	printf("\n");


	return 0;
}

char *get_string() {
	static char __str[20] = {0};
	sprintf(__str, "%s %s", "Gregor", "Redelonghi GGGGGGGGGGGGGGGGGGGGGGG");
	// sprintf(__str, "%s %s", "Gregor", "Redelonghi");
	return __str;
}

