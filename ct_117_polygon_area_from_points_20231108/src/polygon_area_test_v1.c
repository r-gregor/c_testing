/*
 * polygon_area_testi_v1.c
 */
#include <stdio.h>
#include <string.h>

#define POINTS_NUM 4

typedef struct Point {
	int x;
	int y;
} Point;

typedef struct Polygon {
	int points_num;
	Point *points_arr;
} Polygon;

int polygon_area(Polygon *p);


/* MAIN */
int main(void) {

/* === RAW ================================== */
	int p_area;
	Point pt1 = {0,0};
	Point pt2 = {4,0};
	Point pt3 = {4,2};
	Point pt4 = {0,2};

	p_area = (
	            (pt1.x*pt2.y - pt1.y*pt2.x) +
	            (pt2.x*pt3.y - pt2.y*pt3.x) +
	            (pt3.x*pt4.y - pt3.y*pt4.x)
	        ) / 2;

	printf("Area of polygon p1 is:  %d (square)\n", p_area);


/* === USING FUNCTIONS ====================== */

	/* array of polygon points */
	Point square_points[] = {
	{0,0},
	{6,0},
	{6,2},
	{0,2}
	};

	Polygon p2;
	p2.points_num = sizeof(square_points) / sizeof(square_points[0]);
	p2.points_arr = square_points;

/*
	p2.points_arr[0].x = 0;
	p2.points_arr[0].y = 0;
	p2.points_arr[1].x = 6;
	p2.points_arr[1].y = 0;
	p2.points_arr[2].x = 6;
	p2.points_arr[2].y = 2;
	p2.points_arr[3].x = 0;
	p2.points_arr[3].y = 2;
*/

	printf("Area of polygon p2 is: %d (square)\n", polygon_area(&p2));

	return 0;
} // end MAIN


int polygon_area(Polygon *p) {
	int dsum = 0;

	for (int i=0; i < p->points_num - 1; i++) {
		dsum += (p->points_arr[i].x) * (p->points_arr[i+1].y) - (p->points_arr[i].y) * (p->points_arr[i+1].x);
	}

	return dsum / 2;
}

