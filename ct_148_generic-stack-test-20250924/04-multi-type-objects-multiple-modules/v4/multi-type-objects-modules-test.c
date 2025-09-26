/*
 * filename: multi-type-objects-modules-test.c
 * from: C Programming and Memory Management - Full Course --> Objects
 *       https://www.youtube.com/watch?v=rJrd2QMVbGM
 * at:   03:11:00 / 04:43:47
 * ---
 * 20250925 v1 d
 * 20250926 v2 en
 * 20250926 v3 en -- single stb-style header
 * 20250926 v4 en -- universal obj_free function
 *                -- vec3_dist function
 * last: 20250926
 * STOPED on 20250924 at 03:35:30
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "mt_objects.h"

/* main */
int main(int argc, char **argv) {
	// printf("\n\t*** EVERYTHING SEEMS TO BE OK ***\n\n");

	printf("---\n");
	object_t *str1 = new_string("Gregor Redelonghi");
	printf("string object value:   %s\n", str1->data.v_string);

	/* v4 */
	obj_free(str1);

	object_t *fn1 = new_float(134);
	printf("float object value:    %f\n", fn1->data.v_float);
	free(fn1);

	object_t *int1 = new_integer(134);
	printf("integer object value:  %d\n", int1->data.v_int);
	free(int1);

	object_t *vec31 = new_vector3(
			new_integer(1),
			new_integer(4),
			new_integer(9));

	vector_t coord = vec31->data.v_vector3;
	printf("vector3 object value:  (%d, %d, %d)\n",
			coord.x->data.v_int,
			coord.y->data.v_int,
			coord.z->data.v_int);

	/* v4 */
	obj_free(vec31);

	printf("---\n");
	size_t fmem_num = 6;
	object_t *family1 = new_array(fmem_num);
	if (! array_set(family1, 0, new_string("Gregor Redelonghi")))      printf("[ERROR]\n");
	if (! array_set(family1, 1, new_string("Tadeja Mali Redelonghi"))) printf("[ERROR]\n");
	if (! array_set(family1, 2, new_string("Zala Redelonghi")))        printf("[ERROR]\n");
	if (! array_set(family1, 3, new_string("Mark Redelonghi")))        printf("[ERROR]\n");
	if (! array_set(family1, 4, new_string("Špela Redelonghi")))       printf("[ERROR]\n");
	if (! array_set(family1, 5, new_string("Sisi Redelonghi")))        printf("[ERROR]\n");

	for (int i = 0; i < fmem_num; i++) {
		printf("Family member %d: %s\n", i + 1, family1->data.v_array.elements[i]->data.v_string);
	}

	/* v4 */
	printf("---\n");
	size_t pos = 5;
	object_t *fmem4 = array_get(family1, pos - 1);
	printf("Family member #%ld using array_get function: %s \n", pos, fmem4->data.v_string);

	/* v4 */
	obj_free(family1);
	printf("---\n");

	object_t *T1 = new_vector3(
			new_integer(1),
			new_integer(4),
			new_integer(8));

	object_t *T2 = new_vector3(
			new_integer(4),
			new_integer(1),
			new_integer(2));

	printf("Distance between T1(1,4,8) and T2(4,1,2) is: %f\n", vec3_dist(T1, T2));

	/* v4 */
	obj_free(T1);
	obj_free(T2);
	printf("---\n");


	printf("\n");

	return 0;
} /* END main */

