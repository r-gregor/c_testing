#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *date;
char *tms;

void make_tmstmp(char *, char *);

int main(void) {

	date = malloc(sizeof(char) * 9);
	tms = malloc(sizeof(char) * 11);

    strcpy(date, "20220126");

	make_tmstmp(date, tms);

	printf("tms: %s\n", tms);

	free(date);
	free(tms);

    return 0;
}


void make_tmstmp(char *string, char *tmstmp) {
    
	int substr_start = strlen(string) - 8;

    char year[5];
    char month[3];
    char day[3];

    strncpy(year, &string[substr_start], 4);
    year[4] = '\0';

    strncpy(month, &string[substr_start + 4], 2);
    month[2] = '\0';

    strncpy(day, &string[substr_start + 6], 2);
    day[2] = '\0';

    sprintf(tmstmp, "%s-%s-%s", year, month, day);
}

