/*
 * check_for_subs_in_wcstr.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>
#include <wctype.h>
#include <limits.h>
#include <stdbool.h>

// typedef struct Person1 {
// 	wchar_t *name;
// 	int age;
// } Person1;


typedef struct Person2 {
	wchar_t name[256];
	int age;
} Person2;


// void printPerson1(Person1 *person1);
void printPerson2(Person2 *person2);
bool printIfContains(Person2 *person2, wchar_t *subs);

// Person1 **persons1;
Person2 *persons2;
// size_t pcount1 = 0;


int main(int argc, char **argv) {

	setlocale(LC_ALL, "sl_SI.utf-8");

	// persons1 = malloc(sizeof(Person1 *) * 15);
	persons2 = malloc(sizeof(Person2) * 15);
	size_t pcount2 = 0;

	// Person1 p1 = {L"Gregor Redelonghi", 56};
	// Person1 p2 = {L"Tadeja Mali Redelonghi", 56};
	// Person1 p3 = {L"Mark Redelonghi", 56};
	// Person1 p4 = {L"Zala Redelonghi", 56};
	// Person1 p5 = {L"Špela Redelonghi", 56};
	// Person1 p6 = {L"Sisi Redelonghi", 56};

	Person2 p1 = {L"Gregor Redelonghi", 56};
	Person2 p2 = {L"Tadeja Mali Redelonghi", 54};
	Person2 p3 = {L"Mark Redelonghi", 25};
	Person2 p4 = {L"Zala Redelonghi", 28};
	Person2 p5 = {L"Špela Redelonghi", 16};
	Person2 p6 = {L"Sisi Redelonghi", 5};

	persons2[pcount2++] = p1;
	persons2[pcount2++] = p2;
	persons2[pcount2++] = p3;
	persons2[pcount2++] = p4;
	persons2[pcount2++] = p5;
	persons2[pcount2++] = p6;

	for (size_t i = 0; i < pcount2; ++i) {
		printPerson2(&persons2[i]);
	}
	
	wprintf(L"------------------------------------\n");

	bool contains = false;
	wchar_t parts[256] = {L'0'};
	if (argc == 2) {
		mbstowcs(parts, argv[1], 256);
	} else {
		wcscpy(parts, L"ela");
	}

	for (size_t i = 0; i < pcount2; ++i) {
		if(printIfContains(&persons2[i], parts)) contains = true;
	}
	if (contains == false) wprintf(L"No such name\n");



	return 0;
}


// void printPerson1(Person1 *person1) {
// 	wprintf(L"%-30ls", person1->name);
// 	wprintf(L"%-5ld\n", person1->age);
// }

void printPerson2(Person2 *person2) {
	wprintf(L"%-30ls", person2->name);
	wprintf(L"%-5ld\n", person2->age);
}

bool printIfContains(Person2 *person2, wchar_t *subs) {
	if (wcsstr(person2->name, subs) != NULL) {
		printPerson2(person2);
		return true;
	}
	return false;
}

