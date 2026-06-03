/* filenema: xor-tricks-find-dups.c
 * from: Programming Party Tricks (https://www.youtube.com/@Tsoding)
 *       https://www.youtube.com/watch?v=4KdvcQKNfbQ
 * ---
 * v1: 20251209 en
 * v2: 20251209 en
 * v3: 20251209 en
 * last: 20251209
 */
#include <stdio.h>
#include <string.h>


/*
 * v3
 * bin/xor-tricks-find-dups-v2 | shuf | paste -sd ','
 * --> xs[]
 */
int xs[] = {70,83,22,94,74,76,28,95,16,13,32,21,18,90,15,77,40,3,72,8,80,69,24,88,20,47,98,73,84,7,2,19,35,\
            54,27,29,53,44,97,51,33,66,75,31,39,46,63,100,52,41,34,60,64,38,67,59,38,89,25,91,71,17,4,37,26,\
            56,68,9,50,87,23,61,55,82,58,86,43,1,36,42,65,81,57,49,96,11,93,62,45,10,12,92,48,85,79,5,14,30,\
            78,6,99};

/*
 * find dups with this property of XOR:
 * a^b^b == a
 */
int main(int argc, char **argv) {

	int x = 0;
	for (int i = 1; i <= 100; ++i) {
		x ^= i;
	}
	// x=1^2^3^4 ...

	size_t n = sizeof(xs)/sizeof(xs[0]);
	for (int i = 0; i < n; ++i) {
		x ^= xs[i];
		// x=1^3^4 ...
		// x=1^4^5 ...
		// ...
		// x=0^y --> x=y
	}
	printf("Dup: %d\n", x);

	return 0;
}

