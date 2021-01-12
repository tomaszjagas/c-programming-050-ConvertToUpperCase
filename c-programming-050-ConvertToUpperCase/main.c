#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define FILENAME "file.txt"
#define TEMPFILE "temp.txt"

int main() {
	FILE* fp = NULL;
	FILE* fp1 = NULL;

	char ch = 'a';

	fp = fopen(FILENAME, "r");

	if (fp == NULL) {
		return -1;
	}

	// create temp file
	fp1 = fopen(TEMPFILE, "w");

	if (fp1 == NULL) {
		return -1;
	}

	while ((ch = fgetc(fp)) != EOF) {
		if (islower(ch)) {
			ch = ch - 32;
		}
		fputc(ch, fp1);
	}

	fclose(fp);
	fclose(fp1);

	// rename temp file to file.txt file
	//rename(TEMPFILE, FILENAME);

	// remove temp file
	//remove(TEMPFILE);

	fp = fopen(TEMPFILE, "r");

	if (fp == NULL) {
		return -1;
	}

	while ((ch = fgetc(fp)) != EOF) {
		printf("%c", ch);
	}

	fclose(fp);
	fp = NULL;
	fp1 = NULL;

	return 0;
}