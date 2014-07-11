/*
 * main.c
 * Last Change:  2014-04-27
 * Maintainer:   Lucas de Sena <contact@seninha.net>
 * License:      This file is placed in public domain.
 */

#include <mcheck.h>
#include <game/game.h>

int main (int argc, char **argv) {
	mtrace();

	mergedArrays * array;
        array=NULL;
	if (argc > 1) array = readFile(argv[1]);
	else array = readFile("palavras.txt");

	if (array == NULL) return 1;

	playerType * player1;
	playerType * player2;
	player1 = NULL;
	player2 = NULL;
	player1 = createPlayer (1);
	player2 = createPlayer (2);

	gameStart (player1->out);

	int winner = level1 (array, player1, player2);

	if (winner == 1) winner = level2 (array, player1);
	if (winner == 2) winner = level2 (array, player2);

	free(array);
	free(player1);
	free(player2);

	return 0;
}

/* vim: set ai fdm=marker fmr={{{,}}} ft=c: */
