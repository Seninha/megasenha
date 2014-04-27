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

void arrayShuffle_test (void) { // {{{1
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

void turnGenerate_test (void) { // {{{1
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
		     strcmp(turn->key,"áries") && \
		     turn->difficulty == 'f' && \
		     strcmp("corajoso", turn->tip1) && \
		     strcmp(turn->tip2,"intuitivo") && \
		     strcmp(turn->tip3,"destemido");

	CU_ASSERT_TRUE ( ! result );

	fclose(f);
	free(turn);
}

void arrayGenerate_test (void) { // {{{1
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

	turnType ** array;
	int n = 0;

	array = NULL;

	array = arrayGenerate (f, &n, 'm');
	printf("\n");
	printf("%d", n);
	printf("%s", array[0]->key);

	int result = \
		     array[2]->difficulty == 'm' && (\
		     (strcmp(array[2]->key,"libra")       && strcmp("equilibrado", array[2]->tip1)  && strcmp(array[2]->tip2,"diplomático") && strcmp(array[2]->tip3,"sociável"))   || \
		     (strcmp(array[2]->key,"escorpião")   && strcmp("intenso", array[2]->tip1)      && strcmp(array[2]->tip2,"profundo")    && strcmp(array[2]->tip3,"perceptivo")) || \
		     (strcmp(array[2]->key,"sagitário")   && strcmp("otimista", array[2]->tip1)     && strcmp(array[2]->tip2,"sincero")     && strcmp(array[2]->tip3,"corajoso"))   || \
		     (strcmp(array[2]->key,"capricórnio") && strcmp("responsável", array[2]->tip1)  && strcmp(array[2]->tip2,"competitivo") && strcmp(array[2]->tip3,"realista")));
	printf("%d", result);

	CU_ASSERT_TRUE ( result );
	fclose (f);
	free (array);

}

// }}}1

int main () {
	if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error ();

	CU_pSuite suite = CU_add_suite("Test", NULL, NULL);

	// Add tests to suite
	CU_ADD_TEST (suite, arrayShuffle_test);
	CU_ADD_TEST (suite, turnGenerate_test);
	CU_ADD_TEST (suite, arrayGenerate_test);

	CU_basic_set_mode(CU_BRM_VERBOSE);      // Be verbose
	CU_basic_run_tests();                   // Run tests
	CU_cleanup_registry();

	return CU_get_error();
}

/* vim: set ai fdm=marker fmr={{{,}}} ft=c: */
