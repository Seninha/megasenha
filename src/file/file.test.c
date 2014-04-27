/*
 * file.test.c
 * Last Change:  2014-04-26
 * Maintainer:   Lucas de Sena <contact@seninha.net>
 * License:      This file is placed in public domain.
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <file/file.c>

// arrayShufle test {{{1
void arrayShuffle_test (void) {
	int array [10] = { 0, 1,2,3,4,5,6,7,8,9};
	arrayShuffle (array, 10, sizeof(int));
	int result;
	result = array[0] != 0 || \
		 array[1] != 1 || \
		 array[2] != 2 || \
		 array[3] != 3 || \
		 array[4] != 4 || \
		 array[5] != 5 || \
		 array[6] != 6 || \
		 array[7] != 7 || \
		 array[8] != 8 || \
		 array[9] != 9 || \
		 array[1] != 1 || \
		 array[1] != 1 || \
		 array[1] != 1 || \
		 array[1] != 1; 
	CU_ASSERT_TRUE ( result );
}

// turnGenerate test {{{1
void turnGenerate_test (void) {
	FILE * f;
	f = fopen("/tmp/turnGenerate.test", "w+");
	fprintf ( f, "\
		Áries       f Corajoso      Intuitivo    Destemido\n\
		Touro       f Perseverante  Habilidoso   Determinado\n\
		Gêmeos      f Comunicativo  Curioso      Inteligente\n\
		Câncer      F Cuidadoso     Afetuoso     Romântico\n\
		Leão        M Criativo      Leal         Decidido\n\
		Virgem      M Organizado    Corente      Prático\n\
		Libra       M Equilibrado   Diplomático  Sociável\n\
		Escorpião   M Intenso       Profundo     Perceptivo\n\
		Sagitário   D Otimista      Sincero      Corajoso\n\
		Capricórnio D Responsável   Competitivo  Realista\n\
		Aquário     D Civilizado    Tolerante    Libertário\n\
		Peixes      D Amável        Carinhoso    Romântico\n\
		");
	rewind (f);
	turnType * turn;
	turn = NULL;
	char difficultyCurrent;
	turn = turnGenerate (f, &difficultyCurrent);

	int result = \
		     strcmp(turn->key,"Áries") && \
		     turn->difficulty == 'f' && \
		     strcmp("corajoso", turn->tip1) && \
		     strcmp(turn->tip2,"Intuitivo") && \
		     strcmp(turn->tip3,"Destemido");

	CU_ASSERT_TRUE ( ! result );

	fclose(f);
	free(turn);
}

// main {{{1
int main () {
	if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error ();

	CU_pSuite suite = CU_add_suite("Test", NULL, NULL);

	// Add tests to suite
	CU_ADD_TEST (suite, arrayShuffle_test);
	CU_ADD_TEST (suite, turnGenerate_test);

	CU_basic_set_mode(CU_BRM_VERBOSE);      // Be verbose
	CU_basic_run_tests();                   // Run tests
	CU_cleanup_registry();

	return CU_get_error();
}

/* vim: set ai fdm=marker fmr={{{,}}} ft=c: */
