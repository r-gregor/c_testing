#include <stdio.h>
#include <string.h>

int main () {
    
    char line[] = "c_substring_555555555555_test_20211123.txt";
    printf("String: \"%s\"\n", line);

    int substr_start = strlen(line)  - 12;

    char year[5];
    char month[3];
    char day[3];
    char tmstmp[11];

    strncpy(year, &line[substr_start], 4);
    year[4] = '\0';

    strncpy(month, &line[substr_start + 4], 2);
    month[2] = '\0';

    strncpy(day, &line[substr_start + 6], 2);
    day[2] = '\0';

    sprintf(tmstmp, "%s-%s-%s", year, month, day);

    printf("%s\n", tmstmp);
    
    return 0;
}

