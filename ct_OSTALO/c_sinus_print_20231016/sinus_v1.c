/*
 * sinus_v1.c
 * from: My Program Sucks! [Tsoding Daily]
 *       https://www.youtube.com/watch?v=ivLIov6ta-8&list=PLpM-Dvs8t0Vak1rrE2NJn8XYEJ5M7-BqT&index=6
 */
#include <stdio.h>
#include <string.h>
#include <math.h>

#define N 30

float in[N];

int main(void) {
	float f = 1.0f; // frequency -- how many periodes
	for (size_t i = 0; i < N; ++i) {
		float t = (float)i/N;
		in[i] = sinf(2*M_PI*f*t);  // 2*PI -- sine wave of single periode
	}

#if 0
	/* v1
	 * print out numbers
	 */
	for (size_t i = 0; i < N; ++i) {
		printf("%f\n", in[i]);
	}
#endif

#if 0
	/* v2
	 * print out positive 1/2 
	 * it cuts off negative 1/2 
	 */
	for (size_t i = 0; i < N; ++i) {
		for (size_t j = 0; j < in[i]*N ; ++j) {
			printf("*");
		}
		printf("\n");
	}
#endif

#if 0
	/* v3
	 * print out entire periode:
	 * for second (inner) loop ad +1 to value so range from -1 to 1
	 * becomes range from 0 to 2, but then divide by 2 to get range from 0 to 1
	 */
	for (size_t i = 0; i < N; ++i) {
		for (size_t j = 0; j < (in[i] + 1)/2*N ; ++j) {
			printf("*");
		}
		printf("\n");
	}
#endif


#if 0
	/* v4
	 * like v3 but just print the '*' at the border
	 */
	for (size_t i = 0; i < N; ++i) {
		float t = (in[i] + 1)/2;
		for (size_t j = 0; j < t*N ; ++j) {
			printf(" ");
		}
		printf("*\n");
	}
#endif

#if 1
	/* v5
	 * repeate v4 inside loop
	 */
	for (size_t k = 0; k < 2; ++k) {
		for (size_t i = 0; i < N; ++i) {
			float t = (in[i] + 1)/2;
			for (size_t j = 0; j < t*N ; ++j) {
				printf(" ");
			}
			printf("*\n");
		}
	}
#endif

	return 0;
}

