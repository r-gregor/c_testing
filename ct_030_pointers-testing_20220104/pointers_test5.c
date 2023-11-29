#include <stdio.h>


int * multiplyByTwo(int *);

int main() {

	int i = 10;
	int *q;
	q = &i;

	int *z;

	printf("--- variables declaration---\n");
	printf("\tint i = %d;\n", i);
	printf("\tint *q;\n\tq = &i;\n");
	printf("\tint *z;\n");
	printf("\n--- function declaration ---\n");
	printf("\tint * multiplyByTwo(int *x) {*x *= 2; return x;}\n\n");

	printf("\n--- OUTPUT ---\n");
	printf("After multiplycaton by 2 i = %d\n", *(multiplyByTwo(&i)));
	printf("q = &i = %d\n", *q);

	z = multiplyByTwo(q);
	printf("z = multiplyByTwo(q);\n");
	printf("After multiplycaton by 2 z = %d\n", *z);
	printf("\n");

	return 0;
}


int * multiplyByTwo(int *x) {
	*x *= 2;
	return x;
}
