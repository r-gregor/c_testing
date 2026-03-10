/*
 * fname: cinterface_test.c
 * 20260310 en v1
 * last: 20260310
 */
#include <stdio.h>
#include <string.h>
#include "datestamp.h"

typedef struct sensor_interface {
	const char *name;
	int (*read) (void);
} SensorInterface;

int st1_read_temp();
int sh1_read_humid();


/* main */
int main(int argc, char **argv) {

	SensorInterface st1 = {
		.name = "SENST1",
		.read = st1_read_temp
	};

	SensorInterface sh1 = {
		.name = "SENSH1",
		.read = sh1_read_humid
	};

	// char *dtstmp_str = get_datestamp();
	printf("Measurements (%s)\n", get_datestamp());
	printf("Temperature: %d°C\n", st1.read());
	printf("Humidity:    %d %%\n", sh1.read());

	printf("\n");
	return 0;
} /* end main */

/* functions */
int st1_read_temp() {return 25;}
int sh1_read_humid() {return 75;}

