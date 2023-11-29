/* main.c
 * from: Rewriting My Old Pascal Code in C
 *       https://www.youtube.com/watch?v=_SufQh6OIzs
 *       (https://www.youtube.com/@TsodingDaily)
 *
 * V5:
 * FINNISHED (main.c) at about 01:55:00
 * ... -> nobuild.c ... afterwards,
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

#define TILE_WIDTH_PX     256
#define TILE_HEIGHT_PX    256

#define ATLAS_WIDTH_TL 4
#define ATLAS_HEIGHT_TL 4

#define ATLAS_WIDTH_PX  (TILE_WIDTH_PX * ATLAS_WIDTH_TL)
#define ATLAS_HEIGHT_PX (TILE_HEIGHT_PX * ATLAS_HEIGHT_TL)

typedef uint32_t RGBA32;
typedef uint8_t BLTR;

typedef RGB (*Frag_Shader)(BLTR bltr, UV uv); // function pointer to a function that accepts UV as parameter and rturns RGB
                                   // changed in v5 to accept BLTR

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
//
// TODO: more wang tile ideas
// - Metaballs: http://en.wikipedia.org/wiki/Metaballs
//
//     t
//   +---+
// l |   | r
//   +---+
//     b
// bltr
// 0000 = 00
// 0001 = 01
// 0010 = 02
// 0011 = 03
// ...
// 1111 = 15
//
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


// v5: accept BLTR
void generate_tile32(uint32_t *pixels, size_t width, size_t height, size_t stride, BLTR bltr, Frag_Shader shader) {
	for (size_t y = 0; y < height; ++y) {         // start iterating by rows
		for (size_t x = 0; x < width; ++x) {      //       iterating by cols
			float u = (float) x / (float) width;
			float v = (float) y / (float) height;
			RGB p = shader(bltr, vec2f(u, v));    // v5
			pixels[y * stride + x] = make_rgba32(p.c[R], p.c[G], p.c[B]);
		}
	}
}


RGBA32 tile[TILE_WIDTH_PX * TILE_HEIGHT_PX];
RGBA32 atlas[ATLAS_WIDTH_PX * ATLAS_HEIGHT_PX];

// TODO: generate the random wang tile grid
// MAIN -------------------------------------
int main(int argc, char **argv) {

	// v5
	// BLTR = 0, 1, ... 15 (from v4: wang0000, wang0001, ... wang1111)
	// generate_tile32(tile, TILE_WIDTH_PX, TILE_HEIGHT_PX, TILE_WIDTH_PX, 1, wang);

	const char *output_file_path = "imgs/output5.png";

	// way-1
	// way-1 and way-2 are equivalent !!
	// better way: extract rows and cols from BLTR:
	// 1 loop = O(n); 2 nested loops = O(mxn) !!
	for(BLTR bltr = 0; bltr < 16; ++bltr) {
		size_t y = (bltr / ATLAS_WIDTH_TL) * TILE_WIDTH_PX;
		size_t x = (bltr % ATLAS_WIDTH_TL) * TILE_WIDTH_PX;
		
		printf("Generating god seed %.2f%% ...\n", bltr / 15.0f * 100.f);

		// <  stride  > = 12
		// ----TTTT---- =  4
		// 111122223333
		// 111122223333
		// 111122223333
		// 444455556666
		// 444455556666
		// 444455556666

	    generate_tile32(&atlas[y * ATLAS_WIDTH_PX + x], // start
				TILE_WIDTH_PX,                          // width
				TILE_HEIGHT_PX,                         // height
				ATLAS_WIDTH_PX,                         // stride
				bltr,                                   // BLTR
				wang);                                  // function pointer
	}

	#if 0
	// way-2
	// usual way
	for (size_t row=0; row<ATLAS_HEIGHT_TL; ++row) {
		for (size_t col=0; col<ATLAS_WIDTH_TL; ++col) {
			BLTR bltr = row * ATLAS_WIDTH_TL + col;
		}
	}
	#endif

	if (!stbi_write_png(output_file_path, ATLAS_WIDTH_PX, ATLAS_HEIGHT_PX, 4, tile, ATLAS_WIDTH_PX * sizeof(RGBA32))) {
		fprintf(stderr, "ERROR: could not save file %s: %s\n", output_file_path, strerror(errno));
		exit (1);
	}

	return 0;
}

