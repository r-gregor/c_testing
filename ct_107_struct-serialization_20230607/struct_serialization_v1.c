/**
 * struct_serialization_v1.c
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>


#if 0
// as tuple:
const char* PERSON_FORMAT_OUT = "(%s, %d, %c)\n";
const char* PERSON_FORMAT_IN = "(%[^,], %d, %c)\n";  // NOT %s - it reades till the space!
													 // [^,]   - it reads everithing up to the comma
char *fname = "people.dat";
bool is_jason = false;
#else
// jason format:
const char* PERSON_FORMAT_OUT = "{\n\t\"name\": \"%s\",\n\t\"age\": \"%d\",\n\t\"gender\": \"%c\"\n}\n";
const char* PERSON_FORMAT_IN = "(\n\t\"name\": \"%[^,]\",\n\t\"age\": \"%d\",\n\t\"gender\": \"%c\"\n)\n";
char *fname = "people.json";
bool is_jason = true;
#endif

typedef struct person {
	char name[20];
	int age;
	char gender;

} Person;

void show_person(Person *p);

int main(int argc, char **argv) {

	Person p1 = {
		.name = "Gregor Redelonghi",
		.age = 55,
		.gender = 'M'
	};

	Person p2; // where the data wil be saved into

	FILE* file;
	// fopen_s(&file, fname, "w+");
	file = fopen(fname, "w+");

	if (file == NULL) {
		fprintf(stderr, "ERROR: could not open the file");
		return 1;
	}

	// fprintf_s(file, PERSON_FORMAT_OUT, p1.name, p1.age, p1.gender);
	fprintf(file, PERSON_FORMAT_OUT, p1.name, p1.age, p1.gender);
	fseek(file, 0, SEEK_SET);

	// fscanf_s(file, PERSON_FORMAT_IN, p2.name, 20, &p2.age, &p2.gender); // fscanf_s expects addresses and buffer length!
	fscanf(file, PERSON_FORMAT_IN, p2.name, &p2.age, &p2.gender);        // fscanf expects addresses!
	fclose(file);

	if(!is_jason) {
		show_person(&p2);
	}

	return 0;
}

void show_person(Person *p) {
	printf("name:   %s\n", p->name);
	printf("age:    %d\n", p->age);
	printf("gender: %c\n", p->gender);
}

