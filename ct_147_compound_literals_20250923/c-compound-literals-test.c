/*
 * filename: c-compound-literals-test.c
 * 20250923 v2 d
 * last: 20250923
 */
#include <stdio.h>
#include <string.h>

#define START 48
#define END  127

typedef struct point {
	int x;
	int y;
} point_t;

void print_point_ptr(point_t *);
void print_point(point_t);

int main(int argc, char **argv) {

	/* compound literal test 1:
	for (int i = START; i < END; ++i) {
		printf("char at %3d:            %c\n", i, i);
		printf("char at %3d as string: \"%s\"\n", i, (char[]) {i, '\0'});
		//                                                   +________________+
		//                                                    compound literal
	}
	*/

	/* v2 */
	/* compound literal test 1: */
	for (int i = START; i < END; ++i) {
		printf("char at %3d: %c (\"%s\", as str)\n", i, i, (char[]) {i, '\0'});
		//                                                      +________________+
		//                                                        compound literal
	}

	/* compound literal test 2: */
	printf("\n---\nMy name: '%s'\n", (char[]){71, 114, 101, 103, 111, 114, 32, 82, 101, 100, 101, 108, 111, 110, 103, 104, 105, '\0'});
	//                                        G   r    e    g    o    r    _   R    e   d    e    l    o    n    g    h    i

	printf("---\n");

	/* compound literal test 3: */
	print_point_ptr(&(point_t){.x = 2, .y = 7});
	print_point((point_t){.x = 5, .y = -4});

	return 0;
}

void print_point_ptr(point_t *p) {
	printf("point: (%d, %d)\n", p->x, p->y);
}

void print_point(point_t p) {
	printf("point: (%d, %d)\n", p.x, p.y);
}

