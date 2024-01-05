/*
 * offsetof_test_v2.c
 * v2
 * 20240105_02 (en)
 */
#include <stdio.h>
#include <string.h>
#include <stddef.h> // offsetof()

typedef struct Data {
	size_t size;
	int age;
	char name[256];
} Data;

/* MAIN */
int main(void) {

	printf("Offset of 'size': %ld\n", offsetof(Data, size));
	printf("Offset of 'age':  %ld\n", offsetof(Data, age));
	printf("Offset of 'name': %ld\n", offsetof(Data, name));
	printf("sizeof(size):     %ld\n", sizeof(size_t));
	printf("sizeof(age):      %ld\n", sizeof(int));
	printf("sizeof(struct Data): %ld (aligned to multiple of 8 (added 4))\n", sizeof(Data));

	printf("---\n");

	Data d1 = {0};
	strcpy(d1.name, "Tadeja Mali Redelonghi");
	size_t name_len = strlen("Tadeja ");

	/* internal offset from Data struct pointer to position of last name in 'name' field */
	size_t lastn_offset = offsetof(Data, name) + name_len;

	 /* new absolute position of pointer inside struct d1: points to last name:
	    also works: "char *new_pos = (char *)(&d1) + lastn_offset;" */
	size_t new_pos = (size_t)(&d1) + lastn_offset;

	/* info display */
	printf("&d1:                 %p\n", &d1);
	printf("&d1.name:            %p\n", d1.name);
	printf("d1.name:            '%s'\n", d1.name);
	printf("strlen('Tadeja '):   %ld\n", name_len);
	printf("lastn_offset:        %ld (offset of 'name' + strlen('Tadeja '))\n", lastn_offset);
	printf("New pos:             %p\n", (char *)new_pos);
	printf("Lastn:              '%s'\n", (char *)new_pos);

	printf("---------------------------------------------------------------\n");

	/* visual representation */
	printf("  typedef struct Data {\n");
	printf("  	size_t size;       \n");
	printf("  	int age;           \n");
	printf("  	char name[256];    \n");
	printf("  } Data;              \n");

	printf("\n");

	printf("  Data d1 = {0};\n");
	printf("  strcpy(d1.name, \"Tadeja Mali Redelonghi\");\n\n");

	printf("  0      7  11     18                    271 (position)     \n");
	printf("  1      8  12     19                    272 (bytes offset) \n");
	printf("  x......x...x......x................ ~ ...x                \n");
	printf("  |      |   |      |                                       \n");
	printf("  |      |   |     'Mali Redelonghi'                        \n");
	printf("  |      |   |      Lastn                                   \n");
	printf("  |      |   |      |                                       \n");
	printf("  |      |  'Tadeja Mali Redelonghi'                        \n");
	printf("  |      |   d1.name                                        \n");
	printf("  |      |                                                  \n");
	printf("  |      d1.age                                             \n");
	printf("  d1.size                                                   \n");
	printf("  d1                                                        \n");

	return 0;
} // end MAIN

