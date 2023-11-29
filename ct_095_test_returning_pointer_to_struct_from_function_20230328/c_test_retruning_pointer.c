/*
 * from: c_returning-a-pointer-to-a-structure-from-a-function_20230328.txt
 * ---
 * changes: 
 *        - printf_s() changed to printf() with same signiture
 *        - scanf_s() changed to scanf() with signiture adaptation
 */

#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Date Date;
typedef struct Family Family;

// Function prototypes
Family *get_person(void);                                        // Input function
void show_people(bool forwards, Family *pfirst, Family *plast);  // Output function
void release_memory(Family *pfirst);                             // Release heap memory

struct Date {
	int day;
	int month;
	int year;
};

struct Family {               // Family structure declaration
	Date dob;
	char name[20];
	char father[20];
	char mother[20];
	Family *next;             // Pointer to next structure
	Family *previous;         // Pointer to previous structure
};

int main(void) {
	Family *first = NULL;                 // Pointer to first person
	Family *current = NULL;               // Pointer to current person
	Family *last = NULL;                  // Pointer to previous person
	char more = '\0';                     // Test value for ending input

	while (true) {
		printf("\nDo you want to enter details of a %s person (Y or N)? ",
				first != NULL ? "nother" : "");
		// scanf_s(" %c", &more, sizeof(more));
		scanf(" %c", &more);
		if (tolower(more) == 'n')
			break;

		current = get_person();

		if (first == NULL) {
			first = current;              // Set pointer to first Family
		} else {
			last->next = current;         // Set next address for previous Family
			current->previous = last;     // Set previous address for current
		}
		last = current;                   // Remember for next iteration
	}

	show_people(true, first, last);       // Tell them what we know
	release_memory(first);
	first = last = NULL;
	return 0;
}

Family *get_person(void) {
	Family *temp = (Family*)malloc(sizeof(Family));

	printf("\nEnter the name of the person: ");
	// scanf_s("%s", temp->name, sizeof(temp->name));
	scanf("%s", temp->name);

	printf("\nEnter %s's date of birth (day month year); ", temp->name);
	// scanf_s("%d %d %d", &temp->dob.day, &temp->dob.month, &temp->dob.year);
	scanf("%d %d %d", &temp->dob.day, &temp->dob.month, &temp->dob.year);

	printf("\nWho is %s's father? ", temp->name);
	// scanf_s("%s", temp->father, sizeof(temp->father));
	scanf("%s", temp->father);

	printf("\nWho is %s's mother? ", temp->name);
	// scanf_s("%s", temp->mother, sizeof(temp->mother));
	scanf("%s", temp->mother);

	temp->next = temp->previous = NULL;     // Set pointer members to NULL

	return temp;                            // Return address of Family structure
}

void show_people(bool forwards, Family *pfirst, Family *plast) {
	printf("\n");
	for (Family *pcurrent = forwards ? pfirst : plast;
			pcurrent != NULL;
			pcurrent = forwards ? pcurrent->next : pcurrent->previous)
	{
		printf("%s was born %d/%d/%d and has %s and %s as parents.\n",
				pcurrent->name, pcurrent->dob.day, pcurrent->dob.month,
				pcurrent->dob.year, pcurrent->father, pcurrent->mother);
	}
}

void release_memory(Family *pfirst) {
	Family *pcurrent = pfirst;
	Family *temp = NULL;
	while (pcurrent) {
		temp = pcurrent;
		pcurrent = pcurrent->next;
		free(temp);
	}
}

