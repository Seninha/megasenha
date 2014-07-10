/*
 * player.h
 * Last Change:  2014-04-28
 * Maintainer:   Lucas de Sena <contact@seninha.net>
 * License:      This file is placed in public domain.
 */

#ifndef _PLAYER_MOD_
#define _PLAYER_MOD_

#ifdef _PLAYER_SERVER
#define _EXT_PLAYER
#else
#define _EXT_PLAYER extern
#endif


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Tipo de dado de jogador, contém informações básicas dele
 */
typedef struct {
        /// Nome do jogador
	char* name;

        /// Pontuação do jogador
	int scoreLevel;

        /// Arquivo de entrada do jogador
	FILE * in;

        /// Arquivo de saída do jogador
	FILE * out;
} playerType;

_EXT_PLAYER playerType * playerGenerate (char * nameCurrent, FILE * inCurrent, FILE * outCurrent);

#endif

/* vim: set ai fdm=marker fmr={{{,}}} ft=c: */
