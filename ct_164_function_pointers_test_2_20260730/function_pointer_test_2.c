/*
 * fname: function_pointer_test_2.c
 * v1 20260730
 * v2 typedef a function pointer type
 * last: 20260730
 */

#include <stdio.h>
#include <string.h>

float add(float a, float b);
float sub(float a, float b);
float mult(float a, float b);
float div(float a, float b);
typedef float (*calculate_t)(float, float);

// v1
// without typedef:
// float get_result(float (*calculate_t)(float, float), float a, float b);

// v2
float get_result(calculate_t calc, float a, float b);

int main(int argc, char **argv) {

#if 1
	float a = 10.5f;
	float b = 2.2f;
#endif

#if 0
	float a = 10.5f;
	float b = 0.0f;
#endif

#if 0
	float a = 0.0f;
	float b = 2.2f;
#endif


	printf("a = %05.2f; b = %05.2f\n", a, b);
	printf("---\n");
	printf("%05.2f + %05.2f = %05.2f\n", a, b, get_result(&add, a, b));
	printf("%05.2f - %05.2f = %05.2f\n", a, b, get_result(&sub, a, b));
	printf("%05.2f x %05.2f = %05.2f\n", a, b, get_result(&mult, a, b));

	if (a == 0.0) {
		printf("[ERROR] dividing zero with %05.2f\n", b);
	} else if (b == 0.0) {
		printf("[ERROR] dividing with zero\n");
	} else {
		printf("%05.2f / %05.2f = %05.2f\n", a, b, get_result(&div, a, b));
	}

	printf("\n");
	return 0;
}

float add(float a, float b) {
	return a + b;
}

float sub(float a, float b) {
	return a - b;
}

float mult(float a, float b) {
	return a * b;
}

float div(float a, float b) {
	return a / b;
}

// v1
// float get_result(float (*calculate)(float, float), float a, float b) {

// v2
float get_result(calculate_t calc, float a, float b) {
	return calc(a, b);
}

