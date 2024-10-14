#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#define MAX 50

typedef struct {

	char ime[MAX];
	char prezime[MAX];
	int bodovi;

}student;

int brojRedaka(char* datoteka);

int ucitaj(student* studenti, int brojStudenata, char* datoteka);

int ispisi(student* studenti, int brojStudenata, int maxBodovi);

int main() {

	char datoteka[MAX] = "studenti.txt";
	int maxBodovi = 50;

	int brojStudenata = brojRedaka(datoteka);
	if (brojStudenata <= 0) {
		printf("Greska kod ucitavanja datoteke / file prazan\n");
		return -1;
	}

	student* studenti = (student*)malloc(brojStudenata * sizeof(student));
	if (studenti == NULL) {
		printf("Greska kod alokacije");
		return -1;
	}

	ucitaj(studenti, brojStudenata, datoteka);

	ispisi(studenti, brojStudenata, maxBodovi);

	return 0;
}

int brojRedaka(char* datoteka) {

	int brojac = 0;
	char line[300] = { '\0' };

	FILE* fp;
	fp = fopen(datoteka, "r");

	if (fp == NULL) {
		printf("Greska u otvaranju dat. (brojRedaka)");
		return -1;
	}

	while (fgets(line, sizeof(line), fp)) {
		brojac++;
	}

	fclose(fp);

	return brojac;
}

int ucitaj(student* studenti, int brojStudenata, char* datoteka) {

	int i = 0;

	FILE* fp;
	fp = fopen(datoteka, "r");
	if (fp == NULL) {
		printf("Greska u otvaranju dat. (ucitaj)\n");
		return -1;
	}


	for (i = 0; i < brojStudenata; i++) {
		fscanf(fp, "%s %s %d", studenti[i].ime, studenti[i].prezime, &studenti[i].bodovi);
	}

	fclose(fp);

	return 0;
}

int ispisi(student* studenti, int brojStudenata, int maxBodovi) {

	int i = 0;
	double relativniBodovi = 0.0;


	printf("Ime:\tPrezime:\tApsolutni broj bodova:\tRelativni broj bodova:\n");
	for (i = 0; i < brojStudenata; i++) {
		relativniBodovi = studenti[i].bodovi / maxBodovi * 100;
		printf("%s\t%s\t%d\t%.2f\n", studenti[i].ime, studenti[i].prezime, studenti[i].bodovi, relativniBodovi);
	}

	return 0;
}
