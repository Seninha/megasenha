/*
 * modulo_jogo.c
 * Last Change:  2014-04-25
 * Maintainer:   Lucas de Sena <contact@seninha.net>
 * License:      This file is placed in public domain.
 */

#define SERVIDOR_ARQUIVO

#include "arquivo.h"


void embaralhaVetor(void *arr, size_t n, size_t size) {
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

tipoPalavra * gerarPalavra (FILE * arquivoDePalavras) {
	tipoPalavra * palavraAtual;
	palavraAtual = NULL;

	palavraAtual = malloc (sizeof (tipoPalavra));
	palavraAtual->chave = NULL;
	palavraAtual->dica1 = NULL;
	palavraAtual->dica2 = NULL;
	palavraAtual->dica3 = NULL;

	char letraAtual;
	int count = 0;
	int findSpace = 1;
	int palavraTamanho = 0;

	while ( count <= 5 ) {
		letraAtual=fgetc(arquivoDePalavras);

		if (letraAtual == '\n' || letraAtual == EOF) {
			break;
		}
		else if (letraAtual == ' ' || letraAtual == '	') {
			palavraTamanho=0;
			findSpace = 1;
		}
		else {
			if (findSpace == 1) {
				count++;
				palavraTamanho = 0;
			}
			findSpace = 0;
			palavraTamanho++;

			if (count == 1) {
				palavraAtual->chave = (char *) realloc ( palavraAtual->chave, (palavraTamanho + 1));
				palavraAtual->chave[palavraTamanho-1] = letraAtual;
				palavraAtual->chave[palavraTamanho] = '\0';
			}

			else if (count == 2) {
				palavraAtual->dificuldade = letraAtual;
			}

			else if (count == 3) {
				palavraAtual->dica1 = (char *) realloc ( palavraAtual->dica1, (palavraTamanho + 1));
				palavraAtual->dica1[palavraTamanho-1] = letraAtual;
				palavraAtual->dica1[palavraTamanho] = '\0';
			}

			else if (count == 4) {
				palavraAtual->dica2 = (char *) realloc ( palavraAtual->dica2, (palavraTamanho + 1));
				palavraAtual->dica2[palavraTamanho-1] = letraAtual;
				palavraAtual->dica2[palavraTamanho] = '\0';
			}

			else if (count == 5) {
				palavraAtual->dica3 = (char *) realloc ( palavraAtual->dica3, (palavraTamanho + 1));
				palavraAtual->dica3[palavraTamanho-1] = letraAtual;
				palavraAtual->dica3[palavraTamanho] = '\0';
			}

		}
	}

	if (count < 5) return NULL;
	return palavraAtual;
}

tipoPalavra ** gerarVetor (FILE * arquivoDePalavras, int * num) {

	tipoPalavra * palavraAtual;
	tipoPalavra ** vetorDePalavras;

	vetorDePalavras = NULL;
	palavraAtual = NULL;

	int count = 0;

	while ((palavraAtual = gerarPalavra(arquivoDePalavras)) != NULL) {
		count++;

		vetorDePalavras = realloc ( vetorDePalavras, (sizeof (tipoPalavra*) * count));
		vetorDePalavras[count-1]=palavraAtual;
	}

	*num=count;
	return vetorDePalavras;
}

// O Jogo funciona bem com um mínimo de 20 palavras
int palavrasSuficientes (int n) {
	if ( n<20 ) return 0;
	return 1;
}


/* vim: set ai fdm=marker fmr={{{,}}} ft=c: */
