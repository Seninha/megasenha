/*
 * interface_arquivo.h
 * Last Change:  2014-04-25
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

typedef struct {
	char* name;
	int scoreLevel;
	FILE * in;
	FILE * out;
} playerType;

_EXT_PLAYER playerType * playerGenerate (char * nameCurrent, FILE * inCurrent, FILE * outCurrent);
_EXT_PLAYER int playerLevel1Won (int tipNum, playerType * playerCurrent);
_EXT_PLAYER int playerLevel2Won (playerType * playerCurrent);

#endif

/* vim: set ai fdm=marker fmr={{{,}}} ft=c: */
