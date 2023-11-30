/*
 * v3
 * update the update_person_info() function
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
void update_person_info(Person *prs, char *name_inp, int age_inp);

// main
int main(int argc, char **argv) {

	printf("Creating person prs1: ");
	Person *prs1 = make_person("Gregor Redelonghi", 54);
	print_person_info(prs1);

	printf("Updating person prs1 to: ");
	update_person_info(prs1, "Tadeja Mali Redelonghi", 52);
	print_person_info(prs1);

	printf("Creating person prs2: ");
	Person *prs2 = make_person("Mark Redelonghi", 23);
	print_person_info(prs2);

	printf("Updating person prs2 to: ");
	update_person_info(prs2, "Zala Redelonmghi AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", 26);
	printf("prs2 remains: ");
	print_person_info(prs2);

	// dry created (with litterals -> cannot be updated!)
	printf("Creating (dry) person prs4: ");
	Person prs4 = {"Špela Redelonghi", 23};
	print_person_info(&prs4);

	printf("Making memory space for prs5 and memcpy the contents of prs4 into prs5\n");
	Person *prs5 = malloc(sizeof(Person));
	memcpy(prs5, &prs4, sizeof(Person));


	printf("Displaying info for person prs5: ");
	print_person_info(prs5);

	// v2: WORKS
	
	printf("Updating person prs5 to: ");
	update_person_info(prs5, "Sisi Redelonghi", 26);
	print_person_info(prs5);

	printf("Just for test: printing person prs2 info: ");
	print_person_info(prs2);

	printf("Just for test: printing person prs1 info: ");
	print_person_info(prs1);

	return 0;
} // end main


Person *make_person(char *name_inp, int age_inp) {
	Person *newperson = malloc(sizeof(Person));

	strcpy(newperson->name, name_inp);
	newperson->age = age_inp;

	return newperson;
}

void print_person_info(Person *prs){
	printf("name: %s, age: %d\n", prs->name, prs->age);
}


void update_person_info(Person *prs, char *name_inp, int age_inp) {
	if (strlen(name_inp) >= NAME_LEN) {
		printf("Error asigning name \"%s\", (too long)!\n", name_inp);
		return;
	}
	strcpy(prs->name, name_inp);
	prs->age = age_inp;
}

