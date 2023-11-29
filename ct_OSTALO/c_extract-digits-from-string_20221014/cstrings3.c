#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	char str1[] = "999 aaa BBB 12345678";
	printf("String: \"%s\"\n", str1);
	printf("String size: %ld chars.\n", strlen(str1));

	/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
	// Add digits to "nums" string
	int f = 0;
	char nums[20] = "";
	while (str1[f] != '\0') {
		if (isdigit((int) str1[f])) {
			// convert char to string for strcat:
			char curchar = str1[f]; 
			// strcat doesnt work, must be strncat!!
			strncat(nums, &curchar, 1);
		}
		f++;
	}
	printf("\n");

	printf("Size of nums: %ld\n", strlen(nums));
	printf("nums: %s\n", nums);


	return 0;
}

