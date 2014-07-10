/*
 * player.c
 * Last Change:  2014-04-28
 * Maintainer:   Lucas de Sena <contact@seninha.net>
 * License:      This file is placed in public domain.
 */

#define _PLAYER_SERVER

#include <player/player.h>

/**
 * @brief Gera um jogador
 *
 * @param nameCurrent Nome do jogador
 * @param inCurrent Arquivo de entrada do jogador
 * @param outCurrent Arquivo de saída do jogador
 *
 * @return Retorna um jogador, i.e. um objeto do tipo `playerType *`
 */
playerType * playerGenerate (char * nameCurrent, FILE * inCurrent, FILE * outCurrent) {
	playerType * playerCurrent;
	playerCurrent = NULL;

	playerCurrent = malloc (sizeof (playerType));

	playerCurrent -> name = nameCurrent;
	playerCurrent -> in = inCurrent;
	playerCurrent -> out = outCurrent;

	playerCurrent -> scoreLevel = 0;

	return playerCurrent;
}

/* vim: set ai fdm=marker fmr={{{,}}} ft=c: */
