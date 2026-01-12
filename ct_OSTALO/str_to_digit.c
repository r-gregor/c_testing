#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
     
int main(void) {
    char *str = "programmin_garticles_20220222/-", *p = str;
    while (*p) {
        if (isdigit(*p)) {
            long val = strtol(p, &p, 10);
            printf("%ld\n", val);
        } else {
            p++;
        }
    }
    return 0;
}