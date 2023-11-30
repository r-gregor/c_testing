#include <stdio.h>
#include <string.h>
#include <ctype.h> // needed for isidigit()


/* Draw a line of "-" n-chars long */
void crt(int n) {
    for (int j = 0; j<n; j++) {
        printf("-");
    }
    printf("\n");
}

int has_8_digits(char *str) {
    int digit_count = 0;
    for (int i=0; i < strlen(str); i++ ) {
        if isdigit(str[i]) {
            digit_count++;
        }
    }
    printf("digit_count: %d\n", digit_count);
    if (digit_count == 8) {
        return 1;
    } else {
        return 0;
    }
}

void it_has_8digits(char *str) {
    printf("String: \"%s\"\n", str);
    if (has_8_digits(str)) {
        printf("YES, it contains 8 digits!\n");
    } else {
        printf("NO, It does not contain 8 digits.\n");
    }
}

int positive = 1;
int negative = 0;

void my_test(int NUM) {
    printf("%s", (NUM) ? "True\n" : "False\n");
}

int main() {


    crt(80); // --------------------
    char mys[] = "This string contains only four digits: 1234.";
    it_has_8digits(mys);
    
    crt(80); // --------------------
    char mys2[] = "This string contains eight digits: 12345678.";
    it_has_8digits(mys2);

    crt(80); // --------------------
    char mys3[] = "This string contains ten digits: 0123456789.";
    it_has_8digits(mys3);

    crt(80); // --------------------

    my_test(positive);
    my_test(negative);
    
    return 0;
}