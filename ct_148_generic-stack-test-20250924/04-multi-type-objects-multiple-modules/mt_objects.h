#ifndef _MT_OBJECTS_H
#define _MT_OBJECTS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/* structures */

/* forward declared struct
 * it will be used in circular dependency between:
 * object_t -> object_data_t -> vector_t
 */

/* must be declared before object_data_t union whwere it is used -- size must be known! */
typedef struct object object_t;

typedef struct Vector {
	object_t *x;
	object_t *y;
	object_t *z;
} vector_t;

typedef struct Array {
	size_t size;
	object_t **elements;
} array_t;

typedef enum object_kind {
	INTEGER,
	FLOAT,
	STRING,
	VECTOR3,
	ARRAY
} object_kind_t;

typedef union object_data {
	int          v_int;
	float      v_float;
	char     *v_string;
	vector_t v_vector3;
	array_t    v_array;
} object_data_t;

typedef struct object {
	object_kind_t kind;
	object_data_t data;
} object_t;

/* function declarations */
object_t *new_integer(int value);
object_t *new_float(int value);
object_t *new_string(char *value);
object_t *new_vector3(object_t *x, object_t *y, object_t *z);
object_t *new_array(size_t size);
bool array_set(object_t *obj, size_t index, object_t *value);
object_t *array_get(object_t *obj, size_t index);
int obj_get_len(object_t *obj);

#endif
