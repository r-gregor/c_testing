/*
 * v1
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct person {
	char *name;
	int age;
} Person;

Person *make_person(char *name_inp, int age_inp);
void print_person_info(Person *prs);
bool update_person_info(Person *prs, char *name_inp, int age_inp);

// main
int main(int argc, char **argv) {

	Person *prs1 = make_person("Gregor Redelonghi", 54);
	print_person_info(prs1);

	update_person_info(prs1, "Tadeja Mali Redelonghi", 52);
	print_person_info(prs1);

	Person *prs2 = make_person("Mark Redelonghi", 23);
	print_person_info(prs2);

	update_person_info(prs2, "Zala Redelonmghi", 26);
	print_person_info(prs2);

	// dry created (with litterals -> cannot be updated!)
	Person prs4 = {"Špela Redelonghi", 23};
	print_person_info(&prs4);

	Person *prs5 = malloc(sizeof(Person));
	memcpy(prs5, &prs4, sizeof(Person));
	print_person_info(prs5);

	//compiles but gives: Aborted (core dumped)
	// struct not created with make_person() function
	update_person_info(prs5, "Zala Redelonghi", 26);
	print_person_info(prs5);

	return 0;
} // end main


Person *make_person(char *name_inp, int age_inp) {
	Person *newperson = malloc(sizeof(Person));

	newperson->name = NULL;
	newperson->name = malloc(strlen(name_inp) + 1);

	strcpy(newperson->name, name_inp);
	newperson->age = age_inp;

	return newperson;
}

void print_person_info(Person *prs){
	printf("Person name: %s, age: %d\n", prs->name, prs->age);
}


bool update_person_info(Person *prs, char *name_inp, int age_inp) {
	prs->name = realloc(prs->name, strlen(name_inp) + 1);

	if (prs->name == NULL) {
		printf("Error!");
		return false;
	}

	strcpy(prs->name, name_inp);
	prs->age = age_inp;

	return true;
}

