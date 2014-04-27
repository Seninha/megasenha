/*
 * interface_arquivo.h
 * Last Change:  2014-04-25
 * Maintainer:   Lucas de Sena <contact@seninha.net>
 * License:      This file is placed in public domain.
 */

#ifndef _GAME_MOD_
#define _GAME_MOD_

#ifdef _GAME_SERVER
#define _EXT_GAME
#else
#define _EXT_GAME extern
#endif


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <interface/interface.h>

_EXT_GAME int turnPlay (turnType ** turnArray, int num, int *usedElements, int turnNumber, playerType * playerCurrent);
_EXT_GAME int level1 (mergedArrays * array, playerType * player1, playerType * player2);
_EXT_GAME int level2 (mergedArrays * array, playerType * player);

#endif

/* vim: set ai fdm=marker fmr={{{,}}} ft=c: */
