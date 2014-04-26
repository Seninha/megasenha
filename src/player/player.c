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

	playerCurrent -> scoreLevel1 = 0;
	playerCurrent -> scoreLevel2 = 0;
	playerCurrent -> turnLevel1 = 0;
	playerCurrent -> turnLevel2 = 0;

	return playerCurrent;
}

int playerLevel1Won (unsigned int tipNum, playerType * playerCurrent) {
	if (tipNum > 3) return 1;
	playerCurrent -> scoreLevel1 += 3 - tipNum;
	playerCurrent -> turnLevel1 ++;
	return 0;
}

int playerLevel2Won (playerType * playerCurrent) {
	unsigned int turnNum = playerCurrent -> turnLevel2;
	turnNum ++;
	if (turnNum > 8) return 1;

	unsigned int score;

	switch (turnNum) {
		case 1:
			score=10;
			break;

		case 2:
			score=100;
			break;

		case 3:
			score=500;
			break;

		case 4:
			score=1000;
			break;

		case 5:
			score=5000;
			break;

		case 6:
			score=10000;
			break;

		case 7:
			score=500000;
			break;

		case 8:
			score=1000000;
			break;

	}
	playerCurrent -> scoreLevel2 += score;
	playerCurrent -> turnLevel2 ++;
	return 0;
}

int main () {
	playerType * jorje;

	jorje = playerGenerate("Beatriz", stdin, stdout);

	playerLevel1Won (2, jorje);
	playerLevel2Won (jorje);

	printf ("%s\n", jorje->name);
	printf ("%d\n", jorje->scoreLevel1);
	printf ("%d\n", jorje->scoreLevel2);
	printf ("%d\n", jorje->turnLevel1);
	printf ("%d\n", jorje->turnLevel2);

	return 0;
}



/* vim: set ai fdm=marker fmr={{{,}}} ft=c: */
