/* main.c
 * from: Rewriting My Old Pascal Code in C
 *       https://www.youtube.com/watch?v=_SufQh6OIzs
 *       (https://www.youtube.com/@TsodingDaily)
 *
 * V1:
 * STOPED AT: 00:43:00 !!
 *
 * test compile: 'gcc -o main main.c -lm' --> 'build_main.sh'
 */

#include <stdio.h>
#include <string.h>

#include "./la.c"

#define TILE_WIDTH     128
#define TILE_HEIGHT    128
#define TILESET_WIDTH  (TILE_WIDTH * 4)
#define TILESET_HEIGHT (TILE_HEIGHT * 4)

RGB stripes(UV uv) {
	float n = 20.0f;
	Vec3f v = vec3f(sinf(uv.c[U] * n),
                    sinf((uv.c[U] + uv.c[V]) * n),
                    cosf(uv.c[V] * n));

	return vec3f_mul(vec3f_sum(v, vec3fs(1.0f)),
                     vec3fs(0.5f));
}


// MAIN -------------------------------------
int main(int argc, char **argv) {

	printf("It works!\n");

	return 0;
}

