/*
 * interface_arquivo.h
 * Last Change:  2014-04-25
 * Maintainer:   Lucas de Sena <contact@seninha.net>
 * License:      This file is placed in public domain.
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

typedef struct {
	char * key;
	char difficulty;
	char * tip1;
	char * tip2;
	char * tip3;
} turnType;

_EXT_FILE void arrayShuffle(void *arr, size_t n, size_t size);
_EXT_FILE turnType * turnGenerate (FILE * turnFile);
_EXT_FILE turnType ** turnArray (FILE * turnFile, int * num);
_EXT_FILE int turnEnough (int n);

#endif

/* vim: set ai fdm=marker fmr={{{,}}} ft=c: */
