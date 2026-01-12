#include <stdio.h>
#include <string.h>
#include <math.h>


int main(void) {

	double PI = atanf(1.0f) * 4.0;
	printf("double PI = math.atan(1.0f) * 4;\n");
	printf("PI = %.34lf\n", PI);
	
	/////////////////////////////////////////////////

	double PI2 = atan2f(1.0f, 1.0f) * 4.0;
	printf("double PI2 = math.atan2f(1.0f, 1.0f) * 4;\n");
	printf("PI2 = %.34lf\n", PI2);

	return 0;
}

/* OUTPUT
 * float PI = math.atan(1.0f) * 4;
 * PI = 3.141593
 */

