/* main.c
 * from: Rewriting My Old Pascal Code in C
 *       https://www.youtube.com/watch?v=_SufQh6OIzs
 *       (https://www.youtube.com/@TsodingDaily)
 *
 * V4:
 * STOPPED AT: 
 *
 * test compile: 'gcc -o main main.c -lm' --> 'build_main.sh'
 *
 * [**1]
 * gamma correction: watch youtube: minutes physics colors ... https://www.youtube.com/watch?v=LKnqECcg6Gw
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>

// must be defined before la.c !!
/*
 * get stb_image_ ...
 * wget "https://raw.githubusercontent.com/nothings/stb/master/stb_image_write.h"
 */
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include "./la.c"

#define TILE_WIDTH     512
#define TILE_HEIGHT    512
#define TILESET_WIDTH  (TILE_WIDTH * 4)
#define TILESET_HEIGHT (TILE_HEIGHT * 4)

typedef RGB (*Frag_Shader)(UV uv); // function pointer to a function that accepts UV as parameter and rturns RGB
typedef uint32_t RGBA32;
typedef uint8_t BLTR;

RGBA32 make_rgba32(float r, float g, float b) {
	return (((uint32_t) (b * 255.0)) << 16) |
	       (((uint32_t) (g * 255.0)) << 8) |
	        (uint32_t) (r * 255.0) |
	        0xFF000000;
}

// shader like functions that accepts u,v coordinates
RGB stripes(UV uv) {
	float n = 20.0f;
	Vec3f v = vec3f(sinf(uv.c[U] * n),
                    sinf((uv.c[U] + uv.c[V]) * n),
                    cosf(uv.c[V] * n));

	return vec3f_mul(vec3f_sum(v, vec3fs(1.0f)),
                     vec3fs(0.5f));
}


// japan flag
RGB japan(UV uv) {
	float r = 0.25;
	int a = vec2f_sqrlen(vec2f_sub(vec2fs(0.5f), uv)) > r * r;
	return vec3f(1.0f, (float) a, (float) a);
}

// v4
// wang tiles
RGB wang(BLTR bltr, UV uv) {
	float r = 0.50f;
	static const RGB colors[] = {
		
		#if 0
		vec3f(1.0f, 0.0f, 0.0f), // 0   // cmpl error: initializer element is not constatnt
		vec3f(0.0f, 1.0f, 1.0f), // 1   // so: vec3f(1.0f, 0.0f, 0.0f) --> {{1.0f, 0.0f, 0.0f}}

		// vec3f(1.0f, 1.0f, 0.0f), // 0
		// vec3f(0.0f, 0.0f, 1.0f), // 1

		// vec3f(0.0f, 1.0f, 0.0f), // 0
		// vec3f(1.0f, 0.0f, 1.0f), // 1

		// vec3f(0.0f, 0.0f, 0.0f), // 0
		// vec3f(1.0f, 1.0f, 1.0f) // 1
		#endif

		{{1.0f, 0.0f, 0.0f}}, // 0
		{{0.0f, 1.0f, 1.0f}}, // 1

		// {{1.0f, 1.0f, 0.0f}}, // 0
		// {{0.0f, 0.0f, 1.0f}}, // 1

		// {{0.0f, 1.0f, 0.0f}}, // 0
		// {{1.0f, 0.0f, 1.0f}}, // 1

		// {{0.0f, 0.0f, 0.0f}}, // 0
		// {{1.0f, 1.0f, 1.0f}}  // 1
	};
	static_assert(sizeof(colors) / sizeof(colors[0]) == 2, "colors array must have exactly 2 elements");

	RGB result = vec3fs(0.0f);
	static const Vec2f sides[4] = { // cmpl error: initializer element is not constatnt
		#if 0
		vec2f(1.0f, 0.5f), // r
		vec2f(0.5f, 0.0f), // t
		vec2f(0.0f, 0.5f), // l
		vec2f(0.5f, 1.0f), // b
		#endif

		{{1.0f, 0.5f}}, // r
		{{0.5f, 0.0f}}, // t
		{{0.0f, 0.5f}}, // l
		{{0.5f, 1.0f}}  // b
	};

	for (size_t i=0; i<4; ++i) {
		Vec2f p = sides[i];
		float t = 1.0f - fminf((vec2f_len(vec2f_sub(p, uv)) / r), 1.0f);
		result = vec3f_lerp(result, colors[bltr & 1], vec3fs(t));
		bltr = bltr >> 1;
	}

	// [**1] gamma correction
	return vec3f_pow(result, vec3fs(1.0f / 2.2f));

}

// v4
// test
RGB wang0000(UV uv) {
	return wang(0, uv);
}

RGB wang0001(UV uv) {
	return wang(1, uv);
}

RGB wang1111(UV uv) {
	return wang(15, uv);
}

void generate_image32(uint32_t *pixels, size_t width, size_t height, size_t stride, Frag_Shader shader) {
	for (size_t y = 0; y < height; ++y) {     // start iterating by rows
		for (size_t x = 0; x < width; ++x) {  //       iterating by cols
			float u = (float) x / (float) width;
			float v = (float) y / (float) height;
			RGB p = shader(vec2f(u, v));
			pixels[y * stride + x] = make_rgba32(p.c[R], p.c[G], p.c[B]);
		}
	}
}


RGBA32 tile[TILE_WIDTH * TILE_HEIGHT];

// MAIN -------------------------------------
int main(int argc, char **argv) {

	// v4
	// generate_image32(tile, TILE_WIDTH, TILE_HEIGHT, TILE_WIDTH, stripes);
	// generate_image32(tile, TILE_WIDTH, TILE_HEIGHT, TILE_WIDTH, japan);
	generate_image32(tile, TILE_WIDTH, TILE_HEIGHT, TILE_WIDTH, wang1111);

	const char *output_file_path = "imgs/output4.png";
	if (!stbi_write_png(output_file_path, TILE_WIDTH, TILE_HEIGHT, 4, tile, TILE_WIDTH * sizeof(RGBA32))) {
		fprintf(stderr, "ERROR: could not save file %s: %s\n", output_file_path, strerror(errno));
		exit (1);
	}

	return 0;
}

