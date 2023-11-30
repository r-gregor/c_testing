#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>

#define _DEBUGGING_ON

#define CRT printf("---\n");
// #define REGION_CAPACITY 0x80 //10 000 000 = MAX (if inside functiona and not static!)
#define REGION_CAPACITY 257*1024*1024 // 256 MiB


/*
 * region_reset(Region *r) coul be defined as a macro:
 * region_reset(T) (T)->size = 0
 */

/*
 * struct that holds data and meta-data of region memory
 */
typedef struct Region {
	unsigned char *buf;
	size_t capacity;
	size_t curr_offset;
	size_t prev_offset; // v2: added to calculate diff
} Region;


void region_init(Region *r, void *buff, size_t buff_size);
void *region_alloc(Region *r, size_t size);
void region_reset(Region *r);
void debug_info(Region *r);

unsigned char data[REGION_CAPACITY]; // static memory lifetime (or inside function as 'static')

/**
 * main
 */
int main(int argc, char **argv) {

	// declaration and initialization of stack based region memory:
	// 2 options available. One, to declare the array with static storage duration, either by
	// declaring it at file scope (outside of any function) or with the static keyword.
	// static unsigned char data[REGION_CAPACITY]; // static or segmentatio fault!
	Region r = {0};
	region_init(&r, data, REGION_CAPACITY);
	debug_info(&r); // test

	int *i = (int *)region_alloc(&r, sizeof(int));
	*i = -5100;
	debug_info(&r); // test

	char *name = region_alloc(&r, 30);            // num of chars between "" + at least 1
	memmove(name, "Berthold Von Schtrolzenburger", 30);
	debug_info(&r); // test

	float *f = (float *)region_alloc(&r, sizeof(float));
	*f = -123.456;
	debug_info(&r); // test

	char *name2 = region_alloc(&r, 22);            // num of chars between "" + at least 1
	memmove(name2, "Tadeja Mali Redelonghi", 22);
	debug_info(&r); // test

	long *j = (long *)region_alloc(&r, sizeof(long));
	*j = 1000000000000000000;
	debug_info(&r); // test

	char *name3 = region_alloc(&r, 18);      // num of chars between "" + at least 1
	memmove(name3, "Gregor Redelonghi", 18);
	debug_info(&r); // test

	CRT

	printf("addres of integer: %p, value: %d\n", i, *i);
	printf("addres of string: %p, value: %s\n", name, name);
	printf("addres of float: %p, value: %.3f\n", f, *f);
	printf("addres of string: %p, value: %s\n", name2, name2);
	printf("addres of long: %p, value: %ld\n", j, *j);
	printf("addres of string: %p, value: %s\n", name3, name3);
	
	CRT

	printf("Reseting the region ...\n");
	region_reset(&r);
	debug_info(&r);

	return 0;
} // end main


/*
 * initialization of region memory struct with data and meta-data
 */
void region_init(Region *r, void *buff, size_t buff_size) {
	r->buf = (unsigned char *)buff;
	r->capacity = buff_size;
	r->curr_offset = 0;
	r->prev_offset = 0;
}


/*
 * allocation of memory into region memory for single input
 * it returns the pointer to the beginning of the section inside
 * of region and adds size to currentofsset to update the poiner
 * to point to next available section
 */
void *region_alloc(Region *r, size_t size) {
	assert(r->curr_offset + size <= r->capacity);
	r->prev_offset = r->curr_offset;
	void *ptr = &r->buf[r->curr_offset];
	r->curr_offset += size;

	// nulling current section
	memset((uintptr_t *)ptr, 0, size);
	return ptr;
}

/*
 * simple reset: move pointer to beginning of the region memory
 */
void region_reset(Region *r) {
	r->prev_offset = 0;
	r->curr_offset = 0;
}

void debug_info(Region *r) {
#ifdef _DEBUGGING_ON
	size_t diff = r->curr_offset - r->prev_offset;
	printf("Current pointer: %p, current offset: %ld and diff: %ld\n", &r->buf[r->curr_offset], r->curr_offset, diff);
#endif
}

