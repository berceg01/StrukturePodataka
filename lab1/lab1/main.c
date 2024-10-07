#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 1024

int ReadRows(const char* fileName);

main() {
	
	int numberOfRows = 0;
	numberOfRows = ReadRows("dat.txt");
	
	return 0;

}

int ReadRows(const char* fileName) {
	int nurmberOfRow = 0;
	FILE* fp = NULL;
	char buffer[MAX] = {'\0'};
	fp = fopen(fileName, "r");
	if (!fp) {
		return -1;
	}

	while (!feof(fp)) {
		fgets()
	}
}