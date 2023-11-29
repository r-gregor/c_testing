// from: https://stackoverflow.com/questions/46140235/c-how-to-program-a-terminal-matrix-effect

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
char characters [83] = {'A', ' ', 'B', 'C', ' ', 'D', 'E', ' ', 'F', 'G', ' ', 'H', 'I', ' ', 'J', 'K', 'L', ' ', 'M', 'N', 'O', ' ', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', ' ', 'W', 'X', 'Y', 'Z', 'a', ' ', 'b', 'c', 'd', 'e', 'f', 'g', 'h', ' ', 'i', 'j', 'k', 'l', 'm', ' ', 'n', 'o', 'p', 'q', 'r', ' ', 's', 't', 'u', ' ', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', ' ', '9', '!', '%', '&', ' ', '?', '#', '*'};
int i = 0;
int index_array;
srand(time(0));

struct timespec tim, tim2;
tim.tv_sec = 0;
tim.tv_nsec = 10000000L;
for (i=0; i < 20; i++){
	index_array = (rand()%83)+1;
	printf("%c", characters[index_array]);
	fflush(stdout);
	nanosleep(&tim, &tim2);
}
printf("\n");
main();
}
