#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_LEN 40
#define LINE_LEN 120

/* v2
 * moved malloc() and updatePerson() function
 * into new createPerson() function
 */

typedef struct Person {
	char name[NAME_LEN];
	int age;
} Person;

void printPerson(Person *);
Person *createPerson(char *, int);
int testIfPtrNull(void *);
void releasePerson(Person **);

int main(int argc, char **argv) {

	Person *P1, *P2, *P3;

	P1 = createPerson("Gregor Redelonghi", 54);
	P2 = createPerson("Tadeja Mali Redelonghi", 52);
	P3 = createPerson("Špela Redelonghi", 14);

	Person *P4 = createPerson("Sisi", 3);

	printf("---\n");
	printf("Befor setting one to NULL:\n");
	printPerson(P1);
	printPerson(P2);
	printPerson(P3);
	printPerson(P4);

	printf("---\n");
	printf("After setting one to NULL:\n");

	/*
	free(P2);
	P2 = NULL;
	*/

	releasePerson(&P3);

	printPerson(P1);
	printPerson(P2);
	printPerson(P3);
	printPerson(P4);

	return 0;
}

void printPerson(Person *p) {
	if (testIfPtrNull(p)) {
		printf("Person ptr = NULL!\n");
	} else {
		printf("Name: %s, age: %d\n", p->name, p->age);
	}
}

Person *createPerson(char *myname, int myage) {
	Person *p = malloc(sizeof(Person));
	strcpy(p->name, myname);
	p->age = myage;
	return p;
}

int testIfPtrNull(void *ptr) {
	if (ptr == NULL) {
		return 1;
	}
	return 0;
}

void releasePerson(Person **ptr) {
	free(*ptr);
	*ptr = NULL;
}


