#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int usage(char **);
void print_min_max(float, float, float);
float abs_vred(float vred);

float min_padec = 0.3/100.00;


/* MAIN */
int main(int argc, char **argv) {

if (argc != 4) {
	/*
	printf("Usage: %s <kota1> <kota2> <razdalja>\n\n", argv[0]);
	printf("\t<kota1>, <kota2>, <razdalja> ... format: XXX.XX\n\n");
	return -1;
	*/
	usage(argv);

}

/* strtof ?? */
float kota1  = atof(argv[1]);
float kota2  = atof(argv[2]);
float hrazd   = atof(argv[3]);
float vrazd  = kota1 - kota2;
float padec  = vrazd / hrazd;
float ppadec = padec * 100;


printf("Začetna točka: %.2f m\n", kota1);
printf("Končna točka:  %.2f m\n", kota2);
printf("Hori. razd:    %.2f m\n", hrazd);
printf("Vert. razd:    %.2f m\n", vrazd);
printf("Izračunani padec: %.2f %%\n", ppadec);

float abs_padec = abs_vred(padec);

if (abs_padec < min_padec) {
	printf("\n");
	printf("############################\n");
	printf("# Padec je manši of 0.3%% ! #\n");
	printf("############################\n\n");
	print_min_max(kota1, hrazd, min_padec);
	return 0;
}

print_min_max(kota1, hrazd, min_padec);

	return 0;
} /* end MAIN */


void print_min_max(float kota1, float hrazd, float padec) {
	float vrazd = hrazd * padec;
	printf("---------------------------------\n");
	printf("Potrebna končna višina mora biti\n");
	printf("večja kot:  %f m\n", kota1 + abs_vred(vrazd));
	printf("manjša kot: %f m\n", kota1 - abs_vred(vrazd));
}


int usage(char **argv) {
	printf("Usage: %s <kota1> <kota2> <razdalja>\n\n", argv[0]);
	printf("\t<kota1>, <kota2>, <razdalja> ... format: XXX.XX\n\n");
	return -1;
}

float abs_vred(float vred) {
	if(vred < 0) {
		return -1 * vred;
	} else {
		return vred;
	}
}

