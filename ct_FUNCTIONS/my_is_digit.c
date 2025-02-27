#include <stdbool>

bool my_is_digit(char *c);

bool my_is_digit(char *c) {
	if ('0' <= *c <= '9') {
		return true;
	}
	return false;
}

