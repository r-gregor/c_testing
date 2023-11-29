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
	printf("memnum: %d; ", list->memnum);
	printf("name: %s; lname: %s; age: %d\n", list->plist[index].name, list->plist[index].lname, list->plist[index].age);
	*/
	list->memnum++;
}

void display_all_1(Persons_list *list) {
	for (int i=0; i<list->memnum; i++) {
		size_t myindex = sizeof(Person) * i;
		display_person(list->plist[myindex]);
	}
}


void display_all_2(Persons_list *list) {
	for (int i=0; i<list->memnum; i++) {
		size_t myindex = sizeof(Person) * i;
		printf("index: %d; name: %s; lname: %s; age: %d\n",i , list->plist[myindex].name, list->plist[myindex].lname, list->plist[myindex].age);
	}
}


void display_person(Person *pr) {
	printf("name: %s; lname: %s; age: %d\n", pr->name, pr->lname, pr->age);
}

void crta() {
	for (int i=0; i < NUM_LINE_CHARS; i++) {
		printf("-");
	}
	printf("\n");
}

int main() {

	Persons_list *myList1;
	myList1->memnum = 0;

	Person p1 = {"Gregor", "Redelonghi", 53};
	Person p2 = {"Tadeja", "Mali Redelonghi", 51};
	Person p3 = {"Arnold", "Schwatrzennegger", 81};

	add_person(myList1, &p1);
	add_person(myList1, &p2);
	add_person(myList1, &p3);

	/*
	for (int i = 0; i < myList1->memnum; i++) {
		size_t myindex = sizeof(Person) * i;
		// printf("%d; name: %s; lname: %s; age: %d\n",i , myList1->plist[myindex].name, myList1->plist[myindex].lname, myList1->plist[myindex].age);
		display_person(&myList1->plist[myindex]);
	*/
	
	crta();
	display_all_1(myList1);
	crta();
	display_all_2(myList1);
	crta();



	/*
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
	printf("%d\n", count);

	Person plist[sizeof(Person)*15];
	plist[count] = p1;
	count++;

	plist[sizeof(Person)*count] = p2;
	count++;

	plist[sizeof(Person)*count] = p3;
	count++;

	for (int i = 0; i < sizeof(Person)*count; i+=sizeof(Person)) {
		// printf("%d; name: %s; lname: %s; age: %d\n",i , plist[i].name, plist[i].lname, plist[i].age);
		display_person(&plist[i]);
	}
	// SIMPLE SIMPLE SIMPLE SIMPLE SIMPLE SIMPLE SIMPLE SIMPLE SIMPLE SIMPLE 
	*/

}
