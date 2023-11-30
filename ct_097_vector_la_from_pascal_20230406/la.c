/* la.c (linear algebra library) -- src/la_3.c
 * vector_operations_optim_2.c
 * from: Rewriting My Old Pascal Code in C
 *       https://www.youtube.com/watch?v=_SufQh6OIzs
 *       (https://www.youtube.com/@TsodingDaily)
 *
 * if with main: compile with -lm flag, because math.powf() function is in use (Make file):
 *   $> make
 * or:
 * test if it works just as a library:
 *   $> gcc -c la.c
 *
 *   V4
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

#define X 0
#define Y 1
#define Z 2
#define W 3

#define U 0
#define V 1

#define R 0
#define G 1
#define B 2
#define A 3

typedef struct { float c[2]; } Vec2f;    // 2D vectors: (x, y)
typedef struct { float c[3]; } Vec3f;    // 3D vectors: (x, y, z)
typedef struct { float c[4]; } Vec4f;    // 4D vectors: (R,G,B,A)

typedef Vec2f UV;
typedef Vec3f RGB;
typedef Vec4f RGBA;

float lerpf(float,float,float);

/** linear interpolation of floats */
float lerpf(float a, float b, float t) {
	return a + (b - a) * t;
}

// *** functions initializations for 2D vectors  *** #########################################
// vec2f constructor (function)
Vec2f vec2f(float x, float y) {
	/*
	 * Vec2f v;
	 * v.c[X] = x;
	 * v.c[Y] = y;
	 * equals to:
	 */
	Vec2f v = {{x, y}};
	return v;
}

// Vec2f scaler constructor
Vec2f vec2fs(float x) {
	return vec2f(x, x);
}

Vec2f vec2f_sum(Vec2f a, Vec2f b) {
	/*
	 * since 'a' and 'b' are parameters copied by value, they get allocated on the stack
	 * so 'a' can be used as return value and code can be changed to one below the current:
	 *
	 * Vec2f c;
	 * for (size_t i=0; i<2; ++i) c.c[i] = a.c[i] + b.c[i];
	 * return c;
	 */

	for (size_t i=0; i<2; ++i) a.c[i] += b.c[i];
	return a;
}

Vec2f vec2f_sub(Vec2f a, Vec2f b) {
	for (size_t i=0; i<2; ++i) a.c[i] -= b.c[i];
	return a;
}

Vec2f vec2f_mul(Vec2f a, Vec2f b) {
	for (size_t i=0; i<2; ++i) a.c[i] *= b.c[i];
	return a;
}

Vec2f vec2f_div(Vec2f a, Vec2f b) {
	for (size_t i=0; i<2; ++i) a.c[i] /= b.c[i];
	return a;
}

Vec2f vec2f_max(Vec2f a, Vec2f b) {
	/*
	 * instead of multiline expression - turn it ino single line expression:
	 *
	 * for (size_t i=0; i<2; ++i) {
	 * 	if (a.c[i] < b.c[i]) 
	 * 		a.c[i] = b.c[i];
	 * }
	 */

	for (size_t i=0; i<2; ++i) if (a.c[i] < b.c[i]) a.c[i] = b.c[i];
	return a;
}

Vec2f vec2f_min(Vec2f a, Vec2f b) {
	for (size_t i=0; i<2; ++i) if (a.c[i] > b.c[i]) a.c[i] = b.c[i];
	return a;
}

float vec2f_sqrlen(Vec2f a) {
	// for comparrisons like: vec2f_len(a) < r * r
	// if actual length is needed: sqrtf(vec2f_len(a))
	float sqrlen = 0.0f;
	for (size_t i=0; i<2; ++i) sqrlen += a.c[i] * a.c[i];
	return sqrlen;
}

// v4
float vec2f_len(Vec2f a) {
	return sqrtf(vec2f_sqrlen(a));
}

/** linear interpolation of Vec2f structs */
Vec2f vec2f_lerp(Vec2f a, Vec2f b, Vec2f t) {
	for (size_t i=0; i<2; ++i) a.c[i] = lerpf(a.c[i], b.c[i], t.c[i]); 
	return a;
}
Vec2f vec2f_sqrt(Vec2f a) {
	for (size_t i=0; i<2; ++i) a.c[i] = sqrtf(a.c[i]);
	return a;
}

Vec2f vec2f_pow(Vec2f base, Vec2f exp) {
	for (size_t i=0; i<2; ++i) base.c[i] = powf(base.c[i], exp.c[i]);
	return base;
}

// *** functions initializations for 3D vectors  *** #########################################
// vec3f constructor (function)
Vec3f vec3f(float x, float y, float z) {
	Vec3f v = {{x, y, z}};
	return v;
}

// Vec3f scaler constructor
Vec3f vec3fs(float x) {
	return vec3f(x, x, x);
}

