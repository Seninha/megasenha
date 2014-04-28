/*
 * game.c
 * Last Change:  2014-04-28
 * Maintainer:   Lucas de Sena <contact@seninha.net>
 * License:      This file is placed in public domain.
 */

#include <game/game.h>

int turnPlay (turnType ** turnArray, int num, int *usedElements, int turnNumber, playerType * playerCurrent) { // {{{1
	(*usedElements)++;
	int attempt;

	if (*usedElements >= num)
		*usedElements=1;

	char * tryCurrent;
	tryCurrent = NULL;

	turnInit (playerCurrent->out, turnNumber, playerCurrent->name);

	tipShow (playerCurrent->out, turnArray[*usedElements]->tip1, 1);
	tryCurrent = wordInsert(playerCurrent->in);
	attempt = 10 - strcmp (tryCurrent, turnArray[*usedElements]->key);
	if (! attempt) {
		turnRight(playerCurrent->out);
		return 1;
	}

	tipShow (playerCurrent->out, turnArray[*usedElements]->tip2, 2);
	tryCurrent = wordInsert(playerCurrent->in);
	attempt = 10 - strcmp (tryCurrent, turnArray[*usedElements]->key);
	if (! attempt) {
		turnRight(playerCurrent->out);
		return 1;
	}

	tipShow (playerCurrent->out, turnArray[*usedElements]->tip3, 3);
	tryCurrent = wordInsert(playerCurrent->in);
	attempt = 10 - strcmp (tryCurrent, turnArray[*usedElements]->key);
	if (! attempt) {
		turnRight(playerCurrent->out);
		return 1;
	}

	turnWrong(playerCurrent->out, turnArray[*usedElements]->key);
	return 0;
}

int level1 (mergedArrays * array, playerType * player1, playerType * player2) { // {{{1
	int count, rnd;
	for (count=0; count<3; count++){
		rnd=rand()%3;
		player1->scoreLevel += 3 - turnPlay (array[rnd].turnArray, array[rnd].turnSize, &(array[rnd].turnCount), count+1, player1);
		player2->scoreLevel += 3 - turnPlay (array[rnd].turnArray, array[rnd].turnSize, &(array[rnd].turnCount), count+1, player2);
	}                                                                                       
                                                                                                
	if (player1->scoreLevel > player2->scoreLevel) return 1;                              
	if (player2->scoreLevel > player1->scoreLevel) return 2;                              
                                                                                                
	while (player1->scoreLevel == player2->scoreLevel) {                                  
		count++;                                                                        
		rnd=rand()%3;                                                                   
		player1->scoreLevel += 3 - turnPlay (array[rnd].turnArray, array[rnd].turnSize, &(array[rnd].turnCount), count+1, player1);
		player2->scoreLevel += 3 - turnPlay (array[rnd].turnArray, array[rnd].turnSize, &(array[rnd].turnCount), count+1, player2);
	}

	if (player1->scoreLevel > player2->scoreLevel) return 1;
	if (player2->scoreLevel > player1->scoreLevel) return 2;

	return 0;
}

int level2 (mergedArrays * array, playerType * player) { // {{{1
	levelChange (player->out, player->name);
	int score;

	if (! gameContinue(player->out, player->in)) {
		level2giveUp(player->out, player->scoreLevel);
		return 0;
	}
	score=turnPlay (array[0].turnArray, array[0].turnSize, &(array[0].turnCount), 1, player);
	if (score) player->scoreLevel += 10;
	else {
		player->scoreLevel = 0;
		level2lose(player->out);
		return 1;
	}

	if (! gameContinue(player->out, player->in)) {
		level2giveUp(player->out, player->scoreLevel);
		return 0;
	}
	score=turnPlay (array[0].turnArray, array[0].turnSize, &(array[0].turnCount), 2, player);
	if (score) player->scoreLevel += 100;
	else {
		player->scoreLevel = 0;
		level2lose(player->out);
		return 1;
	}

	if (! gameContinue(player->out, player->in)) {
		level2giveUp(player->out, player->scoreLevel);
		return 0;
	}
	score=turnPlay (array[0].turnArray, array[0].turnSize, &(array[0].turnCount), 3, player);
	if (score) player->scoreLevel += 500;
	else {
		player->scoreLevel = 0;
		level2lose(player->out);
		return 1;
	}

	if (! gameContinue(player->out, player->in)) {
		level2giveUp(player->out, player->scoreLevel);
		return 0;
	}
	score=turnPlay (array[1].turnArray, array[1].turnSize, &(array[1].turnCount), 4, player);
	if (score) player->scoreLevel += 1000;
	else {
		player->scoreLevel = 0;
		level2lose(player->out);
		return 1;
	}

	if (! gameContinue(player->out, player->in)) {
		level2giveUp(player->out, player->scoreLevel);
		return 0;
	}
	score=turnPlay (array[1].turnArray, array[1].turnSize, &(array[1].turnCount), 5, player);
	if (score) player->scoreLevel += 5000;
	else {
		player->scoreLevel = 0;
		level2lose(player->out);
		return 1;
	}

	if (! gameContinue(player->out, player->in)) {
		level2giveUp(player->out, player->scoreLevel);
		return 0;
	}
	score=turnPlay (array[1].turnArray, array[1].turnSize, &(array[1].turnCount), 6, player);
	if (score) player->scoreLevel += 10000;
	else {
		player->scoreLevel = 0;
		level2lose(player->out);
		return 1;
	}

	if (! gameContinue(player->out, player->in)) {
		level2giveUp(player->out, player->scoreLevel);
		return 0;
	}
	score=turnPlay (array[2].turnArray, array[2].turnSize, &(array[2].turnCount), 7, player);
	if (score) player->scoreLevel += 500000;
	else {
		player->scoreLevel = 0;
		level2lose(player->out);
		return 1;
	}

	if (! gameContinue(player->out, player->in)) {
		level2giveUp(player->out, player->scoreLevel);
		return 0;
	}
	score=turnPlay (array[2].turnArray, array[2].turnSize, &(array[2].turnCount), 8, player);
	if (score) player->scoreLevel += 1000000;
	else {
		player->scoreLevel = 0;
		level2lose(player->out);
		return 1;
	}

	level2win(player->out, player->scoreLevel);
	return 0;
}

// }}}1

/* vim: set ai fdm=marker fmr={{{,}}} ft=c: */
