#include <stdio.h>

void line();
int sum(int,int);
void show_values(int, int);
void local_values_change(int, int);
void permanent_values_change_pointers(int *, int *);

int main() {

	int x = 10;
	int y = 20;

	printf("No values change\n");
	printf("Sum of %d an %d is: %d\n", x, y, sum(x, y));
	show_values(x, y);

	line();
	printf("Local values change\n");
	local_values_change(x, y);
	printf("Sum of %d an %d is: %d\n", x, y, sum(x, y));
	show_values(x, y);
	
	line();
	printf("Permanent values change\n");
	permanent_values_change_pointers(&x, &y);
	printf("Sum of %d an %d is: %d\n", x, y, sum(x, y));
	show_values(x, y);
	
	return 0;
}

void line() {
	printf("--------------------------------------\n");
}

int sum(int a, int b) {
	return a + b;
}

void show_values(int a, int b) {
	printf("Original values: x = %d, y = %d\n", a, b);
}

void local_values_change(int a, int b) {
	a += 10;
	b += 20;
	printf("New values: x = %d, y = %d\n", a ,b);
}

void permanent_values_change_pointers(int *a, int *b) {
	*a += 30;
	*b += 50;
	printf("New values: x = %d, y = %d\n", *a ,*b);
}

