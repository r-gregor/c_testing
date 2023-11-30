#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void make_tmstmp(char *, char *);
void display_line(char *);

int main () {
    
	char *lines[] = {
	"c_substring_555555555555_test_20211123.txt",
    "jv_so-very-interesting-test_20220222.txt",
    "c_line-1-test_20210222.txt",
    "c_line2-test_20230112.txt",
    "c_line_3_test_19680222.txt",
	};

	#define arr_elements (sizeof(lines) / sizeof(char*))

	for (int i = 0; i < arr_elements; i++) {
		display_line(lines[i]);
	}

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


void display_line(char *line) {
    char tms[11];
	make_tmstmp(line, tms);
    printf("%s\t%s\n", tms, line);
}

