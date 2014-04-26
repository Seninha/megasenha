/*
 * interface_base.h
 * Last Change:  2014-04-25
 * Maintainer:   Lucas de Sena <contact@seninha.net>
 * License:      This file is placed in public domain.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char* nome;
	int pontuacao;
	int turno_num;
	FILE * entrada;
	FILE * saida;
} tipoJogador;

typedef struct {
	char * chave;
	char * dificuldade;
	char * dica1;
	char * dica2;
	char * dica3;
} tipoPalavra;

/* vim: set ai fdm=marker fmr={{{,}}} ft=c: */
