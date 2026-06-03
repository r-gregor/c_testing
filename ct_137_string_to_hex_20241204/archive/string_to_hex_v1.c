/*
 * string_to_hex.c
 * v1: 20241202 en
 */
#include <stdio.h>
#include <string.h>


int main(int argc, char **argv) {

	char name[64]  = {0};
	
	if (argc == 2) {
		strcpy(name, argv[1]);
	} else {
		strcpy(name, "rgregor");
	}


	char *myname = name;
	size_t name_len = strlen(myname);

#if 0
	printf("name: %s\n", myname);
	for (int i = 0; i < name_len; i++) {
		char letter=myname[i];
		printf("%c: %d\t%x\n", letter, letter, letter);

	}
	printf("---\n");
#endif

	printf("'%s' in hex: ", myname);
	for (int i = 0; i < name_len; i++) {
		char letter=myname[i];
		printf("%x", letter);
	}
	printf("\n");

	return 0;
}
