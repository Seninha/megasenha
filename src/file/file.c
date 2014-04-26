/*
 * modulo_jogo.c
 * Last Change:  2014-04-25
 * Maintainer:   Lucas de Sena <contact@seninha.net>
 * License:      This file is placed in public domain.
 */

#define _FILE_SERVER

#include "file.h"


void arrayShuffle(void *arr, size_t n, size_t size) {
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

turnType * turnGenerate (FILE * turnFile) {
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

turnType ** arrayGenerate (FILE * turnFile, int * num) {

	turnType * wordCurrent;
	turnType ** turnArray;

	turnArray = NULL;
	wordCurrent = NULL;

	int count = 0;

	while ((wordCurrent = turnGenerate(turnFile)) != NULL) {
		count++;

		turnArray = realloc ( turnArray, (sizeof (turnType*) * count));
		turnArray[count-1]=wordCurrent;
	}

	*num=count;
	return turnArray;
}

// O Jogo funciona bem com um mínimo de 20 palavras
int turnEnough (int n) {
	if ( n<20 ) return 0;
	return 1;
}


/* vim: set ai fdm=marker fmr={{{,}}} ft=c: */
