#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#define PERCENTAGE(V, T) (100 - (((T - V) * 100) / T))

#ifdef _WIN32
	#include <windows.h>
	#define CLEAR "cls"
#else
	#include <unistd.h>
	#define CLEAR "clear"
#endif

void my_wait(size_t secs) {
	#ifdef _WIN32
		Sleep(1000 * secs);
	#else
		sleep(secs);
	#endif
}

void print_progress(size_t count, size_t max) {
	const wchar_t prefix[] = L"Progress: [";
	const wchar_t suffix[] = L"]";
	const size_t prefix_length = sizeof(prefix) - 1;
	const size_t suffix_length = sizeof(suffix) - 1;
	wchar_t *buffer = calloc(100 + prefix_length + suffix_length + 1, 1);
	size_t i = 0;

	wcscpy(buffer, prefix);
	//wchar_t blk= L'█';                    // "\u2588" -- full block
	wchar_t blk= L'\u2588';                    // "\u2588" -- full block
	for (; i < 100; ++i) {
		// buffer[prefix_length + i] = i < PERCENTAGE(count, max) ? L'#' : L' ';
		buffer[prefix_length + i] = i < PERCENTAGE(count, max) ? blk : L' ';
	}

	wcscpy(&buffer[prefix_length + i], suffix);
	// printf("\b\r%c[2K\r%c", 27, buffer);
	wprintf(L"\r%s", buffer);
	fflush(stdout);
	free(buffer);
}

#define NUM_SECS 10

int main() {
	system(CLEAR);
	size_t num_secs = 1, max_secs = NUM_SECS;
	wprintf(L"%s\n", "");
	print_progress(0, max_secs);

	for (; num_secs <= max_secs; ++num_secs) {
		my_wait(1);
		print_progress(num_secs, max_secs);
	}
	wprintf(L"\n");

	return 0;
}

