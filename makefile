all: build clean

build: main.o file.o player.o interface.o game.o
	gcc -Og -Wall -I "src/" src/main.o src/file/file.o src/player/player.o src/interface/interface.o src/game/game.o -o bin/megasenha

main.o: src/main.c
	gcc -Og -Wall -I "src/" -c src/main.c -o src/main.o

file.o: src/file/file.c src/file/file.h
	gcc -Og -Wall -I "src/" -c src/file/file.c -o src/file/file.o

player.o: src/player/player.c src/player/player.h
	gcc -Og -Wall -I "src/" -c src/player/player.c -o src/player/player.o

interface.o: src/interface/interface.c src/interface/interface.h
	gcc -Og -Wall -I "src/" -c src/interface/interface.c -o src/interface/interface.o

game.o: src/game/game.c src/game/game.h
	gcc -Og -Wall -I "src/" -c src/game/game.c -o src/game/game.o

clean:
	rm src/*.o
	rm src/*/*.o