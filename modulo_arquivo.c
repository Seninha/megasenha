/*
 * modulo_jogo.c
 * Last Change:  2014-04-25
 * Maintainer:   Lucas de Sena <contact@seninha.net>
 * License:      This file is placed in public domain.
 */

#include <stdio.h>
#include <stdlib.h>
#include "interface_base.h"

tipoPalavra * gerarPalavra (FILE * listaDePalavras) {
	tipoPalavra * palavraAtual;
	palavraAtual = NULL;

	palavraAtual = malloc (sizeof (tipoPalavra));
	palavraAtual->chave = NULL;
	palavraAtual->dificuldade = NULL;
	palavraAtual->dica1 = NULL;
	palavraAtual->dica2 = NULL;
	palavraAtual->dica3 = NULL;

	char letraAtual;
	int count = 0;
	int findSpace = 1;
	int palavraTamanho = 0;

	while ( count <= 5 ) {
		letraAtual=fgetc(listaDePalavras);

		if (letraAtual == EOF || letraAtual == '\n' ) {
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
				palavraAtual->dificuldade = (char *) realloc ( palavraAtual->dificuldade, (palavraTamanho + 1));
				palavraAtual->dificuldade[palavraTamanho-1] = letraAtual;
				palavraAtual->dificuldade[palavraTamanho] = '\0';
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

	return palavraAtual;

}

int main () {
	FILE * arquivo;
	arquivo = fopen ("batata", "r");
	tipoPalavra * jota;
	jota = gerarPalavra (arquivo);

	printf ("jota->chave: %s\n", jota->chave);
	printf ("jota->dificuldade: %s\n", jota->dificuldade);
	printf ("jota->dica1: %s\n", jota->dica1);
	printf ("jota->dica2: %s\n", jota->dica2);
	printf ("jota->dica3: %s\n", jota->dica3);

	return 0;
}


/* vim: set ai fdm=marker fmr={{{,}}} ft=c: */
