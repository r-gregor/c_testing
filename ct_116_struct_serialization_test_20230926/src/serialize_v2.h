/*
 * serialize_v2.h
 * 20230928_01 (en)
 * 20231005_02 (d)
 */

#ifndef SERIALIZE_H_
#define SERIALIZE_H_

#include <stdio.h>
#include <string.h>
#include <stdint.h>

/* 8+8+48 = 64 bytes struct */
typedef struct mystrct {
	uint64_t offset;
	uint64_t count;
	char name[48];
} mystrct_t;

#define BUF_SIZE 640 // 10 x struct of size 64
uint64_t strcts_global_count = 0;

/* struct functions declarations */
void add_struct(char *buf, char *name);
void print_all_structs(char *buf, uint64_t structs_count);
void print_single_struct(char *buf, uint64_t position, uint64_t structs_count);

/* v2
 * struct functions definitions */
/* add struct to buf memory region */
void add_struct(char *buf, char *name) {
	uint64_t next_offset = sizeof(mystrct_t) * strcts_global_count;
	uint64_t struct_num = strcts_global_count + 1;

	if (next_offset >= BUF_SIZE) {
		printf("Buffer full!\n");
		return;
	}

	/* v2: no intermediate struct initialization, but directly asign pointer
	 * inside the buf
	 */
	printf("Creating struct %ld with name: %s\n", struct_num, name);
	mystrct_t *new_struct = (mystrct_t *)(buf + next_offset);
	new_struct->count = struct_num;
	strcpy(new_struct->name, name);

	strcts_global_count += 1;
}

/* print single struct info */
void print_single_struct(char *buf, uint64_t position, uint64_t structs_count) {
	if (position > structs_count) {
		fprintf(stderr, "Tried to print struct number %ld: ", position);
		fprintf(stderr, "buffer capacity owerflow!\n");
		printf("---\n");
		return;
	}

	char *start = buf + (position - 1) * sizeof(mystrct_t);
	char *cnt = start + (uint64_t)offsetof(mystrct_t, count);
	char *pointer = start + (uint64_t)offsetof(mystrct_t, name);
	// printf("start: %p, cnt: %p, pointer: %p\n", start, cnt, pointer);
	printf("count: %ld\n", (uint64_t)*cnt);
	printf("name:  %s\n", pointer);
	printf("---\n");
}

/* print all structs given the structs_count */
void print_all_structs(char *buf, uint64_t structs_count) {
	for (uint64_t position = 1; position <= structs_count; position++) {
		print_single_struct(buf, position, structs_count);
	}
}

#endif

