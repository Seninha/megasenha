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
#include <file/file.h>

typedef struct {
	char* name;
	unsigned int scoreLevel1;
	unsigned int scoreLevel2;
	unsigned int turnLevel1;
	unsigned int turnLevel2;
	FILE * in;
	FILE * out;
} playerType;

#endif

/* vim: set ai fdm=marker fmr={{{,}}} ft=c: */
