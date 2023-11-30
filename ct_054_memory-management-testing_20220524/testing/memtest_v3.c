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
 * and updated createPerson() function to
 * store newly created Person to array
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
void addPerson(char *, int);     /* v3 */

int main(int argc, char **argv) {

	personsCount = 0;
	list_of_persons = malloc(sizeof(Person *) * MAX_ELEMENTS);

	addPerson("Gregor Redelonghi", 54);
	addPerson("Tadeja Mali Redelonghi", 52);
	addPerson("Špela Redelonghi", 14);
	addPerson("Sisi", 3);

	printf("---\n");
	printf("Befor setting one to NULL:\n");
	for (int k = 0; k < personsCount; k++) {
		printf("Person %d -- name: %s, age: %d years.\n", k + 1, list_of_persons[k]->name, list_of_persons[k]->age);
	}

	printf("---\n");
	printf("After setting third to NULL:\n");
	releasePerson(&list_of_persons[2]);
	for (int k = 0; k < personsCount; k++) {
		if (list_of_persons[k] != NULL) {
			printf("Person %d -- name: %s, age: %d years.\n", k + 1, list_of_persons[k]->name, list_of_persons[k]->age);
		}
	}


	for (int j = 0; j < personsCount; j++) {
		releasePerson(&list_of_persons[j]);
	}

	free(list_of_persons);
	list_of_persons = NULL;

	return 0;
}

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


