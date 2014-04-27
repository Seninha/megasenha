/*
 * interface.c
 * Last Change:  2014-04-26
 * Maintainer:   Lucas de Sena <contact@seninha.net>
 * License:      This file is placed in public domain.
 */

#include <interface/interface.h>

int gameContinue (FILE * outCurrent, FILE * inCurrent) { // {{{1
	fprintf(outCurrent, "\nVocê deseja sair do jogo? [S/n] ");

	char * input;
	char option = 'n';
	input = NULL;
	size_t n;

	getline (&input, &n, inCurrent);
	if (n == 2) option = input[0];
	if (n == 1) option = 's';

	if (option == 's' || option == 'S') {
		return 1;
	}
	return 0;

}

void gameStart (FILE * outCurrent) { // {{{1
fprintf (outCurrent, "\n\
\n\
                                                                                         \n\
                                       :MMWMMWMXOMMWM'                                   \n\
                                   .dKXWO:coXXWNWMkNWMk'                                 \n\
                                 :0Xkl,:...''';::l,:lcOXNK;                              \n\
                           ..   0Nc,'.................',kNMo                             \n\
                    :xKklckW0XNX0. ..........     ......';xXXo.                          \n\
                   'MWlMNWkl:Xk:.............''''.......'.',x0NK0k0o                     \n\
               ',  .Md.xdlk.''.........':ldxkkOOOESCREVIc,.''..'lNMW'                    \n\
              oWkXO0M;..'.;..;.. ....,coddxxxkkkO0KXSAINKKkkl'...,0Nl                    \n\
              ;XXOxc,.....  ..  ..':cllooodddxxxkkCORRENDOMMN0x:'.,0Mk.                  \n\
               .OM0:..   ..    .';:cllooddxxxxkkkOOO0KXNWMMMWX0Oo..,oWM;                 \n\
              NNNX;.. .       ..,;:clooooooodxkOO00000KXXXNNNKK00k,';kM0                 \n\
             .Mx..           ..,;;:cc;,,'''',,;cldk00KKKXNNNWWX0OOkcooNX,                \n\
              dW..           .,,,,;,.....''''..',;:loxO00KXX0Okddoodl:lkNXl              \n\
              ON..          ..,,'.....'''''''''',;ccclodxxkkxdooooocoxkcokNW:            \n\
             ;Mc.           .'....,,;::;,,;;;;;;;,,;:;:cloddooocclxklokOkXOMMO           \n\
            .XX.            .. ..,;;;;,''',;c:;;,,;;;,.;oko,,::::ccclclox00Mk,           \n\
            WK,.              .'',;;;,'..,,',:oc,',,,''lkKXOxl::clllddXWxo0M:            \n\
           .XX.             ...'',;;;;,;;;:::clol;;,'';ldxOKNKl::ldc;dN0kK0Md            \n\
           :M:              ..,,,,clc:::;;::cccclolclloodkO0XWW0dooookodWMMMc            \n\
           .ONd.           ..,;;;::clooooodddxxxxxdllooddxkO0KNNNOdddxKMMMMN.            \n\
             dM:           .',:::cclllloddxkkxolccloddollclloxxkOOOOOOKNMMMN             \n\
            ;Wx.          .',;:::cccllodddddolc:::ccc:;'.',::ccclldxk0XKXMMN             \n\
            NK.           .';;:::cclllllllc;;:cc:,,,,,'....,:::;',cccldk0NMl             \n\
            dWld'. ....   .',;;;:ccccccc:;,;:cc::;;,,,,,,,,,,,;,;dxc;;:cdOWW             \n\
             cN0kol'''... .',,;;:::::::;,',,,;;;,;,,,,,,,,,,,,,,cdxl;,;:cxWM.            \n\
               .cMo','''...',,,;::::::;'...',,,,;;;;;;;;;:::::cldxdc'',,:xMX             \n\
                 KWx;''.....''',;:::::;...',,,,'...'.'',,:::::,,',:c.'',cKM;             \n\
                 oW,,,,'....''',;:;;;::;.........;,colddoxkkOKOkl..''.':oW0              \n\
                 ,Md;;,'.....''',,,;;:cc,.'''..::llcdl;;':cccdxdk;.''':lkMl              \n\
                  oMM:... ..''''',',,;::;,,;;;,,''.....',,:;:;,.'ddl::loKW.              \n\
                  0MWK.   .....''''',,;:;,;:::::;;;;;:coxdxdkk0kkOkOxlldWk               \n\
                 .MXKd    .....'..''',;;;;,;::::::::;::codkOOOOkxxxOkddNW;               \n\
                  .xNKx.  ........'',,,,,,,,;;::::::::::::::cc::cldOOxXM.                \n\
                     kW,  .''......''',,,,;;,,;;;;::::clloodxkxxkkOO0OWO                 \n\
                     dWo;..','''...'''''',,,;,;;:::ccodxkkO0KKK0K0000KWO                 \n\
                      :xWK:,,,,'''...'''..',,,;;::loooddxkOOOkkkOOOkO0NMo                \n\
                        oWk,,,,,,'''...........',;:cclllooddddddddxxxkNMN                \n\
                        'MO,,,,,,,''''...........',;;;;;::ccllooollookXM,                \n\
                         Mk,,;,,,''''...............'',,,,;;:::ccc:;;lNM                 \n\
                        .Wk,,;,,,,'''.........    ......'.'.'',,'...,OW;                 \n\
                         .0Kc;,,,,'..........          ............,0W.                  \n\
                           ;K0l;;,,'............            ...'..,OM;                   \n\
                             ,0Xd;,,'''................  ....',:lkXMk                    \n\
                               .l0Kxc,''..................':lx0NXo;.                     \n\
                                   ;x00xl:,''.......''',coOXKk:.                         \n\
                                      .c0MMNKkdooodxk0NMMKo.                             \n\
\x1b[0m\n");

fprintf (outCurrent, "\n\
  \x1b[1;31m========================================================================\n\
  \x1b[1;31m=\x1b[1;37m Megasenha é um jogo onde os participantes têm como objetivo \x1b[1;31m=\n\
  \x1b[1;31m=\x1b[1;37m adivinhar uma  série de palavras-chaves  em um  determinado \x1b[1;31m=\n\
  \x1b[1;31m=\x1b[1;37m tendo a disposição um máximo de 3 palavras-dicas.           \x1b[1;31m=\n\
  \x1b[1;31m=\x1b[1;37m                                                             \x1b[1;31m=\n\
  \x1b[1;31m=\x1b[1;37m O jogo ocorre  em duas fases:  na primeira fase 2 jogadores \x1b[1;31m=\n\
  \x1b[1;31m=\x1b[1;37m jogam entre si. Aquele que obtiver mais pontos passará para \x1b[1;31m=\n\
  \x1b[1;31m=\x1b[1;37m a fase final e tentará, sozinho, ser bem sucedido em 8 tur- \x1b[1;31m=\n\
  \x1b[1;31m=\x1b[1;37m nos.                                                        \x1b[1;31m=\n\
  \x1b[1;31m=\x1b[1;37m                                                             \x1b[1;31m=\n\
  \x1b[1;31m=\x1b[1;37m Para mais informações, leia a documentação do jogo.         \x1b[1;31m=\n\
  \x1b[1;31m========================================================================\n\
\x1b[0m\n");

fprintf (outCurrent, "\n\n\n\
CLIQUE ENTER PARA PROSSEGUIR!\n\
\x1b[0m");
getchar();
fprintf (outCurrent, "\x1b[1;1H\x1b[2J");

}

