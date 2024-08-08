 #include <stdio.h>
#include <string.h>


int main(void) {

	// char *fname = "Gregor Redelonghi, Valvasorjeva ulica 5, 1000 Ljubljana";
	char fname[] = "Gregor Redelonghi, Valvasorjeva ulica 5, 1000 Ljubljana";
	int len = strlen(fname);

	char *pos = fname + 8;

	printf("%-20s'%*s'\n","Original:", len, fname);
	printf("%-20s'%*s'\n","Changed:", len, pos);
	printf("%-20s'%*s'\n","Changed:", len, pos + 3);

	return 0;
}

