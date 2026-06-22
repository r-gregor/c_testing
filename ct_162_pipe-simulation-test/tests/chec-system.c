#include <stdio.h>
#include <string.h>



#if defined(WIN32) || defined(_WIN32) || defined(__WIN32)
char *system = "WINDOWS";
#else
char *system = "LINUX";
#endif

int main(int argc, char **argv) {

	printf("System: %s\n", system);


	return 0;
}
