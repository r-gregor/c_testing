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

typedef struct Person prsn;

int count = -1;
prsn family[FAMILY_SIZE];


prsn make_person(char *name, char *lname, int age) {
	prsn p;
	p.name = name;
	p.lname = lname;
	p.age = age;
	p.born = byear(p.age);
	p.index = ++count;
	return p;
}

void add_person_to_family(prsn p) {
	printf("Adding person \"%s %s\" at index %d to family ...\n", p.name, p.lname, p.index);
	if (p.index >= FAMILY_SIZE) {
		printf("Cannot add \"%s %s\" to this family. It's FULL!\n", p.name, p.lname);
		count--;
	} else {
		family[p.index] = p;
	}
}

void print_out(prsn p) {
	printf("---------------------------------------\n");
	printf("The person's index is: %d.\n", p.index);
	printf("The person's name is: %s.\n", p.name);
	printf("Tbhe person's last name is: %s.\n", p.lname);
	printf("The person's age is: %d.\n", p.age);
	printf("The person's year of birth is: %d.\n", p.born);
}

/* main */
int main(int argc, char **argv) {
	
	prsn g = make_person("Gregor", "Redelonghi",54);
	add_person_to_family(g);

	prsn t = make_person("Tadeja", "Mali Redelonghi", 52);
	add_person_to_family(t);

	add_person_to_family(make_person("Zala", "Redelonghi", 26));

	add_person_to_family(make_person("Mark", "Redelonghi", 23));

	add_person_to_family(make_person("Špela", "Redelonghi", 14));

	add_person_to_family(make_person("Sisi", "Redelonghi", 3));

	add_person_to_family(make_person("Arnold", "Schwartzennegger", 75));

	printf("The number of persons: %d\n", count + 1);

	for (int i=0; i<FAMILY_SIZE; i++) {
		print_out(family[i]);
	}


	return 0;
}

