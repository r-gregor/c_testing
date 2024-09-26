/*
 * cm2feetinch_v2.c
 * 20240926
 * v2: cm ->  feet -> feet(') inch (")
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int feet;
	float inch;
} FeetInch;

void cm2feet_inch(float heigth_cm, FeetInch *heigth_fein);

int main(int argc, char **argv) {

	float heigth_cm;
	if (argc != 2) {
		heigth_cm = 185.0f;
	} else {
		heigth_cm = atoi(argv[1]);
	}


	FeetInch heigth_fein;
	cm2feet_inch(heigth_cm, &heigth_fein);
	printf("Višina %.2f cm: %d' %.0f\"\n", heigth_cm, heigth_fein.feet, heigth_fein.inch);

	return 0;
}


void cm2feet_inch(float heigth_cm, FeetInch *heigth_fein) {
	const float cm2foot = 30.48f;
	const float foot2inch = 12.0f;

	float total_feet = heigth_cm / cm2foot;
	float rest_inch = (total_feet - (int) total_feet) * foot2inch;

	heigth_fein->feet = (int) total_feet;
	heigth_fein->inch = rest_inch;
}