Vec3f vec3f_sum(Vec3f a, Vec3f b) {
	for (size_t i=0; i<3; ++i) a.c[i] += b.c[i];
	return a;
}

Vec3f vec3f_sub(Vec3f a, Vec3f b) {
	for (size_t i=0; i<3; ++i) a.c[i] -= b.c[i];
	return a;
}

Vec3f vec3f_mul(Vec3f a, Vec3f b) {
	for (size_t i=0; i<3; ++i) a.c[i] *= b.c[i];
	return a;
}

Vec3f vec3f_div(Vec3f a, Vec3f b) {
	for (size_t i=0; i<3; ++i) a.c[i] /= b.c[i];
	return a;
}

Vec3f vec3f_max(Vec3f a, Vec3f b) {
	for (size_t i=0; i<3; ++i) if (a.c[i] < b.c[i]) a.c[i] = b.c[i];
	return a;
}

Vec3f vec3f_min(Vec3f a, Vec3f b) {
	for (size_t i=0; i<3; ++i) if (a.c[i] > b.c[i]) a.c[i] = b.c[i];
	return a;
}

float vec3f_sqrlen(Vec3f a) {
	float sqrlen = 0.0f;
	for (size_t i=0; i<3; ++i) sqrlen += a.c[i] * a.c[i];
	return sqrlen;
}

// v4
float vec3f_len(Vec3f a) {
	return sqrtf(vec3f_sqrlen(a));
}

/** linear interpolation of Vec3f structs */
Vec3f vec3f_lerp(Vec3f a, Vec3f b, Vec3f t) {
	for (size_t i=0; i<3; ++i) a.c[i] = lerpf(a.c[i], b.c[i], t.c[i]); 
	return a;
}

Vec3f vec3f_sqrt(Vec3f a) {
	for (size_t i=0; i<3; ++i) a.c[i] = sqrtf(a.c[i]);
	return a;
}

Vec3f vec3f_pow(Vec3f base, Vec3f exp) {
	for (size_t i=0; i<3; ++i) base.c[i] = powf(base.c[i], exp.c[i]);
	return base;
}

// *** functions initializations for 4D vectors  *** #########################################
// vec4f constructor (function)
Vec4f vec4f(float x, float y, float z, float w) {
	Vec4f v = {{x, y, z, w}};
	return v;
}

// Vec4f scaler constructor
Vec4f vec4fs(float x) {
	return vec4f(x, x, x, x);
}

Vec4f vec4f_sum(Vec4f a, Vec4f b) {
	for (size_t i=0; i<4; ++i) a.c[i] += b.c[i];
	return a;
}

Vec4f vec4f_sub(Vec4f a, Vec4f b) {
	for (size_t i=0; i<4; ++i) a.c[i] -= b.c[i];
	return a;
}

Vec4f vec4f_mul(Vec4f a, Vec4f b) {
	for (size_t i=0; i<4; ++i) a.c[i] *= b.c[i];
	return a;
}

Vec4f vec4f_div(Vec4f a, Vec4f b) {
	for (size_t i=0; i<4; ++i) a.c[i] /= b.c[i];
	return a;
}

Vec4f vec4f_max(Vec4f a, Vec4f b) {
	for (size_t i=0; i<4; ++i) if (a.c[i] < b.c[i]) a.c[i] = b.c[i];
	return a;
}

Vec4f vec4f_min(Vec4f a, Vec4f b) {
	for (size_t i=0; i<4; ++i) if (a.c[i] > b.c[i]) a.c[i] = b.c[i];
	return a;
}

float vec4f_sqrlen(Vec4f a) {
	float sqrlen = 0.0f;
	for (size_t i=0; i<4; ++i) sqrlen += a.c[i] * a.c[i];
	return sqrlen;
}

// v4
float vec4f_len(Vec4f a) {
	return sqrtf(vec4f_sqrlen(a));
}

/** linear interpolation of Vec4f structs */
Vec4f vec4f_lerp(Vec4f a, Vec4f b, Vec4f t) {
	for (size_t i=0; i<4; ++i) a.c[i] = lerpf(a.c[i], b.c[i], t.c[i]); 
	return a;
}

Vec4f vec4f_sqrt(Vec4f a) {
	for (size_t i=0; i<4; ++i) a.c[i] = sqrtf(a.c[i]);
	return a;
}

Vec4f vec4f_pow(Vec4f base, Vec4f exp) {
	for (size_t i=0; i<4; ++i) base.c[i] = powf(base.c[i], exp.c[i]);
	return base;
}

#if 0
// MAIN // ----------------------------------------------------------------------------------
int main(void) {
	printf("It works!\n");

	return 0;
}
// MAIN // ----------------------------------------------------------------------------------
#endif

