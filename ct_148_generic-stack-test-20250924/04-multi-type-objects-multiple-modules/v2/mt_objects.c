/*
 * filename: mt_objects.c
 * 20250926 v2 en
 * last: 20250926
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "mt_objects.h"

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

/* v2 */
/* function obj_free_string */
void obj_free_string(object_t *string) {
	if (string == NULL) { return; }
	free(string->data.v_string);
	free(string);
}

/* function obj_free_vesctor3 */
void obj_free_vesctor3 (object_t *vector3) {
	if (vector3 == NULL) { return; }
	vector_t coord = vector3->data.v_vector3;
	free(coord.x);
	free(coord.y);
	free(coord.z);

	free(vector3);
}

/* function obj_free_array */
void obj_free_array(object_t *array) {
	if (array == NULL) { return; }
	size_t fmem_num = array->data.v_array.size;
	for (int i = 0; i < fmem_num; i++) {
		free(array->data.v_array.elements[i]->data.v_string);
		free(array->data.v_array.elements[i]);
	}
	free(array->data.v_array.elements);
	free(array);
}

