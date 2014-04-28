# Instalar megasenha

Informações sobre a instalação do jogo megasenha em sistemas GNU/Linux.


## Instalação

Primeiro compile:
```
$ make
```

Depois execute, substituindo `<file>` pelo nome do arquivo onde estão as
palavras:
```
$ bin/megasenha "<file>"
```


## Compilar módulos

Você pode compilar módulos individualmente pelo seguinte comando:
```
$ make <module>.o
``` 
Substitua `<module>` pelo nome do módulo desejado, que pode ser:
	- file
	- player
	- interface
	- game


## Casos de teste

Você pode testar os módulos individualmente.

Para isso, compile o caso de teste do módulo desejado:
```
$ make <module>.test
``` 

E execute:
```
$ bin/<module>.test

Substitua `<module>` pelo nome do módulo desejado, veja na sessão acima os
possíveis nomes para os módulos.

vim:set ft=markdown:
