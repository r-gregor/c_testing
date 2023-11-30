#include <stdio.h>


int main() {

	int i = 20;
	int *p = &i;
	
	printf("Declarations:\n");
	printf("int i = 20;\nint *p = &i;\n");
	printf("------------------------------------\n");
	printf("i = %d\n", i);
	printf("p = %p\n", p);
	printf("*p = %d\n", *p);
	printf("*(&i) = %d\n", *(&i));


	return 0;
}
