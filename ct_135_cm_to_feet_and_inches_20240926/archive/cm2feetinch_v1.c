/*
 * cm2feetinch_v1.c
 * 20240926
 * v1: cm -> inch -> feet(') inch (")
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
	const float foot2inch = 12.0f;
	const float inch2cm =  2.54f;

	float total_inch = heigth_cm / inch2cm;
	float feetf = total_inch / foot2inch;
	float rest_inch = total_inch - ((int)feetf * 12);

	heigth_fein->feet = (int) feetf;
	heigth_fein->inch = rest_inch;
}

