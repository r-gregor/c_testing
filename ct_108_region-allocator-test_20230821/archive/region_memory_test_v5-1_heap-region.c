/*
 * v5.1: test HEAP based memory region
 * load contents of a big file into memory region
 * 20230821 (en)
 * 20230915 (en)
 * v5 new: get_fsize(FILE *fp)
 * v5.1: allocate big enough region: REGION_CAPACITYi = fsize --> malloc!!
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

#define _DEBUGGING_ON

/*
 * struct that holds data and meta-data of region memory
 */
typedef struct Region {
	unsigned char *buf;
	size_t capacity;
	size_t curr_offset;
	size_t prev_offset; // v2: to calculate diff
} Region;


void region_init(Region *r, void *buff, size_t buff_size);
void *region_alloc(Region *r, size_t size);
void region_reset(Region *r);
void debug_info(Region *r);
size_t get_fsize(FILE *fp);
void crt();

/**
 * main
 */
int main(int argc, char **argv) {

	char *fname = NULL;

	if (argc == 2) {
		fname = argv[1];
	} else {
		fname = "big_100MB_file.txt";
	}

	FILE *fp = fopen(fname, "r"); // OPEN
	const size_t fsize = get_fsize(fp);

	size_t REGION_CAPACITY = fsize;
	
	// declaration and initialization of HEAP based region memory:
	unsigned char *data = malloc(REGION_CAPACITY);

	Region r = {0};
	region_init(&r, data, REGION_CAPACITY);
	debug_info(&r); // test

	// alocate memory region
	char *story = region_alloc(&r, fsize);
	
	// read from file into memory region
	fread(story, 1, fsize, fp);
	fclose(fp); // CLOSE

	debug_info(&r); // test

	crt(); //---

	printf("Total memory space: %12ld bytes\n", r.curr_offset);
	printf("file size:          %12ld bytes (-)\n", fsize);
	printf("Unused memory:      %12ld bytes (=)\n", r.curr_offset - fsize);

	crt(); //---

	// set cursor to 1024 bytes till the end of file size
	size_t curr_point = fsize - 1024;

	// write from cursor till  end of a string
	int n = 3;
	size_t start = curr_point;
	size_t end = start + 1024 * n;
	size_t diff = end - start;

	printf("Printing out memory section from %ld till %ld (%ld bytes = 1024 * %d)\n", start, end, diff, n);
	fwrite( story + curr_point, 1024, n, stdout); // as long as (story + curr_point + 1024 * n) <= fsize
	printf("\n");

	crt(); //---

	printf("Reseting the region ...\n");
	region_reset(&r);
	debug_info(&r);
	
	free(data); // v5.1

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
 * of region and adds size to current ofsset to update the pointer
 * to point to next available section
 */
void *region_alloc(Region *r, size_t size) {
	assert(r->curr_offset + size <= r->capacity);
	r->prev_offset = r->curr_offset;
	void *ptr = &r->buf[r->curr_offset]; // pointer to beginning of this section to be returned
	r->curr_offset += size;              // update pointer to addres for next section

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

/*
 * get file size from file descriptor
 * fopen() and fclose() OUTSIDE of function
 * if fsize > REGION_CAPACITY file is read only as much as
 * REGION_CAPACITY
 */
size_t get_fsize(FILE *fp) {
	if (fp == NULL) {
		fprintf(stderr, "Could not open the file\n");
		exit(1);
	}

	// get size of file
	fseek(fp, 0, SEEK_END);   // move pointer to END
	size_t fsize = ftell(fp); // 105906176
	fseek(fp, 0, SEEK_SET);   // move pointer to START

	// if (fsize > REGION_CAPACITY) {
	// 	fsize = REGION_CAPACITY;
	// }

	return fsize;
}

void crt() {
	printf("---\n");
}

