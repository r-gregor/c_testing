#include <stdio.h>
#include <string.h>


char digit_to_hex_char(int);

int main() {

	printf("Litteral: ");
	printf(	"Printing this line means that,"
			" you cannot rely on the things"
			" [T]hey put into their perspective!"
			"\n"
			"\n");

	char line[255] = {"This otiginal is appended + "};
	strcat(line, "Printing this line means that,"
			" you cannot rely on the things"
			" [T]hey put into their perspective!"
			"\n"
			"\n");
	printf("%s", line);


	char line2[255] = {"This line will be overwritten!\n"};
	printf("%s", line2);
	sprintf(line2, "Printing this line means that,"
			" you cannot rely on the things"
			" [T]hey put into their perspective!"
			"\n"
			"\n");
	printf("%s", line2);

	char *str2;
	str2 = "Hello there. This string has been assigned directly to a pointer.\n";
	printf("%s\n", str2);

	char *str3 = "Hello there again. This string has also been assigned directly to a pointer.\n";
	printf("%s\n", str3);

	printf("Function that converts a char (0 - 15) to hex digit:\n");
	printf("char digit_to_hex_char(int digit) {return \"0123456789ABVDEF\"[digit]} //string literal subscript!!\n");
	printf("hex char of digit 11 = %c\n", digit_to_hex_char(11));


	printf("\nFrom EN (20220110):\n");

	int n = 1024;
	float f = 3.1415926;
	char name[] = "Gregor Redelonghi";
	char sentence[strlen(name) + sizeof(int) + sizeof(float) + 1];
	sprintf(sentence, "Name: %s, num1: %d, num2: %.3f", name, n, f);

	printf("Sentence: \"%s\"\n", sentence);
	printf("Length of sentence: %ld\n", strlen(sentence));

	return 0;
}


char digit_to_hex_char(int digit) {
	return "0123456789ABVDEF"[digit];
}

