/*
 * FROM:
 * Writing Garbage Collector in C
 * https://www.youtube.com/watch?v=2JgEKEd3tw8
 * Tsoding Daily
 * References:
 * - Source Code: https://github.com/tsoding/memalloc
 * - Previous Episode (malloc/free): https://www.youtube.com/watch?v=sZ8GJ... …
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

#define HEAP_CAP 640000

/*
 * ep1
 * static_assert(HEAP_CAP % sizeof(void *) == 0);
 * char *heap[HEAP_CAP / sizeof(void *)];
 */

// ep2
// arranging the slots of heap by the size of a word not a size of byte!
// size of slot = sizeof(uintptr_t) ... pointer
static_assert(HEAP_CAP % sizeof(uintptr_t) == 0);
uintptr_t heap[HEAP_CAP / sizeof(uintptr_t)];

typedef struct {
	char xs[2];
	void *ptr;
} Foo;

int main(int argc, char **argv) {

	printf("\nstructure declaration:\n");
	printf(""
	"  typedef struct {\n"
	"  	char xs[2];\n"
	"  	void *ptr;\n"
	"  } Foo;\n"
	"\n"
	);

	printf("sizeof(char) = %zu\n", sizeof(char));
	printf("sizeof(void *) = %zu\n", sizeof(void *));
	printf("sizeof(Foo) = %zu\n", sizeof(Foo));

	printf("---\n");

	// ep2
	Foo *foo = (Foo *) heap;
	for (size_t i=0; i < sizeof(foo->xs); ++i) {
		foo->xs[i] = i + 1;
	}
	foo->ptr = foo;

	printf("foo->ptr: %p\n", foo->ptr);
	printf("heap[0]:  %p\n", (void *) heap[0]);
	printf("heap[1]:  %p\n", (void *) heap[1]);


	return 0;
}

