#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_LEN 40
#define LINE_LEN 120

typedef struct Person {
	char name[NAME_LEN];
	int age;
} Person;

void printPerson(Person *);
void updatePerson(Person *, char *, int);
int testIfPtrNull(void *);
void releasePerson(Person **);

int main(int argc, char **argv) {

	Person *P1 = malloc(sizeof(Person));
	Person *P2 = malloc(sizeof(Person));
	Person *P3 = malloc(sizeof(Person));

	updatePerson(P1, "Gregor Redelonghi", 54);
	updatePerson(P2, "Tadeja Mali Redelonghi", 52);
	updatePerson(P3, "Špela Redelonghi", 14);

	printf("---\n");
	printf("Befor setting one to NULL:\n");
	printPerson(P1);
	printPerson(P2);
	printPerson(P3);

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

	return 0;
}

void printPerson(Person *p) {
	if (testIfPtrNull(p)) {
		printf("Person ptr = NULL!\n");
	} else {
		printf("Name: %s, age: %d\n", p->name, p->age);
	}
}

void updatePerson(Person *p, char *myname, int myage) {
	strcpy(p->name, myname);
	p->age = myage;
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


