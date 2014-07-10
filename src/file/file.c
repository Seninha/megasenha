/*
 * file.c
 * Last Change:  2014-04-28
 * Maintainer:   Lucas de Sena <contact@seninha.net>
 * License:      This file is placed in public domain.
 */

#define _FILE_SERVER

#include <file/file.h>

/** Mistura o conteúdo de um vetor
 * \param  arr
 *         Vetor a ser misturado
 *
 * \param  n
 *         Tamanho de cada entrada do vetor
 *
 * \param  size
 *         Quantidade de entradas que o vetor possui
 *
 * \return Gol da Alemanha
 */
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

/**
 * Procura em um arquivo, uma entrada de turno com uma dificuldade
 *
 * @param turnFile Arquivo que contém os turnos
 * @param turnDifficulty Dificuldade do turno
 *
 * @return Retorna um turno, i.e. um objeto do tipo `turnType *`
 */
turnType * turnGenerate (FILE * turnFile, char * turnDifficulty) {
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

/**
 * @brief Gera um vetor de turnos
 *
 * Essa função usa a função `turnGenerate` para obter os turnos do arquivo
 *
 * @param turnFile Arquivo que contém os turnos
 * @param num Número de turnos
 * @param turnDifficulty Dificuldade dos turnos
 *
 * @return Retorna um vetor de turnos, i.e. um objeto do tipo `turnType **`
 */
turnType ** arrayGenerate (FILE * turnFile, int * num, char turnDifficulty) {
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

/**
 * Cria um vetor com todos os turnos de um arquivo, conténdo metadados
 * sobre eles
 *
 * @param turnFile Arquivo que contém os turnos
 *
 * @return Retorna um vetor de metadados de turnos
 */
mergedArrays * mergeArrays (FILE * turnFile) {
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

/**
 * @brief Verifica se a quantidade de turnos é suficiente (mais de 7)
 *
 * @param n Quantidade de turnos
 *
 * @return Retorna 1 caso não haver turno suficiente, 0 caso contrário
 */
int turnEnough (int n) {
	if ( n<7 ) return 1;
	return 0;
}

/* vim: set ai fdm=marker fmr={{{,}}} ft=c: */
