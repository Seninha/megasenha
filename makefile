all: build clean

build: main.o file.o player.o interface.o game.o base
	gcc -std=gnu99 -fprofile-arcs -ftest-coverage -lncurses -Og -Wall -I "src/" src/main.o src/file/file.o src/player/player.o src/interface/interface.o src/game/game.o -o bin/megasenha


## Modules building
main.o: src/main.c base
	gcc -std=gnu99 -fprofile-arcs -ftest-coverage -lncurses -Og -Wall -I "src/" -c src/main.c -o src/main.o

file.o: src/file/file.c src/file/file.h base
	gcc -std=gnu99 -fprofile-arcs -ftest-coverage -lncurses -Og -Wall -I "src/" -c src/file/file.c -o src/file/file.o

player.o: src/player/player.c src/player/player.h base
	gcc -std=gnu99 -fprofile-arcs -ftest-coverage -lncurses -Og -Wall -I "src/" -c src/player/player.c -o src/player/player.o

interface.o: src/interface/interface.c src/interface/interface.h base
	gcc -std=gnu99 -fprofile-arcs -ftest-coverage -lncurses -Og -Wall -I "src/" -c src/interface/interface.c -o src/interface/interface.o

game.o: src/game/game.c src/game/game.h base
	gcc -std=gnu99 -fprofile-arcs -ftest-coverage -lncurses -Og -Wall -I "src/" -c src/game/game.c -o src/game/game.o


## Test modules building

file.test: src/file/file.c src/file/file.h src/file/file.test.c base
	gcc -std=gnu99 -fprofile-arcs -ftest-coverage -lncurses -lcunit -Og -Wall -I "src/" src/file/file.test.c -o bin/file.test

player.test: src/player/player.c src/player/player.h src/player/player.test.c base
	gcc -std=gnu99 -fprofile-arcs -ftest-coverage -lncurses -lcunit -Og -Wall -I "src/" src/player/player.test.c -o bin/player.test

interface.test: src/interface/interface.c src/interface/interface.h src/interface/interface.test.c base
	gcc -std=gnu99 -fprofile-arcs -ftest-coverage -lncurses -lcunit -Og -Wall -I "src/" src/interface/interface.test.c -o bin/interface.test

game.test: src/game/game.c src/game/game.h src/game/game.test.c base
	gcc -std=gnu99 -fprofile-arcs -ftest-coverage -lncurses -lcunit -Og -Wall -I "src/" src/game/game.test.c -o bin/game.test


## Modules source code coveraging

file.gcov: src/file/file.c src/file/file.h base
	gcov src/file/file.c

player.gcov: src/player/player.c src/player/player.h base
	gcov src/player/player.c

interface.gcov: src/interface/interface.c src/interface/interface.h base
	gcov src/interface/interface.c

game.gcov: src/game/game.c src/game/game.h base
	gcov src/game/game.c

main.gcov: src/main.c base
	gcov src/main.c


## Module static analysis

file.splint: src/file/file.c src/file/file.h base
	splint -weak +infloops +sysdirerrors +compdef -I "src/" src/file/file.c

player.splint: src/player/player.c src/player/player.h base
	splint -weak +infloops +sysdirerrors +compdef -I "src/" src/player/player.c

interface.splint: src/interface/interface.c src/interface/interface.h base
	splint -weak +infloops +sysdirerrors +compdef -I "src/" src/interface/interface.c

game.splint: src/game/game.c src/game/game.h base
	splint -weak +infloops +sysdirerrors +compdef -I "src/" src/game/game.c

main.splint: src/main.c base
	splint -weak +infloops +sysdirerrors +compdef -I "src/" src/main.c


## Create documentation
doc: ./Doxyfile
	doxygen ./Doxyfile


clean:
	rm -f src/*.o
	rm -f src/*/*.o
	rm -f src/*.gc*
	rm -f src/*/*.gc*

docclean:
	rm -rf doc/*

remove:
	rm -f bin/*

base:
	mkdir -p bin tmp
