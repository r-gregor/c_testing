/*
 * filename: strct_test.c
 * v1: en: 20260114
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FAM_MEMS_NUM 2

/* globals */

typedef struct Fmem {
	char *name;
	int age;
	int id;
} Fmem_t;

void display_fmem(Fmem_t *str);
void update_id(Fmem_t *s);
void release_ptr(void *ptr);
void display_chr_at_pos(char *str, int pos);
int count = 0;

/* main */
int main(int argc, char **argv) {

	Fmem_t s1;
	s1.name = "Gregor Redelonghi";
	s1.age  = 58;
	update_id(&s1);

	Fmem_t *s2;
	s2 = malloc(sizeof(Fmem_t));

	printf("Enter name: ");
	// scanf("%s", s2->name);
	fgets(s2->name, 32, stdin);
	s2->name[strlen(s2->name) - 1] = '\0'; // remove trailing '\n'
	update_id(s2);

	printf("Enter age: ");
	scanf("%d", &(s2->age));

	printf("---\n");
	display_fmem(&s1);
	display_fmem(s2);

	display_chr_at_pos(s2->name, 8);


	/* v2 */
	Fmem_t **fam_mems = malloc(sizeof(Fmem_t *) * FAM_MEMS_NUM);
	fam_mems[0] = &s1;
	fam_mems[1] = s2;

	printf("---\n");
	printf("%3s %-30s%3s\n", "Id", "Name", "Age");
	int dashnum = 37;
	for (int k=0; k<dashnum; ++k) {
		printf("-");
	}
	printf("\n");

	for (int i=0; i < FAM_MEMS_NUM; ++i) {
		printf("%03d %-30s%3d\n", fam_mems[i]->id, fam_mems[i]->name, fam_mems[i]->age);
	}
	printf("\n");

	// free(s2);
	// s2 = NULL;
	release_ptr(s2);

	// free(fam_mems);
	// fam_mems = NULL;
	release_ptr(fam_mems);

	return 0;
} // end main

/* functions */

/* display family member info */
void display_fmem(Fmem_t *s) {
	printf("id:   %02d\n", s->id);
	printf("Name: %s\n", s->name);
	printf("Age:  %d\n", s->age);
	printf("---\n");
}

/* update global counter of family members */
void update_id(Fmem_t *s) {
	count++;
	s->id = count;
}

/* free malloce'd ponters */
void release_ptr(void *ptr) {
	if (ptr != NULL) {
		free(ptr);
		ptr = NULL;
	}
}

/* show character at pos inside a name string */
void display_chr_at_pos(char *str, int pos) {
	int str_ln = strlen(str);
	if (pos > str_ln) {
		printf("[ERROR] Trying to get char at position %d\n", pos);
		printf("[ERROR] Char position outside string\n");
		return;
	} else {
		printf("Char at position: %d in '%s': '%c'\n", pos, str, *(str + (pos - 1)));
	}
}

