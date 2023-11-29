#include <stdio.h>
#include <string.h>

#define FAMILY_SIZE 6

const int CURR_YEAR = 2022;

struct Person {
	char *name;
	char *lname;
	int age;
	int born;
	int index;
};

int byear(int age) {
	return CURR_YEAR - age;
}

typedef struct Person Person;

int count = -1;
int fmemnum = 0;
Person family[FAMILY_SIZE];


Person make_person(char *name, char *lname, int age) {
	Person p;
	p.name = name;
	p.lname = lname;
	p.age = age;
	p.born = byear(p.age);
	p.index = ++count;
	return p;
}

void print_out(Person p) {
	printf("The person's name is: %s.\n", p.name);
	printf("The person's age is: %d.\n", p.age);
	printf("The person's year of birth is: %d.\n", p.born);
}

void add_person_to_family(Person p) {
	printf("---------------------------------------\n");
	printf("Adding person \"%s %s\" at index %d ... ", p.name, p.lname, p.index);
	if (p.index >= FAMILY_SIZE) {
		printf("[FAIL]\nCannot add \"%s %s\" to Redelonghi family. FULL!\n", p.name, p.lname);
		// count--;
	} else {
		fmemnum++;
		family[p.index] = p;
		printf("[OK]\n");
		print_out(p);
	}
}

/* main */
int main(int argc, char **argv) {

	add_person_to_family(make_person("Gregor", "Redelonghi",54));
	add_person_to_family(make_person("Tadeja", "Mali Redelonghi", 52));
	add_person_to_family(make_person("Zala", "Redelonghi", 26));
	add_person_to_family(make_person("Mark", "Redelonghi", 23));
	add_person_to_family(make_person("Špela", "Redelonghi", 14));
	add_person_to_family(make_person("Sisi", "Redelonghi", 3));
	add_person_to_family(make_person("Arnold", "Schwartzennegger", 75));
	add_person_to_family(make_person("Jean Baptiste Emanuell", "z0rg", 174));

	printf("---------------------------------------\n");
	printf("The number of persons: %d\n", fmemnum);


/*
 * 	for (int i=0; i<FAMILY_SIZE; i++) {
 * 		print_out(family[i]);
 * 	}
 */

	return 0;
}

