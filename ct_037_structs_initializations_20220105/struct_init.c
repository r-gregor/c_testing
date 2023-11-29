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

void print_mem(int, char*);
void print_part(int, char*);

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

	print_mem(member1.id, member1.name);
	print_mem(mbr2.id, mbr2.name);
	print_mem(m3.id, m3.name);
	print_mem(m4.id, m4.name);

	print_part(ram.id, ram.part_name);
	print_part(sp1.id, sp1.part_name);

	return 0;
}

void print_mem(int id, char* name) {
	printf("ID: %d; name: %s\n", id, name);
}

void print_part(int id, char* name) {
	printf("ID: %d; Part name: %s\n", id, name);
}
