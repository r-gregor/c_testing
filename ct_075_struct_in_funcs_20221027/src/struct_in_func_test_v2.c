/*
 * v2
 * changed to fixed length char arrey for name
 * in struct
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define NAME_LEN 25

typedef struct person {
	char name[NAME_LEN];
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

	if ((update_person_info(prs2, "Zala Redelonmghi AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", 26)) == false){
		return -1;
	}
	print_person_info(prs2);

	// dry created (with litterals -> cannot be updated!)
	Person prs4 = {"Špela Redelonghi", 23};
	print_person_info(&prs4);

	Person *prs5 = malloc(sizeof(Person));
	memcpy(prs5, &prs4, sizeof(Person));
	print_person_info(prs5);

	// v2: WORKS
	if ((update_person_info(prs5, "Sisi Redelonghi", 26)) == false) {
		return -1;
	}
	print_person_info(prs5);

	return 0;
} // end main


Person *make_person(char *name_inp, int age_inp) {
	Person *newperson = malloc(sizeof(Person));

	strcpy(newperson->name, name_inp);
	newperson->age = age_inp;

	return newperson;
}

void print_person_info(Person *prs){
	printf("Person name: %s, age: %d\n", prs->name, prs->age);
}


bool update_person_info(Person *prs, char *name_inp, int age_inp) {
	if (strlen(name_inp) >= NAME_LEN) {
		printf("Error asigning name \"%s\", (too long)!\n", name_inp);
		return false;
	}
	strcpy(prs->name, name_inp);
	prs->age = age_inp;

	return true;
}

