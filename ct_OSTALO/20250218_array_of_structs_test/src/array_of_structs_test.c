#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MEM_NUM 6

typedef struct fmem {
	char *name;
	int birth_year;
} Fmem_t;

size_t fmem_num = 0;

Fmem_t *init_person(char *name, int birth_year);
void add_fmem_to_list(Fmem_t *fmem, Fmem_t **fmem_list, size_t *pos);
void print_fmems(Fmem_t **fmem_list);
void release_memory(Fmem_t **list);

int main(int argc, char **argv) {

	Fmem_t **fmem_list = malloc(sizeof(Fmem_t *) * MAX_MEM_NUM);

	Fmem_t *me = init_person("Gregor Redelongi", 1968);
	Fmem_t *zena = init_person("Tadeja Mali Redelongi", 1970);
	Fmem_t *sin = init_person("Mark Redelongi", 1999);
	Fmem_t *hci1 = init_person("Zala Redelongi", 1996);
	Fmem_t *hci2 = init_person("Špela Redelongi", 2011);
	Fmem_t *macka = init_person("Sisi", 2020);
	Fmem_t *ext = init_person("Berthold Strolzenburger", 2000);
	Fmem_t *ext2 = init_person("Eufigenya Cleopatra Djokich", 1902);

	add_fmem_to_list(me, fmem_list, &fmem_num);
	add_fmem_to_list(zena, fmem_list, &fmem_num);
	add_fmem_to_list(hci1, fmem_list, &fmem_num);
	add_fmem_to_list(hci2, fmem_list, &fmem_num);
	add_fmem_to_list(sin, fmem_list, &fmem_num);
	add_fmem_to_list(macka, fmem_list, &fmem_num);
	add_fmem_to_list(ext, fmem_list, &fmem_num);
	add_fmem_to_list(ext2, fmem_list, &fmem_num);

	print_fmems(fmem_list);
	release_memory(fmem_list);

	return 0;
}

Fmem_t *init_person(char *name, int birth_year) {
	Fmem_t *fmem = malloc(sizeof(Fmem_t));
	fmem->name = name;
	fmem->birth_year = birth_year;

	return fmem;
}

void add_fmem_to_list(Fmem_t *fmem, Fmem_t **fmem_list, size_t *pos) {
	if (*pos >= MAX_MEM_NUM) {
		fprintf(stderr, "---\n");
		fprintf(stderr, "[ERR] Trying to add '%s (%d)' to Family members list into position %02ld\n", fmem->name, 2025 - fmem->birth_year, *pos + 1);
		fprintf(stderr, "[ERR] Family members list full\n");
		return;
	} else {
		fmem_list[*pos] = fmem;
		printf("[INF] Added '%s' to Family members list into position %02ld\n", fmem->name, *pos + 1);
		*pos += 1;
	}
}

void print_fmems(Fmem_t **fmem_list) {
	printf("---\n");
	printf("test: how many members: %ld\n", fmem_num);
	size_t index =0;
	while (index < fmem_num) {
		printf("%02ld: %s (%d)\n", index + 1, fmem_list[index]->name, 2025 - fmem_list[index]->birth_year);
		index++;
	}
}

void release_memory(Fmem_t **list) {
	for (size_t j = 0; j < fmem_num; j++) {
		free(list[j]);
	}
	free(list);
}

