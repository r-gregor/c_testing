#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void make_tmstmp(char *, char *);
void display_line(char *, char *);

int main () {
    
    char line1[] = "c_substring_555555555555_test_20211123.txt";
    char line2[] = "jv_so-very-interesting-test_20220222.txt";

    char tms[11];

	display_line(tms, line1);
	display_line(tms, line2);

    return 0;
}

void make_tmstmp(char *string, char *tmstmp) {

    int substr_start = strlen(string)  - 12;

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


void display_line(char *tms, char *line) {
	make_tmstmp(line, tms);
    printf("%s\t%s\n", tms, line);
}
