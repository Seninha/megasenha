/**
 * \file        file.h
 * \date        2014-04-28
 * \author      Lucas de Sena <contact@seninha.net>
 * \copyright   Public domain.
 */

#ifndef _FILE_MOD_
#define _FILE_MOD_

#ifdef _FILE_SERVER
#define _EXT_FILE
#else
#define _EXT_FILE extern
#endif


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/// Contém os dados de um turno
typedef struct {
    /// Palavra chave do turno que deve ser encontrada
    char * key;

    /// Dificuldade do turno
    char difficulty;
    
    /// Dica número 1
    char * tip1;

    /// Dica número 2
    char * tip2;

    /// Dica número 3
    char * tip3;
} turnType;

/// Contém metadados sobre um turno
typedef struct mergedArrays {

    /// Os dados do turno própriamente dito
    turnType ** turnArray;

    /// O tamanho do turno
    int turnSize;

    /// O contador do turno (Mostra qual é o número do turno atual)
    int turnCount;
} mergedArrays;

_EXT_FILE void arrayShuffle(void *arr, size_t n, size_t size);
_EXT_FILE turnType * turnGenerate (FILE * turnFile, char * turnDifficulty);
_EXT_FILE turnType ** arrayGenerate (FILE * turnFile, int * num, char turnDifficulty);
_EXT_FILE mergedArrays * mergeArrays (FILE * turnFile);
_EXT_FILE int turnEnough (int n);

#endif

/* vim: set ai fdm=marker fmr={{{,}}} ft=c: */
