#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50

struct _person;
typedef struct _person *position;
typedef struct _person {

	char name[MAX_SIZE];
	char lastName[MAX_SIZE];
	int birthYear;

	position next;
}Person;

position CreatePerson(char *name, char *lastName, int birthYear) {

	position newPerson = NULL;
	newPerson = (position)malloc(sizeof(Person));
	if (newPerson == NULL) {
		printf("Greška u mallocu\n");
		return NULL;
	}

	strcpy(newPerson->name, name);
	strcpy(newPerson>surname)

}

int main() {

	Person head = {
	.name = {0},
	.lastName = {0},
	.birthYear = 0,
	.next = NULL 
	};


	return 0;

}

int PrintList(position first) {
	position temp = NULL;
	temp = first;

	while (temp != NULL) {
		printf("%s %s %d", temp->name, temp->lastName, temp->birthYear);
		temp = temp->next;
	}

	return EXIT_SUCCESS;
}

int AppendList(position head, cahr*, char*, int) {

	position newPerson = NULL;
	position last = NULL;
	newPerson = CreatePerson(name, lastname, birthYear);
	if (!newPerson) {
		printf("Failed in person creation!");
		return - 1;
	}

	last = FindLast(head);

	last->next = newPerson;


	return EXIT_SUCCESS;

}

position FindLast(position head) {

	position last = NULL;
	last = head;
	while (last->next != NULL) {
		last = last->next;
	}

	return last;
}

int InsertAfter(position prev, position newPerson) {
	newPerson->next = prev.next;
	last->next = newPerson;
}

position FindPerson(position first, char *surname) {
	position temp=NULL;
	temp = first;

	while (temp) {
		if (strcmp(surname, temp->surname) == 0)
			return temp;
		temp = temp->next;
	}

	return NULL;
}

int Delete(position head, char* name) {
	
	position prev = head;
	position toDelete = NULL;

	prev = FindPrev(head, name);

	toDelete = prev->next;
	prev->next = toDelete;
	free(toDelete);

	return EXIT_SUCCESS;
}

position FindPrev(position head, char* name) {
	position temp0head;

	while
}