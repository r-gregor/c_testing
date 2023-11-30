#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STR_LEN 40

typedef struct Person {
	char name[STR_LEN];
	int age;
} Person;

void printAllChars(char *, int);
void printIfNotFreedOrNull(Person *);
void release_ptr(void **);

int main(int argc, char **argv) {

	Person *Oci = malloc(sizeof(Person));
	Person *copyOfOci = malloc(sizeof(Person));

	strcpy(Oci->name, "Gregor Redelonghi");
	Oci->age = 54;

	memcpy(copyOfOci, Oci, sizeof(Person));

	printf("Person Oči -> ");
	printIfNotFreedOrNull(Oci);

	printf("Copy of person Oči -> ");
	printIfNotFreedOrNull(copyOfOci);

	// free(Oci);
	// Oci = NULL;
	release_ptr(&Oci);
	
	printf("---\n");
	printf("Print only if not freed or NULL:\n");

	printf("Person Oči -> ");
	printIfNotFreedOrNull(Oci);

	printf("Copy of person Oči -> ");
	printIfNotFreedOrNull(copyOfOci);

	printf("---\n");
	printf("Without memset all %d chars to \".\"\n", STR_LEN);
	memset(copyOfOci->name, '\0', STR_LEN);
	strcpy(copyOfOci->name, "Gregor Redelonghi III");
	printAllChars(copyOfOci->name, STR_LEN);

	printf("---\n");
	printf("Memset all %d chars to \".\"\n", STR_LEN);
	memset(copyOfOci->name, '.', STR_LEN);
	strcpy(copyOfOci->name, "Gregor Redelonghi III");
	printAllChars(copyOfOci->name, STR_LEN);

	release_ptr(&copyOfOci);
	release_ptr(&Oci);

	return 0;
}

/**
 * print all characters of a string
 * shows all chars up to the memory size
 * if all chars were set to "." with memset,
 * or else just the chars in a string
 * parameters: string and LEN (defined)
 */
void printAllChars(char *string, int LEN) {
	
	printf("\"");
	for (int i=0; i < LEN; i++) {
		printf("%c", string[i]);
	}
	printf("\"\n");
}

/**
 * print data from struct Person
 * if struct not already freed or NULL
 * parameter: type Person (struct)
 */
void printIfNotFreedOrNull(Person *person) {
	
	if (person != NULL) {
		printf("name: %s, age %d\n", person->name, person->age);
	} else {
		printf("Person freed or NULL!\n");
	}
}

void release_ptr(void **ptr) {
	if (*ptr != NULL) {
		free(*ptr);
		*ptr = NULL;
		return;
	}
	
	printf("Already free!\n");
}

