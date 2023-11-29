#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
 * v3
 * add each char without use of external function
 */

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
			// insert char at last position in string nums
			//
			// methodi1: with string subscripts
			// nums[strlen(nums)] = str1[f];
			//
			// method2: with pointer arithmetics
			*(nums + strlen(nums)) = *(str1 + f);
		}
		f++;
	}
	printf("\n");

	printf("Size of nums: %ld\n", strlen(nums));
	printf("nums: %s\n", nums);


	return 0;
}

