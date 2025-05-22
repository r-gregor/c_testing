/* 
 * filename: timediff-v1.c
 * 20250522 v1 en
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool is_not_number(char *T);
int get_secs_in_h(int Th);
int get_secs_in_m(int Tm);
int get_secs(int Ts);

int sih = 60 * 60;   /* seconds in hour */
int sim = 60;        /* seconds in minute */
int sid = 24*60*60;  /* seconds in day */

int main(int argc, char **argv) {

	char *T1 = "000000";
	char *T2 = "24959";

	if (is_not_number(T1)) {
		printf("[ERROR] Argument must be a number in format HHMMSS (example: 120533)\n");
		return -1;
	}

	if (is_not_number(T2)) {
		printf("[ERROR] Argument must be a number in format HHMMSS (example: 120533)\n");
		return -1;
	}

	char T1h[3] = {0};
	char T1m[3] = {0};
	char T1s[3] = {0};

	char T2h[3] = {0};
	char T2m[3] = {0};
	char T2s[3] = {0};

	strncpy(T1h, T1, 2);
	strncpy(T1m, T1 + 2, 2);
	strncpy(T1s, T1 + 4, 2);

	strncpy(T2h, T2, 2);
	strncpy(T2m, T2 + 2, 2);
	strncpy(T2s, T2 + 4, 2);

	if (atol(T2) - atol(T1) <= 0) {
		printf("[ERROR] Time difference to small (under 1 sec, or negative)\n");
		return -1;
	}

	int T1ts = get_secs_in_h(atoi(T1h)) + get_secs_in_m(atoi(T1m)) + get_secs(atoi(T1s));
	int T2ts = get_secs_in_h(atoi(T2h)) + get_secs_in_m(atoi(T2m)) + get_secs(atoi(T2s));
	int totals = T2ts - T1ts;

	if (totals >= sid) {
		printf("[ERROR] Time difference to big (over one day)\n");
		return -1;
	}


	div_t pass1 = div(totals, 60);
	int dm = pass1.quot;
	int ds = pass1.rem;

	div_t pass2 = div(dm, 60);
	int dh = pass2.quot;
	dm = pass2.rem;

	printf("The difference is: %d seconds (%d hours, %d minutes and %d seconds)\n", totals, dh, dm, ds);
	printf("The difference is: %02d:%02d:%02d\n", dh, dm, ds);

	return 0;
}

bool is_not_number(char *T) {
	for (int i = 0; i < strlen(T); ++i) {
		if (isdigit((int)T[i]) == 0) {
			return true;
		}
	}
	return false;
}

int get_secs_in_h(int Th) {
	if (Th > 23) {
		printf("[ERROR] Hours part (%d) is greater than 23 hours\n", Th);
		return -1;
	}
	return Th * sih;
}

int get_secs_in_m(int Tm) {
	if (Tm > 59) {
		printf("[ERROR] Minutes part (%d) is greater than 59 minutes\n", Tm);
		return -1;
	}
	return Tm * sim;
}

int get_secs(int Ts) {
	if (Ts > 59) {
		printf("[ERROR] Seconds part (%d) is greater than 59 seconds\n", Ts);
		return -1;
	}
	return Ts;
}

