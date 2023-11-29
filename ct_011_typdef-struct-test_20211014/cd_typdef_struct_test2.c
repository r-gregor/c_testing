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

int count = 0;

void print_out(prsn p) {
	printf("\nThe person's data:\n");
	printf("The person's name is: %s.\n", p.name);
	printf("Tbhe person's last name is: %s.\n", p.lname);
	printf("The person's age is: %d.\n", p.age);
	printf("The person's year of birth is: %d.\n", p.born);
}

int main(int argc, char** argv) {

	prsn g1;
	g1.name = "Gregor";
	g1.lname = "Redelonghi";
	g1.age = 54;
	g1.born = byear(g1.age);
	print_out(g1);

	prsn t1;
	t1.name = "Tadeja";
	t1.lname ="Mali Redelonghi";
	t1.age = 52;
	t1.born = byear(t1.age);
	print_out(t1);

	return 0;
}

