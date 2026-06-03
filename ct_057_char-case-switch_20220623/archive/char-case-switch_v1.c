#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
 * v1
 */

char lower_to_upper(char);
char lower_to_upper_no_check(char);
void display_chars(char *);
void applay_lower_to_upper(char *);
void applay_lower_to_upper_no_check(char *);

int main(int argc, char **argv) {

	char *lowers = "abcdefghijklmnopqrstuvwxyz";
	char *lowers2 = "abCdefGhijklMnopQrstuvWxyZ";

	printf("Diff between 'a' and 'A' is: %d\n", 'A' - 'a');
	printf("---\n");
	
	applay_lower_to_upper(lowers);
	printf("---\n");

	printf("Applaying lower_to_upper_no_check() without checking if char is lower:\n");
	applay_lower_to_upper_no_check(lowers2);
	printf("---\n");


	printf("Applaying lower_to_upper():\n");
	applay_lower_to_upper(lowers2);
	printf("---\n");


	return 0;
}

char lower_to_upper_no_check(char lower_char) {
	return lower_char + ('A' - 'a');
}

char lower_to_upper(char lower_char) {
	if (islower(lower_char)) {
		return lower_char + ('A' - 'a');
	} else {
		return lower_char;
	}
}

void display_chars(char *string) {
	for (int i = 0; i < strlen(string) - 1; i++) {
		printf("%c, ", string[i]);
	}
	printf("%c\n", string[strlen(string) - 1]);
}

void applay_lower_to_upper(char *string) {
	printf("String chars BEFORE lower_to_upper() function use:\n");
	display_chars(string);
	printf("---\n");

	printf("String chars AFTER lower_to_upper() function use:\n");
	for (int i = 0; i < strlen(string) - 1; i++) {
		printf("%c, ", lower_to_upper(string[i]));
	}
	printf("%c\n", lower_to_upper(string[strlen(string) - 1]));
}

void applay_lower_to_upper_no_check(char *string) {
	printf("String chars BEFORE lower_to_upper_no_check() function use:\n");
	display_chars(string);
	printf("---\n");

	printf("String chars AFTER lower_to_upper_no_check() function use:\n");
	for (int i = 0; i < strlen(string) - 1; i++) {
		printf("%c, ", lower_to_upper_no_check(string[i]));
	}
	printf("%c\n", lower_to_upper_no_check(string[strlen(string) - 1]));
}

