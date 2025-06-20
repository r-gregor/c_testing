/* filename: test-strings-associated-with-enum-constnts.c
 * 20250620 v1 en
 */

#include <stdio.h>
#include <string.h>


int main(int argc, char **argv) {

	// Character names can be associated with enumeration constants
	// using arrays with designators:
	enum { RED, GREEN, BLUE };
	const char *nm[] = {
		[RED] = "red",
		[GREEN] = "green",
		[BLUE] = "blue",
	};

	enum {MUC, MAMI, OCI, SIN, HCI1, HCI2};

	const char *fmem[] = {
		[OCI]  = "Gregor Redelonghi",
		[SIN]  = "Mark Redellonghi",
		[MAMI] = "Tadeja Mali Redelonghi",
		[HCI2] = "Špela Redelonghi",
		[HCI1] = "Zala Redelonghi",
		[MUC]  = "Sisi"
	};


	printf("The grass is %s.\n", nm[GREEN]);

	printf("Oči:   %s.\n", fmem[OCI]);
	printf("Mamai: %s.\n", fmem[MAMI]);
	printf("Hči 1: %s.\n", fmem[HCI1]);
	printf("Hči 2: %s.\n", fmem[HCI2]);
	printf("Sin:   %s.\n", fmem[SIN]);
	printf("Mačka: %s.\n", fmem[MUC]);


	return 0;
}
