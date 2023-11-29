/*
 * sinus_v2.c
 * from: My Program Sucks! [Tsoding Daily]
 *       https://www.youtube.com/watch?v=ivLIov6ta-8&list=PLpM-Dvs8t0Vak1rrE2NJn8XYEJ5M7-BqT&index=6
 */
#include <stdio.h>
#include <string.h>
#include <math.h>

#define N 30

float in[N];

int main(void) {
	for (size_t i = 0; i < N; ++i) {
		float t = (float)i/(N - 1);
		float hann = 0.5 - 0.5*cosf(2*M_PI*t);
		for (size_t j = 0; j < hann*N; ++j) {
			printf("*");
		}
		printf("\n");
	}

	/* early exit to test */
	return 0;


	for (size_t k = 0; k < 2; ++k) {
		for (size_t i = 0; i < N; ++i) {
			float t = (in[i] + 1)/2;
			for (size_t j = 0; j < t*N ; ++j) {
				printf(" ");
			}
			printf("*\n");
		}
	}

	return 0;
}

