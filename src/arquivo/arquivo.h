/*
 * interface_arquivo.h
 * Last Change:  2014-04-25
 * Maintainer:   Lucas de Sena <contact@seninha.net>
 * License:      This file is placed in public domain.
 */

#ifndef MOD_ARQUIVO
#define MOD_ARQUIVO

#ifdef SERVIDOR_ARQUIVO
#define EXT_MOD_ARQUIVO
#else
#define EXT_MOD_ARQUIVO extern
#endif


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char* nome;
	int pontuacao;
	int turno_num;
	FILE * entrada;
	FILE * saida;
} tipoJogador;

typedef struct {
	char * chave;
	char dificuldade;
	char * dica1;
	char * dica2;
	char * dica3;
} tipoPalavra;

EXT_MOD_ARQUIVO void embaralhaVetor(void *arr, size_t n, size_t size);
EXT_MOD_ARQUIVO tipoPalavra * gerarPalavra (FILE * arquivoDePalavras);
EXT_MOD_ARQUIVO tipoPalavra ** gerarVetor (FILE * arquivoDePalavras, int * num);
EXT_MOD_ARQUIVO int palavrasSuficientes (int n);

#endif

/* vim: set ai fdm=marker fmr={{{,}}} ft=c: */
