#include <stdio.h>

int my_is_digit(char *c);
unsigned long long my_strtol(char *c);

/* string to long */
unsigned long long my_strtol(char *c) {
	unsigned long long n = 0;
	while (my_is_digit(c)) {
		n = n*10 + *c - '0';
		c +=1;
	}
	return n;
}

int my_is_digit(char *c) {
	return ('0' <= *c && *c <= '9');
}

