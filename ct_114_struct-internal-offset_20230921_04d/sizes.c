/*
 * sizes.c
 * 20230921_01 (d)
 * 20230922_02 (d)
 */
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>


int main(void) {


	printf("size of 'size_t':       %3ld bytes\n", sizeof(size_t));
	printf("size of 'unsigned int': %3ld bytes", sizeof(unsigned int)); printf(" (at least 2, usually 4)\n");
	printf("size of 'uint8_t':      %3ld byte\n", sizeof(uint8_t));
	printf("size of 'uint16_t':     %3ld bytes\n", sizeof(uint16_t));
	printf("size of 'uint32_t':     %3ld bytes\n", sizeof(uint32_t));
	printf("size of 'uint64_t':     %3ld bytes\n", sizeof(uint64_t));
	printf("---\n");
	printf("size of 'long':         %3ld bytes", sizeof(long)); printf(" (at least 4, usually 8)\n");
	printf("size of 'long long':    %3ld bytes\n", sizeof(long long));
	printf("size of 'float':        %3ld bytes\n", sizeof(float));
	printf("size of 'double':       %3ld bytes\n", sizeof(double));
	printf("size of 'long double':  %3ld bytes\n", sizeof(long double));
	printf("size of 'bool':         %3ld byte\n", sizeof(bool));
	printf("size of 'char':         %3ld byte\n", sizeof(char));
	printf("---\n");
	printf("size of '(void *)':     %3ld bytes \n", sizeof(void *));


	return 0;
}
