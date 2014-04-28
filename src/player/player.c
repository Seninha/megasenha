/*
 * player.c
 * Last Change:  2014-04-28
 * Maintainer:   Lucas de Sena <contact@seninha.net>
 * License:      This file is placed in public domain.
 */

#define _PLAYER_SERVER

#include <player/player.h>

playerType * playerGenerate (char * nameCurrent, FILE * inCurrent, FILE * outCurrent) { // {{{1
	playerType * playerCurrent;

	playerCurrent = malloc (sizeof (playerType));

	playerCurrent -> name = nameCurrent;
	playerCurrent -> in = inCurrent;
	playerCurrent -> out = outCurrent;

	playerCurrent -> scoreLevel = 0;

	return playerCurrent;
}

// }}}1

/* vim: set ai fdm=marker fmr={{{,}}} ft=c: */
