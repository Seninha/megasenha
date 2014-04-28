/*
 * player.test.c
 * Last Change:  2014-04-28
 * Maintainer:   Lucas de Sena <contact@seninha.net>
 * License:      This file is placed in public domain.
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <player/player.c>

void playerGenerate_test (void) { // {{{1
	playerType * player;
	player = NULL;
	player = playerGenerate ("Jorge", stdin, stdout);
	int result = !strcmp(player->name, "Jorge") && player->scoreLevel == 0;

	free (player);

	CU_ASSERT_TRUE (result);
}

// }}}1

int main () {
	if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error ();

	CU_pSuite suite = CU_add_suite("Test", NULL, NULL);

	// Add tests to suite
	CU_ADD_TEST (suite, playerGenerate_test);

	CU_basic_set_mode(CU_BRM_VERBOSE);      // Be verbose
	CU_basic_run_tests();                   // Run tests
	CU_cleanup_registry();

	return CU_get_error();
}

/* vim: set ai fdm=marker fmr={{{,}}} ft=c: */
