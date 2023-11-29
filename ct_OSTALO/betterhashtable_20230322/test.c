#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "hashtable.h"

#define MAX_LINE 4096

uint64_t hash(const char *name, size_t length) {
	uint64_t hash_value = 0;
	for (int i=0; i < length; i++) {
		hash_value += name[i];
		hash_value = hash_value * name[i];
	}
	return hash_value;
}

int main(int argc, char **argv) {
	if (argc != 3) {
		printf("usage: %s <wordlist filename> <num guesses>\n", argv[0]);
		return EXIT_FAILURE;
	}

	char *filename = argv[1];
	uint32_t num_guesses = atol(argv[2]);

	const int tablesize = (1<<20); // 1<<20 == 1048576 (1 MegaEntry)
	hash_table *table = hash_table_create(tablesize, hash);

	FILE *fp = fopen(filename, "r");
	char buffer[MAX_LINE];
	uint32_t numwords = 0;

	while (!feof(fp) && fgets(buffer, MAX_LINE, fp) != NULL) {
		buffer[strcspn(buffer, "\n\r")] = '\0'; // remove trailing newline simbol
		buffer[strcspn(buffer, "\n")] = '\0'; // remove trailing newline simbol
		char *newentry = malloc(strlen(buffer) + 1);
		strcpy(newentry, buffer);
		// test
			printf("%d: newentry: %s\n",numwords, newentry);
		hash_table_insert(table, newentry, newentry);
		numwords++;

	}
	fclose(fp);
	
	printf("Loaded %d words into the table\n", numwords);

	getchar();
	hash_table_print(table);

	return 0;
}

