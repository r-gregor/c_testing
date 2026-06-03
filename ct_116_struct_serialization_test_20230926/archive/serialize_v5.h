/*
 * serialize_v5.h
 * 20230928_01 (en)
 * 20231005_02 (d)
 * 20231006_03 (d)
 * 20231010_04 (en)
 * 20231010_05 (en)
 */

#ifndef SERIALIZE_H_
#define SERIALIZE_H_

#include <stdio.h>
#include <string.h>
#include <stdint.h>

/* 8+8+48 = 64 bytes struct */
typedef struct Element {
	uint64_t offset;
	uint64_t count;
	char name[48];
} Element_t;

#define BUF_SIZE 640 // 10 x struct of size 64
uint64_t elements_global_count = 0;

/* struct functions declarations */
void element_add_to_buf(char *buf, char *name);
void elements_print_all(char *buf, uint64_t elements_count);
void elements_print_single(char *buf, uint64_t pos, uint64_t elements_count);

/* v2
 * struct functions definitions */
/* add struct to buf memory region */
void element_add_to_buf(char *buf, char *name) {
	uint64_t next_offset = sizeof(Element_t) * elements_global_count;
	uint64_t element_num = elements_global_count + 1;

	if (next_offset >= BUF_SIZE) {
		printf("Buffer full!\n");
		return;
	}

	/* v2: no intermediate struct initialization, but directly asign pointer
	 * inside the buf
	 */
	printf("Creating element %ld with name: %s\n", element_num, name);
	Element_t *new_element = (Element_t *)(buf + next_offset);
	new_element->offset = next_offset; // v5
	new_element->count = element_num;
	strcpy(new_element->name, name);

	elements_global_count += 1;
}

/* print single struct info */
void elements_print_single(char *buf, uint64_t pos, uint64_t elements_count) {
	if (pos > elements_count) {
		fprintf(stderr, "Tried to print element number %ld: ", pos);
		fprintf(stderr, "buffer capacity owerflow!\n");
		printf("---\n");
		return;
	}

	/* v3 STARO
	char *new_element = buf + (pos - 1) * sizeof(Element_t);
	char *element_count = new_element + (uint64_t)offsetof(Element_t, count);
	char *name_pos = new_element + (uint64_t)offsetof(Element_t, name);
	printf("start: %p, count: %p, name pos: %p\n", new_element, element_count, name_pos);
	*/
	
	/* v5 NOVO */
	Element_t *new_element = (Element_t *)(buf + (pos - 1) * sizeof(Element_t));
	printf("offset: %ld\n", new_element->offset);
	printf("count:  %ld\n", new_element->count);
	printf("start:  %p, count: %p, name pos: %p\n", new_element, &new_element->count, new_element->name);
	printf("name:   %s\n", new_element->name);
	printf("---\n");
}

/* print all structs given the elements_count */
void elements_print_all(char *buf, uint64_t elements_count) {
	for (uint64_t pos = 1; pos <= elements_count; pos++) {
		elements_print_single(buf, pos, elements_count);
	}
}

#endif

