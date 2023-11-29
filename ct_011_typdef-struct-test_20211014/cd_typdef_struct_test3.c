#include <stdio.h>

const int curry = 2022;

struct Person {
	char* name;
	char* lname;
	int age;
	int born;
};

int byear(int age) {
	return curry - age;
}

typedef struct Person prsn;

int count = -1;
prsn family[5];


void make_person(char *name, char *lname, int age) {
	prsn p;
	p.name = name;
	p.lname = lname;
	p.age = age;
	p.born = byear(p.age);
	family[++count] = p;
}

void print_out(prsn p) {
	printf("---------------------------------------\n");
	printf("The person's name is: %s.\n", p.name);
	printf("Tbhe person's last name is: %s.\n", p.lname);
	printf("The person's age is: %d.\n", p.age);
	printf("The person's year of birth is: %d.\n", p.born);
}

/* main */
int main(int argc, char **argv) {
	
	make_person("Gregor", "Redelonghi",54);
	make_person("Tadeja", "Mali Redelonghi", 52);
	make_person("Zala", "Redelonghi", 26);
	make_person("Mark", "Redelonghi", 23);
	make_person("Špela", "Redelonghi", 14);
	
	printf("The number of persons: %d\n", count + 1);

	for (int i=0; i<5; i++) {
		print_out(family[i]);
	}


	return 0;
}

