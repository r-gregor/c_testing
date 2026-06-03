/*
 * v4
 * load contents of a big file into memory region
 * 20230821 (en)
 * 20230915 (en)
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>

#define _DEBUGGING_ON

#define CRT printf("---\n");
// #define REGION_CAPACITY 0x80 //10 000 000 = MAX (if inside functiona and not static!)
// #define REGION_CAPACITY 50*1024*1024 // test if fsize > than REGION_CAPACITY
#define REGION_CAPACITY 200*1024*1024


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
	size_t prev_offset; // v2: to calculate diff
} Region;


void region_init(Region *r, void *buff, size_t buff_size);
void *region_alloc(Region *r, size_t size);
void region_reset(Region *r);
void debug_info(Region *r);

unsigned char data[REGION_CAPACITY]; // [**1]: static memory lifetime (or inside function as 'static')

/**
 * main
 */
int main(int argc, char **argv) {

	// declaration and initialization of stack based region memory:
	// [**1]: 2 options available. One, to declare the array with static storage duration, either by
	// declaring it at file scope (outside of any function) or with the static keyword.
	// static unsigned char data[REGION_CAPACITY]; // static or segmentatio fault!
	Region r = {0};
	region_init(&r, data, REGION_CAPACITY + 1);
	debug_info(&r); // test
	
	char *fname = "big_100MB_file.txt";
	FILE *fp = fopen(fname, "r");

	if (fp == NULL) {
		fprintf(stderr, "Could not open the file\n");
		return 1;
	}

	// size of file
	fseek(fp, 0, SEEK_END);   // move pointer to END
	size_t fsize = ftell(fp); // 105906176
	fseek(fp, 0, SEEK_SET);   // move pointer to START

	// allocate memory
	// char *story = region_alloc(&r, 150*1024*1024); // v1:   num of chars between "" + at least 1
	if (fsize > REGION_CAPACITY) {                    // v4.2 check if fiule size is bigger than region memory
		fsize = REGION_CAPACITY;
	}
	char *story = region_alloc(&r, fsize);            // v4.2: num of chars between in file = fsize
	
	// read from file into memory region
	// fread(story, 150, 1024*1024, fp);   // v1
	// fread(story, 1, 150*1024*1024, fp); // v4.1
	fread(story, 1, fsize, fp);            // v4.2
	fclose(fp);

	debug_info(&r); // test

	CRT

	printf("Total memory space: %12ld bytes\n", r.curr_offset);
	printf("file size:          %12ld bytes (-)\n", fsize);
	printf("Unused memory:      %12ld bytes (=)\n", r.curr_offset - fsize);

	CRT

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

