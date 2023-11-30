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

typedef struct Persons_list {
	int memnum;
	Person plist[sizeof(Person) * MAX_LIST_ELEMENTS];

} Persons_list;

void add_person(Persons_list *list, Person *prs) {
	size_t index = sizeof(Person)*(list->memnum); 
	list->plist[index] = *prs;
	/* TEST
	 *printf("memnum: %d; ", list->memnum);
	 *printf("name: %s; lname: %s; age: %d\n", list->plist[index].name, list->plist[index].lname, list->plist[index].age);
	 */
	list->memnum++;
}

void display_person(Person *pr) {
	printf("name: %s; lname: %s; age: %d\n", pr->name, pr->lname, pr->age);
}

void display_all_1(Persons_list *list) {
	for (int i=0; i<list->memnum; i++) {
		size_t myindex = sizeof(Person) * i;
		Person p = list->plist[myindex];
		display_person(&p);
	}
}


void display_all_2(Persons_list *list) {
	for (int i=0; i<list->memnum; i++) {
		size_t myindex = sizeof(Person) * i;
		printf("index: %d; name: %s; lname: %s; age: %d\n",i , list->plist[myindex].name, list->plist[myindex].lname, list->plist[myindex].age);
	}
}

void crta() {
	for (int i=0; i < NUM_LINE_CHARS; i++) {
		printf("-");
	}
	printf("\n");
}


/* Main */
int main() {

	Persons_list myList1;
	myList1.memnum = 0;

	Person p1 = {"Gregor", "Redelonghi", 53};
	Person p2 = {"Tadeja", "Mali Redelonghi", 51};
	Person p3 = {"Arnold", "Schwartzennegger", 81};

	add_person(&myList1, &p1);
	add_person(&myList1, &p2);
	add_person(&myList1, &p3);

	crta();
	display_all_1(&myList1);
	crta();
	display_all_2(&myList1);
	crta();


	return 0;
}

