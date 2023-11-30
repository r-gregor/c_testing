#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* get_tmstmp(char *);
void display_line(char *);

int main () {
    
    char line[] = "c_substring_555555555555_test_20211123.txt";
    char line2[] = "jv_so-very-interesting-test_20220222.txt";

	display_line(line);
	display_line(line2);

    return 0;
}

char* get_tmstmp(char *string) {

    int substr_start = strlen(string)  - 12;

    char year[5];
    char month[3];
    char day[3];
    char *tmstmp = malloc(sizeof(char)*11);

    strncpy(year, &string[substr_start], 4);
    year[4] = '\0';

    strncpy(month, &string[substr_start + 4], 2);
    month[2] = '\0';

    strncpy(day, &string[substr_start + 6], 2);
    day[2] = '\0';

    sprintf(tmstmp, "%s-%s-%s", year, month, day);

    return tmstmp;
}

void display_line(char *string) {
	printf("%s\t%s\n", get_tmstmp(string), string);
}
