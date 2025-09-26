/*
 * filename: mt_objects.h
 * 20250926 v2 en
 * 20250926 v3 en (single stb-style header)
 * 20250926 v4 en (universal obj_free function)
 * last: 20250926
 */

#ifndef _MT_OBJECTS_H
#define _MT_OBJECTS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/* structures */

/* forward declared struct
 * it will be used in circular dependency between:
 * object_t -> object_data_t -> vector_t
 */

/* must be declared before object_data_t union whwere it is used -- size must be known! */
typedef struct Object object_t;

typedef struct Vector {
	object_t *x;
	object_t *y;
	object_t *z;
} vector_t;

typedef struct Array {
	size_t size;
	object_t **elements;
} array_t;

typedef enum Object_kind {
	INTEGER,
	FLOAT,
	STRING,
	VECTOR3,
	ARRAY
} object_kind_t;

typedef union Object_data {
	int          v_int;
	float      v_float;
	char     *v_string;
	vector_t v_vector3;
	array_t    v_array;
} object_data_t;

typedef struct Object {
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
float vec3_dist(object_t *T1, object_t *T2);

/* v4 */
void obj_free(object_t *obj);

/* =============== implementation ================ */
#define MT_OBJECT_IMPLEMENTATION

#ifdef MT_OBJECT_IMPLEMENTATION

/* function new_integer */
object_t *new_integer(int value) {
	object_t *obj = malloc(sizeof(object_t));
	if (obj == NULL) { return NULL; }
	
	obj->kind = INTEGER;
	obj->data.v_int = value;

	return obj;
}

/* function new_float */
object_t *new_float(int value) {
	object_t *obj = malloc(sizeof(object_t));
	if (obj == NULL) { return NULL; }
	
	obj->kind = FLOAT;
	obj->data.v_float = value;

	return obj;
}

/* function new_string */
object_t *new_string(char *value) {
	object_t *obj = malloc(sizeof(object_t));
	if (obj == NULL) { return NULL; }
	
	obj->kind = STRING;
	obj->data.v_string = malloc(strlen(value) + 1);
	if (obj->data.v_string == NULL) { return NULL; }

	strcpy(obj->data.v_string, value);

	return obj;
}

/* function new_vector3
 * --------------------
 * object than can hold reference to another object
 * it is a collection type that holds other types
 */
object_t *new_vector3(object_t *x, object_t *y, object_t *z) {
	if (x == NULL || y == NULL || z == NULL) { return NULL; }

	object_t *obj = malloc(sizeof(object_t));
	if (obj == NULL) { return NULL; }
	
	obj->kind = VECTOR3;
	obj->data.v_vector3.x = x;
	obj->data.v_vector3.y = y;
	obj->data.v_vector3.z = z;
	return obj;
}

/* function new_array */
object_t *new_array(size_t size) {
	object_t *obj = malloc(sizeof(object_t));
	if (obj == NULL) { return NULL; }
	
	obj->kind = ARRAY;

	object_t **elements = calloc(size, sizeof(object_t *));
	if (elements == NULL) { return NULL; }
	array_t array = { .size = size, .elements = elements };

	obj->data.v_array = array;

	return obj;
}

/* function array_set */
bool array_set(object_t *obj, size_t index, object_t *value) {
	if (obj == NULL || value == NULL) { return false; }
	if (obj->kind != ARRAY) { return false; }
	if (obj->data.v_array.size <= index) { return false; }

	obj->data.v_array.elements[index] = value;
	return true;
}

/* function array_get */
object_t *array_get(object_t *obj, size_t index) {
	if (obj == NULL ) { return false; }
	if (obj->kind != ARRAY) { return false; }
	if (obj->data.v_array.size <= index) { return false; }

	return obj->data.v_array.elements[index];
}

/* function obj_len */
int obj_get_len(object_t *obj) {
	if (obj == NULL) { return -1; }

	switch (obj->kind) {
		case INTEGER: return 1;
		case FLOAT: return 1;
		case STRING: return strlen(obj->data.v_string);
		case VECTOR3: return 3;
		case ARRAY: return obj->data.v_array.size;
		default: return -1;
	}
}

/* v4 */
/* function obj_free */
void obj_free(object_t *obj) {
	switch(obj->kind) {
		case INTEGER:
		case FLOAT:

		case STRING:
			if (obj == NULL) { return; }
			free(obj->data.v_string);
			free(obj);
			break;

		case VECTOR3:
			if (obj == NULL) { return; }
			vector_t coord = obj->data.v_vector3;
			free(coord.x);
			free(coord.y);
			free(coord.z);
			free(obj);
			break;

		case ARRAY:
			if (obj == NULL) { return; }
			size_t fmem_num = obj->data.v_array.size;
			for (int i = 0; i < fmem_num; i++) {
				free(obj->data.v_array.elements[i]->data.v_string);
				free(obj->data.v_array.elements[i]);
			}
			free(obj->data.v_array.elements);
			free(obj);
			break;

		default:
			break;
	}
}

/* function dist */
float vec3_dist(object_t *T1, object_t *T2) {
	float result;
	vector_t crd1 = T1->data.v_vector3;
	vector_t crd2 = T2->data.v_vector3;
	result = sqrtf(powf(((float)(crd2.x->data.v_int) - (float)(crd1.x->data.v_int)), 2.0) + \
				   powf(((float)(crd2.y->data.v_int) - (float)(crd1.y->data.v_int)), 2.0) + \
				   powf(((float)(crd2.z->data.v_int) - (float)(crd1.z->data.v_int)), 2.0));
	return result;
}

#endif
/* =============== implementation ================ */

#endif
