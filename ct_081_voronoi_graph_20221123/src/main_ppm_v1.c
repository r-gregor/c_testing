/*
 * from:
 * https://github.com/tsoding/voronoi-opengl/blob/master/src/main_ppm.c
 * v1: up to 00:22:58
 *
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <limits.h>

#define WIDTH 800
#define HEIGHT 600

#define COLOR_WHITE  0xFFFFFFFF
#define COLOR_BLACK  0xFF000000
#define COLOR_RED    0xFF0000FF
#define COLOR_GREEN  0xFF00FF00
#define COLOR_BLUE   0xFFFF0000

#define OUTPUT_FILE_PATH "output_v1.ppm"

typedef uint32_t Color32;

static Color32 image[HEIGHT][WIDTH];

void fill_image(Color32 color) {
	printf("Writing COLOR bytes to image of %dx%d bytes\n", HEIGHT, WIDTH);
	for (size_t y = 0; y < HEIGHT; ++y) {
		for (size_t x = 0; x < WIDTH; ++x) {
			image[y][x] = color;
		}
	}
}

void save_image_as_ppm(const char *file_path) {
	FILE *f = fopen(file_path, "wb");
	if (f == NULL) {
		fprintf(stderr, "ERROR: could NOT write into file %s: %s\n", file_path, strerror(errno));
		exit(1);
	}
	fprintf(f, "P6\n%d %d 255\n", WIDTH, HEIGHT);
	for (size_t y = 0; y < HEIGHT; ++y) {
		for (size_t x = 0; x < WIDTH; ++x) {
			// 0xAABBGGRR
			uint32_t pixel = image[y][x];
			uint8_t bytes[3] = {
				(pixel&0x0000FF)>>8*0,
				(pixel&0x00FF00)>>8*1,
				(pixel&0xFF0000)>>8*2,
			};
			fwrite(bytes, sizeof(bytes), 1, f);
			assert(!ferror(f));
		}
	}

	int ret = fclose(f);
	assert(ret == 0);
	printf("Wrote image bytes to: \"%s\"\n", OUTPUT_FILE_PATH);  // addedbyme
}

int main(void) {
	fill_image(COLOR_RED);
	save_image_as_ppm(OUTPUT_FILE_PATH);
	return 0;
}

