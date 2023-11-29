/**
 * src/rectangle_info_v1.c
 * 20230605 /01 (en)
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct rect {
	float a;
	float b;
	float area;
	float perimeter;
	float sides_r;         // side a : side b ratio
	float ar_per_r;        // area : perimeter ratio
} Rect_t;

bool make_rectangle(Rect_t *rect, const float a, const float b);
void rectangle_info(Rect_t *rect);
void make_and_display_rectangle_info(float a, float b);

/** MAIN */
int main(int argc, char **argv) {

	int count = 0;
	float a = 7;
	float b = 4;
	while (count < 10) {
		make_and_display_rectangle_info(a, b);
		a += 3;
		b += 2;
		count++;
	}

	return 0;
} // END main


/* OK if always constructed from function */
bool make_rectangle(Rect_t *rect, const float a, const float b) {
	if (rect == NULL) {
		fprintf(stderr, "Could not create rectangle\n");
		return false;
	}

	rect->a = a;
	rect->b = b;
	rect->area      = rect->a * rect->b;
	rect->perimeter = 2 * (rect->a + rect->b);
	rect->sides_r   = rect->a / rect->b;
	rect->ar_per_r  = rect->area / rect->perimeter;
	return true;
}

void rectangle_info(Rect_t *rect) {
	printf("Rectangle is of size: %0.2fx%0.2f\n", rect->a, rect->b);
	printf("Area:      %-6.2f | ", rect->area);
	printf("a/b ratio:            %-6.2f\n", rect->sides_r);
	printf("Perimeter: %-6.2f | ", rect->perimeter);
	printf("area/perimeter ratio: %-6.2f\n", rect->ar_per_r);
	printf("---\n");
}

void make_and_display_rectangle_info(float a, float b) {
	Rect_t rct;
	make_rectangle(&rct, a, b);
	rectangle_info(&rct);
}

