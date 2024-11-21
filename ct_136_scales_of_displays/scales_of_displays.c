/*
 * scales_of_displays.c
 * 20241107_01 -- en
 */

#include <stdio.h>
#include <string.h>

char *get_name(float V);

int main(void) {

	printf("\nFactor  Horizontal  Vertical    Name\n");
	printf(  "------------------------------------\n");

	const float N1[] = {1.0, 1.5, 2.0, 2.5, 3.0, 4.0, 5.0, 6.0};
	const size_t N1_len = sizeof(N1) / sizeof(N1[0]);
	const float V =  720.0;
	const float H = 1280.0;

	for (size_t i=0; i < N1_len; i++) {
		float V1 = V * N1[i];
		float H1 = H * N1[i];
		char *NM = get_name(V1);
		printf("%0.1f   %12.0f   %7.0f  %6s\n", N1[i], H1, V1, NM);
	}

	return 0;
}

char *get_name(float V) {
	switch((int)V) {
		case 720:
			return "HD";
			break;

		case 1080:
			return"FHD";
			break;

		case 1440:
			return"QHD";
			break;

		case 2160:
			return "UHD/4K";
			break;

		case 4320:
			return "8K";
			break;

		default:
			return "";
			break;
	}
}
