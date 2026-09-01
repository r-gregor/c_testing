#ifndef MY_LIBRARY_
#define MY_LIBRARY_

typedef struct {
	char *contents;
	unsigned int size;
	unsigned int idx;
} String_View;

unsigned int count = 0;

String_View SV_init(char *string_literal) {
	return (String_View) {
		.contents = string_literal,
		.size     = strlen(string_literal),
		.idx      = ++count,
	};
}

void SV_print(String_View *sv) {
	printf("string view sv-%02d: \"%.*s\"\n", sv->idx, sv->size, sv->contents);
	printf("sv-%02d length:       %d\n", sv->idx, sv->size);
}

#endif

