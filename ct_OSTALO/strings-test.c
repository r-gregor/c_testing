#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LENGTH 8

/* Draw a line of "-" n-chars long */
void crt(int n) {
    for (int j = 0; j<n; j++) {
        printf("-");
    }
    printf("\n");
}

/* Print all digits in a string */
void get_digits(char *str) {
    printf("Full string: \"%s\"\n", str);
    printf("Nums only: ");
    for (int i=0; i < strlen(str); i++) {
        if (isdigit(str[i])) {
            printf("%c", str[i]);
        }
    }
    printf("\n");
}


int main() {

    crt(80); // ---------------------------------
    get_digits("Sam mal 2, pa še mal 300 in potem še 1500. No pa je konc 456789.");
    crt(80); // ---------------------------------
    get_digits("20210222 12345678 332255");
    crt(80); // ---------------------------------
    get_digits("c_file_to extract_last_18_digits_20210222.txt");
    crt(80); // ---------------------------------


    
    return 0;
}


