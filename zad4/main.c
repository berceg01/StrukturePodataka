#define _CRT_SECURE_NO_WARNINGS_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _element *position;
typedef struct _element{
	int koef;
	int eksp;

	position next;
} element;

position create(int koef, int eksp);

int main() {
	element x = {
		koef = 0;
		eksp = 0;

	}



	return 0;
 }

position create(int koef, int eksp) {
	position newelement = NULL;
	newelement = (position)malloc(sizeof(element));

	if (newelement == NULL) {
		printf("\Greska u alokaciji memorije!!\n");
	}


}