char * wordInsert (FILE * fileCurrent) { // {{{1
	int count;
	size_t n=0;
	char ** wordCurrent;

	* wordCurrent = NULL;

	getline (wordCurrent, &n, fileCurrent);

	for (count=0 ; *wordCurrent[count] != '\0' ; count++) {
		*wordCurrent[count] = tolower(*wordCurrent[count]);
		*wordCurrent[count] = toascii(*wordCurrent[count]);
	}

	return *wordCurrent;
}

void tipShow (FILE * outCurrent, char * tipCurrent, int n) { // {{{1
	fprintf(outCurrent, "	Dica nº %d: %s\n\
	Resposta: ", n, tipCurrent);
}

void turnWrong (FILE * outCurrent, char * keyWord) { // {{{1
	fprintf(outCurrent, "\x1b[1;31mERROU!\x1b[0m Palavra-chave é: %s\n", keyWord);
}

void turnRight (FILE * outCurrent) { // {{{1
	fprintf(outCurrent, "\x1b[1;32mACERTOU!\x1b[0m");
}

void turnInit (FILE * outCurrent, int n, char* playerName) { // {{{1
	fprintf(outCurrent, "\n\x1b[1mTurno nº %d\nJogador: %s\nBoa Sorte!\n\x1b[0m", n, playerName);
}

void level2lose (FILE * outCurrent) { // {{{1
	fprintf(outCurrent, "\x1b[1mERROU! PERDEU TUDO!\x1b[0m");
}

void level2win (FILE * outCurrent, int score) { // {{{1
	fprintf(outCurrent, "\x1b[1mPARABÉNS!!! VOCÊ CHEGOU ATÉ O FINAL COM %d PONTOS!\x1b[0m", score);
}

void level2giveUp (FILE * outCurrent, int score) { // {{{1
	fprintf(outCurrent, "\x1b[1mVOCÊ DESISTIU!!! Acumulaste %d pontos!\x1b[0m", score);
}

void levelChange (FILE * outCurrent, char *playerName) { // {{{1
	fprintf (outCurrent, "\x1b[1;1H\x1b[2J");
	fprintf(outCurrent, "\x1b[1m\
---------------------------------------[\
FASE FINAL!\
]---------------------------------------");
}

playerType * createPlayer (int num) { // {{{1
	playerType * player;
	player = NULL;
	char * nameCurrent;
	size_t n;

	fprintf (stdout, "\nEscreva seu nome, jogador %d: ", num);
	getline (&nameCurrent, &n, stdin);

	player = playerGenerate (nameCurrent, stdin, stdout);

	return player;
}

mergedArrays * readFile () { // {{{1
	int getError = 0;
	FILE * fp;
	fp = fopen("palavras.txt", "r");

	if (fp == NULL) {
		fprintf (stderr, "ERRO: arquivo \"palavras.txt\" não existe.");
		return NULL;
	}

	mergedArrays * array;
	array = NULL;

	array = mergeArrays (fp);
	fclose(fp);

	if (turnEnough(array[0].turnSize)) {
		fprintf (stderr, "ERRO: arquivo \"palavras.txt\" contém menos de 7 palavras fáceis.");
		getError = 1;
	}

	if (turnEnough(array[1].turnSize)) {
		fprintf (stderr, "ERRO: arquivo \"palavras.txt\" contém menos de 7 palavras médias.");
		getError = 1;
	}

	if (turnEnough(array[2].turnSize)) {
		fprintf (stderr, "ERRO: arquivo \"palavras.txt\" contém menos de 7 palavras difíceis.");
		getError = 1;
	}

	if (getError) {
		free (array);
		return NULL;
	}

	return array;

}
// }}}1
/* vim: set ai fdm=marker fmr={{{,}}} ft=c: */
