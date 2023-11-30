#include <stdio.h>
#include <string.h>

#define NAME_LEN 25

typedef struct fmem {
	int id;
	char *name;
} Fmem;

typedef struct nano {
	int id;
	char *part_name;
} Nano;

void print_mem(Fmem *);
void print_part(Nano *);

int main() {

	int mems = 0;

	struct fmem member1 = {.id=++mems, .name="Gregor"};

	Fmem mbr2;
	mbr2.name = "Tadeja";
	mbr2.id = ++mems; 

	struct fmem m3;
	m3.id = ++mems;
	m3.name = "Mark";

	Fmem m4 = {.name="Zala", .id=++mems};

	Nano ram;
	ram.id = 10050;
	ram.part_name = "DRAM SR1500, 128GB";

	struct nano sp1 = {.part_name="Špela", .id=2008};

	print_mem(&member1);
	print_mem(&mbr2);
	print_mem(&m3);
	print_mem(&m4);

	print_part(&ram);
	print_part(&sp1);

	return 0;
}

void print_mem(Fmem *fmem) {
	printf("ID: %d; name: %s\n", fmem->id, fmem->name);
}

void print_part(Nano *nano) {
	printf("ID: %d; Part name: %s\n", nano->id, nano->part_name);
}

