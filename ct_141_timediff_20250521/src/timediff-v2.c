/* 
 * filename: timediff-v2.c
 * 20250522 v1 en
 * 20250522 v2 en: move all time string and number parts into single struct
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct Time_str {
	int H;
	int M;
	int S;
	char time[9];
	int total_s;
} Time_str;

bool is_not_number(char *T);
int get_secs_in_h(int Th);
int get_secs_in_m(int Tm);
int get_secs(int Ts);
void make_time(Time_str *tmi, char *T);

int sih = 60 * 60;   /* seconds in hour */
int sim = 60;        /* seconds in minute */
int sid = 24*60*60;  /* seconds in day */

int main(int argc, char **argv) {

	char *T1 = "060000";
	char *T2 = "153333";

	Time_str start = {0};
	Time_str end = {0};
	make_time(&start, T1);
	make_time(&end, T2);


	if (is_not_number(T1)) {
		printf("[ERROR] Argument must be a number in format HHMMSS (example: 120533)\n");
		return -1;
	}

	if (is_not_number(T2)) {
		printf("[ERROR] Argument must be a number in format HHMMSS (example: 120533)\n");
		return -1;
	}

	if (atoi(T2) - atoi(T1) <= 0) {
		printf("[ERROR] Time difference to small (under 1 sec, or negative)\n");
		return -1;
	}

	int totals = end.total_s - start.total_s;

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

	printf("Start time: %s\n", start.time);
	printf("End time:   %s\n", end.time);
	printf("Time difference: %d seconds (%d hours, %d minutes and %d seconds)\n", totals, dh, dm, ds);
	printf("Time difference: %02d:%02d:%02d\n", dh, dm, ds);

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
		exit(-1);
	}
	return Th * sih;
}

int get_secs_in_m(int Tm) {
	if (Tm > 59) {
		printf("[ERROR] Minutes part (%d) is greater than 59 minutes\n", Tm);
		exit(-1);
	}
	return Tm * sim;
}

int get_secs(int Ts) {
	if (Ts > 59) {
		printf("[ERROR] Seconds part (%d) is greater than 59 seconds\n", Ts);
		exit(-1);
	}
	return Ts;
}

void make_time(Time_str *tm, char *T) {
	char Th[3] = {0};
	char Tm[3] = {0};
	char Ts[3] = {0};

	strncpy(Th, T, 2);
	strncpy(Tm, T + 2, 2);
	strncpy(Ts, T + 4, 2);

	sprintf(tm->time, "%s:%s:%s", Th, Tm, Ts);
	tm->time[8] = '\0';

	tm->H = get_secs_in_h(atoi(Th));
	tm->M = get_secs_in_m(atoi(Tm));
	tm->S = get_secs(atoi(Ts));
	tm->total_s = tm->H + tm->M + tm->S;
}

