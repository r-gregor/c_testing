#include <stdio.h>
#include <string.h>
#include <math.h>

#define SCREENW 100

void percent_bar(double percent, char *symbol);

int main(int argc, char **argv) {

	// unicod table:
	// https://www.tamasoft.co.jp/en/general-info/unicode.html
	// EVEN BETTER: https://graphemica.com/unicode/characters/page/6
	printf("%s\n", "\u00AE"); // 00A0 + 0E = 00AE
	printf("%s\n", "\u03F4"); // 03E0 + 14 = 03F4
	printf("%s\n", "\u07F7"); // 07E0 + 17 = 07F7
	printf("%s\n", "\u102A"); // 1020 + 0A = 102A
	printf("%s\n", "\u26FA"); // 26E0 + 1A = 26FA
	printf("%s\n", "\u2A0C"); // 2A00 + 0C = 2A0C
	printf("\n");

	printf("  1 %% bar: ");
	percent_bar(1.0, "\u2592");

	printf(" 80 %% bar: ");
	percent_bar(80.0, "\u2591");

	printf(" 50 %% bar: ");
	percent_bar(50.0, "\u2593");

	printf(" 99 %% bar: ");
	percent_bar(99.0, "\u2589");

	printf("100 %% bar: ");
	percent_bar(100.0, "\u2592");

	printf(" 75 %% bar: ");
	percent_bar(75.0, "\u2573");

	printf(" 35 %% bar: ");
	percent_bar(35.0, "#");



	return 0;
}

void percent_bar(double percent, char *symbol) {
	int num;
	num = floor(round((percent / 100.0) * SCREENW));
	int rest = SCREENW - num;
	printf("[");
	for (int i = 0; i < num; i++) {
		printf("%s", symbol);
	}
	for (int k=0; k < rest; k++) {
		// printf(".");
		// printf(" ");
		// printf("\u2810");
		printf("\u00B7");
	}
	printf("]");
	printf("\n");
}

