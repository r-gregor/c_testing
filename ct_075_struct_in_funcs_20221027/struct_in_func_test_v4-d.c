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
bool update_person_info(Person *prs, char *name_inp, int age_inp);

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

	// dry created
	printf("Creating (dry) person prs4: ");
	Person prs4 = {"Špela Redelonghi", 23};
	print_person_info(&prs4);

	printf("Updating person prs4 to: ");
	// update_person_info(&prs4, "Sisi Redelonghi", 3);
	// print_person_info(&prs4);
	if ((update_person_info(&prs4, "Sisi Redelonghi", 3)) == false) {
		return -1;
	}
	print_person_info(&prs4);

	printf("Just for test: printing person prs1 info: ");
	print_person_info(prs1);

	printf("Just for test: printing person prs2 info: ");
	print_person_info(prs2);

	printf("Just for test: printing person prs4 info: ");
	print_person_info(&prs4);
	
	// malloc-ed struct must be freed!
	free(prs1);
	free(prs2);

	return 0;
} // end main


Person *make_person(char *name_inp, int age_inp) {
	Person *newperson = malloc(sizeof(Person));

	if (newperson == NULL) {
		printf("Error allocating memory!\n");
		return NULL;
	}

	strcpy(newperson->name, name_inp);
	newperson->age = age_inp;

	return newperson;
}

void print_person_info(Person *prs){
	printf("name: %s, age: %d\n", prs->name, prs->age);
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

/* memory leak check command:
 * valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s bin/struct_in_func_test_v4-d
 */

