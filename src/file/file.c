/*
 * file.c
 * Last Change:  2014-04-28
 * Maintainer:   Lucas de Sena <contact@seninha.net>
 * License:      This file is placed in public domain.
 */

#define _FILE_SERVER

#include <file/file.h>

void arrayShuffle(void *arr, size_t n, size_t size) { // {{{1
	char * aux;
	char * array;

	array = (char *) arr;
	aux = (char *) malloc(size);

	size_t i, j;
	for (i = n-1; i + 1 > 0; --i) {
		j = rand() % (i+1);

		memcpy(aux, &array[size*j], size);
		memcpy(&array[size*j], &array[size*i], size);
		memcpy(&array[size*i], aux, size);
	}
	free(aux);
}

turnType * turnGenerate (FILE * turnFile, char * turnDifficulty) { // {{{1
	turnType * wordCurrent;
	wordCurrent = NULL;

	wordCurrent = malloc (sizeof (turnType));
	wordCurrent->key = NULL;
	wordCurrent->tip1 = NULL;
	wordCurrent->tip2 = NULL;
	wordCurrent->tip3 = NULL;

	char charCurrent;
	int count = 0;
	int findSpace = 1;
	int wordSize = 0;

	while ( count <= 5 ) {
		charCurrent=fgetc(turnFile);
		charCurrent=tolower(charCurrent);

		if (charCurrent == '\n' || charCurrent == EOF) {
			break;
		}
		else if (charCurrent == ' ' || charCurrent == '	') {
			wordSize=0;
			findSpace = 1;
		}
		else {
			if (findSpace == 1) {
				count++;
				wordSize = 0;
			}
			findSpace = 0;
			wordSize++;

			if (count == 1) {
				wordCurrent->key = (char *) realloc ( wordCurrent->key, (wordSize + 1));
				wordCurrent->key[wordSize-1] = charCurrent;
				wordCurrent->key[wordSize] = '\0';
			}

			else if (count == 2) {
				wordCurrent->difficulty = charCurrent;
				*turnDifficulty = charCurrent;
			}

			else if (count == 3) {
				wordCurrent->tip1 = (char *) realloc ( wordCurrent->tip1, (wordSize + 1));
				wordCurrent->tip1[wordSize-1] = charCurrent;
				wordCurrent->tip1[wordSize] = '\0';
			}

			else if (count == 4) {
				wordCurrent->tip2 = (char *) realloc ( wordCurrent->tip2, (wordSize + 1));
				wordCurrent->tip2[wordSize-1] = charCurrent;
				wordCurrent->tip2[wordSize] = '\0';
			}

			else if (count == 5) {
				wordCurrent->tip3 = (char *) realloc ( wordCurrent->tip3, (wordSize + 1));
				wordCurrent->tip3[wordSize-1] = charCurrent;
				wordCurrent->tip3[wordSize] = '\0';
			}

		}
	}

	if (count < 5) return NULL;
	return wordCurrent;
}

turnType ** arrayGenerate (FILE * turnFile, int * num, char turnDifficulty) { // {{{1
	rewind(turnFile);

	turnType * wordCurrent;
	turnType ** turnArray;

	turnArray = NULL;
	wordCurrent = NULL;

	int count = 0;

	char difficultyCurrent;

	while ((wordCurrent = turnGenerate(turnFile, &difficultyCurrent)) != NULL) {
		if (difficultyCurrent == turnDifficulty) {
			count++;

			turnArray = realloc ( turnArray, (sizeof (turnType*) * count));
			turnArray[count-1]=wordCurrent;
		}
	}

	*num=count;
	arrayShuffle(turnArray, *num, sizeof (turnType *)); 

	return turnArray;
}

mergedArrays * mergeArrays (FILE * turnFile) { // {{{1
	mergedArrays * array;

	array = NULL;
	array = malloc (sizeof(mergedArrays)*3);

	array[0].turnArray = arrayGenerate (turnFile, &(array[0].turnSize), 'f');
	array[0].turnCount = 0;

	array[1].turnArray = arrayGenerate (turnFile, &(array[1].turnSize), 'm');
	array[1].turnCount = 0;

	array[2].turnArray = arrayGenerate (turnFile, &(array[2].turnSize), 'd');
	array[2].turnCount = 0;

	return array;
}

int turnEnough (int n) { // {{{1
	if ( n<7 ) return 1;
	return 0;
}

// }}}1

/* vim: set ai fdm=marker fmr={{{,}}} ft=c: */
