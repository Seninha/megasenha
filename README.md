# Megasenha

Esse é o desenvolvimento do primeiro trabalho da Turma A do primeiro
semestre de 2014 da disciplina Programação Sistemática da Universidade de
Brasília.

O trabalho consiste na criação de um jogo chamado **Megasenha**


## Objetivo

**Megasenha** é um jogo onde os participantes têm como objetivo adivinhar uma
série de **palavras-chaves**.

Cada **palavra-chave** deve ser adivinhada em um determinado tempo.

Cada participande tem direito à 3 palavras-dicas para adivinhar a palavra-chave.
As **palavras-dicas** são sinônimos ou do mesmo campo lógico da palavra-chaves.


## Andamento do Jogo

- O jogo é dividido em duas fases: **Fase Eliminatória** e **Fase Final**.

- Cada fase é dividida em turnos.

- Cada turno possui uma dificuldade que define o quão difícil será a adivinhação
  da **Palavra Chave**

- Cada turno possui uma pontuação.

- A pontuação é cumulativa para cada fase, ou seja, a pontuação da 1ª fase é
  igual à soma das pontuações de todos os turnos da 1ª fase. O mesmo vale para a
  2ª fase.

- A pontuação final do jogo é igual à pontuação da 1ª Fase vezes a pontuação da
  2ª Fase.

- Ao fim do jogo, a pontuação e o nome do jogador vão para um ranking que será
  acessível a todos.


### Turnos

Durante um turno, as seguintes coisas acontecem, em ordem:

1. O jogo irá gerar uma palavra-chave aleatória, de dificuldade aleatória,
   que deverá ser adivinhada pelo jogador atual.

2. O jogador receberá a primeira dica e tentará adivinhar a palavra-chave.

3. Caso não consiga adivinhar, o jogador receberá a segunda palavra-dica e tentará
   adivinhar novamente.

4. Caso não consiga adivinhar, o jogador receberá a terceira palavra-dica e tentará
   adivinhar novamente.

5. Caso não consiga adivinhar, o jogador perde o turno.


### Fase Eliminatória

Na Fase Eliminatória, dois jogadores jogam entre si alternando seus turnos.

Após cada jogador ter realizado 3 turnos, aquele que possuir a maior pontuação
ganha a **Fase Eliminatória** e passará, sozinho, para a **Fase Final**.

Durante esta fase, cada turno vale uma pontuação definida por `P1 = 3 - D`, onde
`D` é a quantidade de dicas usadas.


### Fase Final

Na Fase Final, o jogador fará no máximo 8 turnos.

Cada turno vale uma quantidade determinada de pontos e possui uma dificuldade
pré-definida, de acordo com a tabela abaixo:

Turno | Pontuação | Dificuldade
------|-----------|------------
  1   | 10        | Fácil
  2   | 100       | Fácil
  3   | 500       | Fácil
  4   | 1000      | Média
  5   | 5000      | Média
  6   | 10000     | Média
  7   | 500000    | Difícil
  8   | 1000000   | Difícil

Caso o jogador perca um turno, ele não poderá realizar os turnos seguintes e
perderá toda a pontuação da **Fase Final**, encerrando-se o jogo.

Após cada turno, o jogador pode desistir de realizar os turnos seguintes. Neste
caso o jogo se encerrará e ele não perderá os pontos ganhos.
