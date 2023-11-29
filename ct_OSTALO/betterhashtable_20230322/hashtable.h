#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef uint64_t (hashfunction) (const char *, size_t);
typedef struct _hash_table hash_table;

hash_table *hash_table_create(const uint32_t size, hashfunction *hf);
void hash_table_destroy(hash_table *ht);
void hash_table_print(hash_table *ht);

// refactoring v1
/*
bool hash_table_insert(hash_table *ht, const char *key, size_t keylen, void *obj);
void *hash_table_lookup(hash_table *ht, const char *key, size_t keylen);
void *hash_table_delete(hash_table *ht, const char *key, size_t keylen);
*/

// refactoring v1
bool hash_table_insert(hash_table *ht, const char *key, void *obj);
void *hash_table_lookup(hash_table *ht, const char *key);
void *hash_table_delete(hash_table *ht, const char *key);

#endif

