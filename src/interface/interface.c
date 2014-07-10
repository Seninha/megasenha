/*
 * interface.c
 * Last Change:  2014-04-28
 * Maintainer:   Lucas de Sena <contact@seninha.net>
 * License:      This file is placed in public domain.
 */

#define _INTERFACE_SERVER

#include <interface/interface.h>

/**
 * @brief Pergunta ao jogador se ele deseja sair do jogo
 *
 * @param outCurrent Arquivo de saída
 * @param inCurrent Arquivo de entrada
 *
 * @return Retorna 1 caso o jogador deseja sair, 0 caso contrário
 */
int gameContinue (FILE * outCurrent, FILE * inCurrent) {
	fprintf(outCurrent, "\nVocê deseja sair do jogo? [s/N] ");
	char * option;
	option = NULL;
	size_t n = 0;

	getline (&option, &n, inCurrent);
	if (option[0] == 's' || option[0] == 'S') return 0;

	free (option);
	return 1;

}

/**
 * @brief IMPRIME MINHA CARA LOCA!!!!
 * 
 * Gol da Alemanha
 *
 * @param outCurrent Arquivo de saída
 */
void gameStart (FILE * outCurrent) {
fprintf (outCurrent, "\x1b[1;1H\x1b[2J");
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
                     dWo;..','''...'''''',,,;,;;:::ccodxkkO0GOL0K0000KWO                 \n\
                      :xWK:,,,,'''...'''..',,,;;::loooddxkOOOkDAOOOkO0NMo                \n\
                        oWk,,,,,,'''...........',;:cclllooALEMANHAxxxkNMN                \n\
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
  \x1b[1;31m===============================================================\n\
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
  \x1b[1;31m===============================================================\n\
\x1b[0m\n");

fprintf (outCurrent, "\n\n\n\
CLIQUE ENTER PARA PROSSEGUIR!\n\
\x1b[0m");
getchar();
fprintf (outCurrent, "\x1b[1;1H\x1b[2J");

}

/**
 * @brief Obtém uma palavra do arquivo atual
 *
 * @param fileCurrent Arquivo atual
 *
 * @return  String da palavra obtida
 */
char * wordInsert (FILE * fileCurrent) {
	int count;
	size_t n=0;
	char * wordCurrent;

	wordCurrent = NULL;

	getline (&wordCurrent, &n, fileCurrent);

	for (count=0 ; wordCurrent[count] != '\0' ; count++) {
		wordCurrent[count] = tolower(wordCurrent[count]);
		//wordCurrent[count] = toascii(wordCurrent[count]);
	}

	return wordCurrent;
}

/**
 * @brief Mostra dica do turno atual
 *
 * @param outCurrent Arquivo de Saída
 * @param tipCurrent Arquivo de Entrada
 * @param n Número do turno
 */
void tipShow (FILE * outCurrent, char * tipCurrent, int n) {
	fprintf(outCurrent, "	Dica nº %d: \x1b[1m%s\n\
	Resposta: \x1b[0m", n, tipCurrent);
}

/**
 * @brief Mostra que usuário errou o turno
 *
 * @param outCurrent Arquivo de Saída
 * @param keyWord Palavra correta que o usuário não acertou
 */
void turnWrong (FILE * outCurrent, char * keyWord) {
	fprintf(outCurrent, "	\x1b[1;31mERROU!\x1b[0m Palavra-chave é: %s\n", keyWord);
}

/**
 * @brief Mostra que usuário acertou o turno
 *
 * @param outCurrent Arquivo de Saída
 */
void turnRight (FILE * outCurrent) {
	fprintf(outCurrent, "	\x1b[1;32mACERTOU!\x1b[0m\n");
}

/**
 * @brief Inicia um turno
 *
 * @param outCurrent Arquivo de Saída
 * @param n Número do turno atual
 * @param playerName Nome do jogador
 */
void turnInit (FILE * outCurrent, int n, char* playerName) {
	fprintf(outCurrent, "\n\x1b[1mTurno nº %d\nJogador: %sBoa Sorte!\n\x1b[0m", n, playerName);
}

/**
 * @brief Mostra que o jogador perdeu o jogo
 *
 * @param outCurrent Arquivo de Saída
 */
void level2lose (FILE * outCurrent) {
	fprintf(outCurrent, "\n\x1b[1;34;41mERROU! PERDEU TUDO!\x1b[0m\n");
}

/**
 * @brief Mostra que o jogador ganhou o jogo
 *
 * @param outCurrent Arquivo de SAída
 * @param score Pontuação do jogador
 */
void level2win (FILE * outCurrent, int score) {
	fprintf(outCurrent, "\n\x1b[1;44mPARABÉNS!!! VOCÊ CHEGOU ATÉ O FINAL COM %d PONTOS!\x1b[0m\n", score);
}

/**
 * @brief Mostra quantidade de pontuação acumulada até então pelo jogador desistente
 *
 * @param outCurrent Arquivo de saída
 * @param score Pontuação do jogador
 */
void level2giveUp (FILE * outCurrent, int score) {
	fprintf(outCurrent, "\n\x1b[1;33mVOCÊ DESISTIU!!! Acumulaste %d pontos!\x1b[0m\n", score);
}

/**
 * @brief Encerra a rodada de nível 1 e inicia a rodada de nível 2
 *
 * @param outCurrent Arquivo de saída
 * @param playerName Nome do jogador vencedor da rodada 1
 */
void levelChange (FILE * outCurrent, char *playerName) {
	fprintf (outCurrent, "\x1b[1;1H\x1b[2J");
	fprintf(outCurrent, "\x1b[1m\
---------------------------------------[\
FASE FINAL!\
]---------------------------------------");
}

/**
 * @brief Interface para criar um jogador
 *
 * @param num Numero do jogador
 *
 * @return Retorna um jogador, i.e. um objeto do tipo `playerType *`
 */
playerType * createPlayer (int num) {
	playerType * player;
	player = NULL;
	char * nameCurrent;
	nameCurrent = NULL;
	size_t n = 0;

	fprintf (stdout, "Escreva seu nome, jogador %d: ", num);
	getline (&nameCurrent, &n, stdin);

	player = playerGenerate (nameCurrent, stdin, stdout);

	return player;
}

/**
 * @brief Interface para ler arquivo que contém os turnos, 
 *
 * @param fileName Nome do arquivo
 *
 * @return Retorna vetorzão com os turnos
 */
mergedArrays * readFile (char * fileName) {
	int getError = 0;
	FILE * fp;
	fp = fopen(fileName, "r");

	if (fp == NULL) {
		fprintf (stderr, "ERRO: arquivo \"%s\" não existe.\n", fileName);
		return NULL;
	}

	mergedArrays * array;
	array = NULL;

	array = mergeArrays (fp);
	fclose(fp);

	if (turnEnough(array[0].turnSize)) {
		fprintf (stderr, "ERRO: arquivo \"%s\" contém menos de 7 palavras fáceis.\n", fileName);
		getError = 1;
	}

	if (turnEnough(array[1].turnSize)) {
		fprintf (stderr, "ERRO: arquivo \"%s\" contém menos de 7 palavras médias.\n", fileName);
		getError = 1;
	}

	if (turnEnough(array[2].turnSize)) {
		fprintf (stderr, "ERRO: arquivo \"%s\" contém menos de 7 palavras difíceis.\n", fileName);
		getError = 1;
	}

	if (getError) {
		free (array);
		return NULL;
	}

	return array;

}
/* vim: set ai fdm=marker fmr={{{,}}} ft=c: */
