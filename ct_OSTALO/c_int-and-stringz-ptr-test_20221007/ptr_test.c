#include <stdio.h>
#include <string.h>

void prnt(int);
void add_to_start(int *, int);

int main(int argc, char **argv) {

	int start = 0;
	prnt(start);

	add_to_start(&start, 5);
	prnt(start);


	return 0;
}


void prnt(int num) {
	printf("%d\n", num);
}



void add_to_start(int *recv, int num) {
	*recv += num;
}

