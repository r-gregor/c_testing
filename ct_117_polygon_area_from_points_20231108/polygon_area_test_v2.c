/*
 * polygon_area_testi_v2.c
 * 20231108_01 (d)
 */
#include <stdio.h>
#include <string.h>

typedef struct Point {
	int x;
	int y;
} Point;

typedef struct Polygon {
	int points_num;
	Point *points_arr;
} Polygon;

int polygon_area(Polygon *p);
Polygon make_polygon(Point *points_arr, int points_num); // v2
void display_polygon_points(Polygon *p); // v2


/* MAIN */
int main(void) {

/* === RAW ================================== */

	printf("Calculating polygon area from points(vertices):\n\n");
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

	printf("Points: [(%d,%d), (%d,%d), (%d,%d), (%d,%d)]\n",
			pt1.x, pt1.y,
			pt2.x, pt2.y,
			pt3.x, pt3.y,
			pt4.x, pt4.y
			);
	printf("Area of polygon p1 is:  %d (square 4x2)\n---\n", p_area);


/* === USING FUNCTIONS ====================== */

	/* array of polygon points (counter-clock wise) */
	Point square_points[] = {
	{0,0},
	{6,0},
	{6,2},
	{0,2}
	};

	Polygon p2 = make_polygon(square_points, 4);
	display_polygon_points(&p2);
	printf("Area of polygon p2 is: %d (square 6x2)\n---\n", polygon_area(&p2));

	// ---

	/* array of polygon points (counter-clock wise) */
	Point triangle_points[] = {
		{0,0},
		{8,0},
		{8,8}
	};

	Polygon p3 = make_polygon(triangle_points, 3);
	display_polygon_points(&p3);
	printf("Area of polygon p3 is: %d (triangle 8/8)\n---\n", polygon_area(&p3));

	return 0;
} // end MAIN


int polygon_area(Polygon *p) {
	int dsum = 0;

	/*
	 * calculating polygon area from points p1(x1,y1), p2(x2,y2), ... pn(xn, yn):
	 * area = 1/2 * [(x1*y2 - y1*x2) + (x2*y3 - y2*x3) + ... + (xn-1*yn - yn-1*xn)]
	 * points must be indexed in counter-clock direction (walking along the border -> inner
	 * area is on the left)
	 * ---
	 *  for loop till points_num - 1, because of 'points_arr[i+1]'
	 */
	for (int i=0; i < p->points_num - 1; i++) {
		dsum += (p->points_arr[i].x) * (p->points_arr[i+1].y) - (p->points_arr[i].y) * (p->points_arr[i+1].x);
	}

	return dsum / 2;
}

/*
 * v2
 * TODO: get points and number of points from data structure
 *       supplied as argument to function
 */
Polygon make_polygon(Point *points_arr, int points_num) {
	Polygon p;
	p.points_num = points_num;
	p.points_arr = points_arr;

	return p;
}

/*
 * v2
 */
void display_polygon_points(Polygon *p) {
	printf("Points: [");
	for (int i=0; i < p->points_num - 1; ++i) {
		printf("(%d,%d), ", p->points_arr[i].x, p->points_arr[i].y);
	}
	printf("(%d,%d)]\n", p->points_arr[p->points_num - 1].x, p->points_arr[p->points_num - 1].y);
}

