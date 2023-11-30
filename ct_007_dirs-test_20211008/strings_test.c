#include <stdio.h>
#include <string.h>

int main(void) {
	const char *name = "Gregor Redelonghi";
	printf("The string: \"%s\"\n", name);

	/* strlen() */
	printf("The num of chars in string using 'strlen()': %d\n", strlen(name));

	/* while loop */
	int str_len = 0;
	while (name[str_len] != 0x00) {
		str_len++;
	}
	printf("The num of chars in string using 'while loop': %d\n", str_len);

	
	return 0;
}

