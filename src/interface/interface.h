/*
 * interface.h
 * Last Change:  2014-04-28
 * Maintainer:   Lucas de Sena <contact@seninha.net>
 * License:      This file is placed in public domain.
 */

#ifndef _INTERFACE_MOD_
#define _INTERFACE_MOD_

#ifdef _INTERFACE_SERVER
#define _EXT_INTERFACE
#else
#define _EXT_INTERFACE extern
#endif


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <player/player.h>
#include <file/file.h>
#include <curses.h>

_EXT_INTERFACE int gameContinue (FILE * outCurrent, FILE * inCurrent);
_EXT_INTERFACE void gameStart (FILE * outCurrent);
_EXT_INTERFACE char * wordInsert (FILE * fileCurrent);
_EXT_INTERFACE void tipShow (FILE * outCurrent, char * tipCurrent, int n);
_EXT_INTERFACE void turnWrong (FILE * outCurrent, char * keyWord);
_EXT_INTERFACE void turnRight (FILE * outCurrent);
_EXT_INTERFACE void turnInit (FILE * outCurrent, int n, char* playerName);
_EXT_INTERFACE void levelChange (FILE * outCurrent, char *playerName);
_EXT_INTERFACE void level2lose (FILE * outCurrent);
_EXT_INTERFACE void level2win (FILE * outCurrent, int score);
_EXT_INTERFACE void level2giveUp (FILE * outCurrent, int score);
_EXT_INTERFACE playerType * createPlayer (int num);
_EXT_INTERFACE mergedArrays * readFile ();

// }}}1


#endif

/* vim: set ai fdm=marker fmr={{{,}}} ft=c: */
