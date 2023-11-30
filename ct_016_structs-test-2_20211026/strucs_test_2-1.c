#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST_ELEMENTS 15
#define NUM_LINE_CHARS 80

typedef struct Person { 
	char name[20];
	char lname[30];
	int age;
} Person;

void display_person(Person *pr) {
	printf("name: %s; lname: %s; age: %d\n", pr->name, pr->lname, pr->age);
}

/* main */
int main() {
	// SIMPLE SIMPLE SIMPLE SIMPLE SIMPLE SIMPLE SIMPLE SIMPLE SIMPLE SIMPLE 
	Person p1;
	strcpy(p1.name, "Gregor");
	strcpy(p1.lname, "Redelonghi");
	p1.age = 53;

	Person p2;
	strcpy(p2.name, "Tadeja");
	strcpy(p2.lname, "Mali Redelonghi");
	p2.age = 51;
	
	Person p3;
	strcpy(p3.name, "Arnold");
	strcpy(p3.lname, "Scwartzennegger");
	p3.age = 81;

	int count = 0;
	// printf("%d\n", count);

	Person plist[sizeof(Person)*15];
	plist[count] = p1;
	count++;

	plist[sizeof(Person)*count] = p2;
	count++;

	plist[sizeof(Person)*count] = p3;
	count++;

	/* 1-st for loop with display_person function */
	for (size_t i = 0; i < sizeof(Person)*count; i+=sizeof(Person)) {
		display_person(&plist[i]);
	}
	
	printf("---\n");

	/* 2-nd for loop: RAW */
	for (size_t i = 0; i < sizeof(Person)*count; i+=sizeof(Person)) {
		printf("%ld; name: %s; lname: %s; age: %d\n",i , plist[i].name, plist[i].lname, plist[i].age);
		// display_person(&plist[i]);
	}
	// SIMPLE SIMPLE SIMPLE SIMPLE SIMPLE SIMPLE SIMPLE SIMPLE SIMPLE SIMPLE 

	return 0;

}
