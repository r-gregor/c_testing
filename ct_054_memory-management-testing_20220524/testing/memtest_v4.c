#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_LEN 40
#define LINE_LEN 120
#define MAX_ELEMENTS 10

/* v2
 * moved malloc() and updatePerson() function
 * into new createPerson() function
 */

/* v3
 * added an array os Person struct pointers
 * and moved contents of createPerson() function to
 * addPerson() function to create and store Person to array
 */

/* v4
 * new printElements() function that checks if an element of
 * an array is NOT NULL (released --> free, NULL), and prints
 * the element.
 */

typedef struct Person {
	char name[NAME_LEN];
	int age;
} Person;

Person **list_of_persons;
int personsCount;

void printPerson(Person *);
int testIfPtrNull(void *);
void releasePerson(Person **);
void addPerson(char *, int);        /* v3 */
void printElements(Person **list);  /* v4 */

/* main */
int main(int argc, char **argv) {

	personsCount = 0;
	list_of_persons = malloc(sizeof(Person *) * MAX_ELEMENTS);

	addPerson("Gregor Redelonghi", 54);
	addPerson("Tadeja Mali Redelonghi", 52);
	addPerson("Špela Redelonghi", 14);
	addPerson("Sisi", 3);

	printf("---\n");
	printf("Befor setting one to NULL:\n");
	printElements(list_of_persons);

	printf("---\n");
	printf("After setting third to NULL:\n");
	releasePerson(&list_of_persons[2]);
	printElements(list_of_persons);

	printf("---\n");
	printf("After setting second one to NULL:\n");
	releasePerson(&list_of_persons[1]);
	printElements(list_of_persons);

	printf("---\n");
	for (int n = 0; n < personsCount; n++) {
		printf("Person %d - ", n + 1);
		printPerson(list_of_persons[n]);
	}


	for (int j = 0; j < personsCount; j++) {
		releasePerson(&list_of_persons[j]);
	}

	free(list_of_persons);
	list_of_persons = NULL;

	return 0;
} // end main

/* custom functions */

void printPerson(Person *p) {
	if (testIfPtrNull(p)) {
		printf("Person ptr = NULL!\n");
	} else {
		printf("Name: %s, age: %d\n", p->name, p->age);
	}
}

void addPerson(char *myname, int myage) {
	int *cnt = &personsCount;
	Person *p = malloc(sizeof(Person));
	strcpy(p->name, myname);
	p->age = myage;
	list_of_persons[*cnt] = p;
	*cnt += 1;
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

void printElements(Person **list) {
	for (int k = 0; k < personsCount; k++) {
		if (list_of_persons[k] != NULL) {
			printf("Person %d -- name: %s, age: %d years.\n", k + 1, list_of_persons[k]->name, list_of_persons[k]->age);
		}
	}
}


