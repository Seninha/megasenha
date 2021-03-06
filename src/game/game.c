/*
 * game.c
 * Last Change:  2014-04-28
 * Maintainer:   Lucas de Sena <contact@seninha.net>
 * License:      This file is placed in public domain.
 */

#define _GAME_SERVER

#include <game/game.h>

/*!
 * Executa um turno
 *
 * @param turnArray Vetor que contém os turnos do qual será obtido o atual
 * @param num Quantidade de elementos do vetor
 * @param usedElements Número de elementos usados
 * @param turnNumber Número do turno atual
 * @param playerCurrent Jogador atual
 *
 * @return Retorna 1 caso o jogador passou desse turno, 0 caso contrário
 */
int turnPlay (turnType ** turnArray, int num, int *usedElements, int turnNumber, playerType * playerCurrent) {
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

/**
 * Executa rodada de nível 1.
 * Enquanto escrevia a descrição dessa função a alemanha fez um gol.
 *
 * @param array Contém o vetor de turnos que será usado nessa rodada
 * @param player1 Jogador 1
 * @param player2 Jogador 2
 *
 * @return Retorna 1 caso jogador 1 vença, retorna 2 caso jogador 2 vença,
 * retorna 0 caso contrário (nunca irá retornar 0, colocado apenas por motivos
 * de debugação)
 */
int level1 (mergedArrays * array, playerType * player1, playerType * player2) {
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

/**
 * @brief Executa rodada de nível 2
 *
 * @param array Contém o vetor de turnos que será usado nessa rodada
 * @param player Jogador que venceu a rodada 1
 *
 * @return 
 */
int level2 (mergedArrays * array, playerType * player) {
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

/* vim: set ai fdm=marker fmr={{{,}}} ft=c: */
