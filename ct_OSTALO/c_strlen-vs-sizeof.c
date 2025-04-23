#include <stdio.h>
#include <string.h>

#define name "GREGOR REDELONGHI"

int main(void) {

	printf("Stringz in C:\n");
	printf("strlen(\"%s\") = %d\n", name, strlen(name)); // 6 + 10 chars + 1 space = 17 chars
	printf("sizeof(\"%s\") = %d -- (additional '\\0' character)\n", name, sizeof(name)); // additional '\0' char

	return 0;
}

