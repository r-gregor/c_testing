#include <stdio.h>
#include <string.h>

typedef char * string;

int main(int argc, char **argv) {

	string name ="Gregor Redelonghi";
	printf("%s\n", name);
	printf("Strings' adress: %p\n", &name);

	printf("sizeof(string) -- pointer to char memory: %ld\n", sizeof(string));

	return 0;
}
