/*
 * filename: get-process-info.c
 * from: https://www.quora.com/How-can-I-write-a-C-program-to-print-the-information-of-the-current-process-from-the-file-proc
 */

#include <stdio.h>

int main() {
	FILE *fp;
	char buf[ 128 ];

	if( !(fp = fopen("/proc/self/status", "r")) ) {
		fprintf(stderr, "Can't open /proc/self/status\n" );
		return 1;
	}

	while( fgets( buf, sizeof(buf), fp ) ) {
		printf("%s", buf );
	}
	fclose( fp );
	return 0;
}

