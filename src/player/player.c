/*
 * player.c
 * Last Change:  2014-04-26
 * Maintainer:   Lucas de Sena <contact@seninha.net>
 * License:      This file is placed in public domain.
 */

#include <player/player.h>

playerType * playerGenerate (char * nameCurrent, FILE * inCurrent, FILE * outCurrent) {
	playerType * playerCurrent;

	playerCurrent = malloc (sizeof (playerType));

	playerCurrent -> name = nameCurrent;
	playerCurrent -> in = inCurrent;
	playerCurrent -> out = outCurrent;

	playerCurrent -> scoreLevel = 0;

	return playerCurrent;
}


/* vim: set ai fdm=marker fmr={{{,}}} ft=c: */
