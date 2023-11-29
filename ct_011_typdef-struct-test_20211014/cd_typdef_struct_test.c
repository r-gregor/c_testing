#include <stdio.h>
#include <string.h>

const int curry = 2022;

struct PersonM {
	char name[10];
	char lname[20];
	int age;
	int born;
};

struct PersonF {
	char* name;
	char* lname;
	int age;
	int born;
};

int byear(int age) {
	return curry - age;
}

typedef struct PersonM person_m;
typedef struct PersonF person_f;

void print_out_m(person_m p) {
	printf("\nThe (male) person's data:\n");
	printf("The person's name is: %s.\n", p.name);
	printf("The person's last name is: %s.\n", p.lname);
	printf("The person's age is: %d.\n", p.age);
	printf("The person's year of birth is: %d.\n", p.born);
}

void print_out_f(person_f p) {
	printf("\nThe (female) person's data:\n");
	printf("The person's name is: %s.\n", p.name);
	printf("The person's last name is: %s.\n", p.lname);
	printf("The person's age is: %d.\n", p.age);
	printf("The person's year of birth is: %d.\n", p.born);
}

int main(int argc, char** argv) {

	person_m g1;
	strcpy(g1.name, "Gregor");			// char name[10]
	strcpy(g1.lname, "Redelonghi");		// char lname[20]
	g1.age = 54;
	g1.born = byear(g1.age);
	print_out_m(g1);

	person_f t1;
	t1.name = "Tadeja";
	t1.lname ="Mali Redelonghi";
	t1.age = 52;
	t1.born = byear(t1.age);
	print_out_f(t1);



	return 0;
}

