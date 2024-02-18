CC=gcc
#CFLAGS= -W -Wall -ansi -pedantic -g
EXEC=snake
SRC= $(wildcard src/*.c)
LDFLAGS= -W -Wall -ansi -pedantic -g -lMLV


$(EXEC): bin/game.o bin/grid.o bin/snake.o
	$(CC) -o bin/$@ $^ $(LDFLAGS)

bin/game.o: src/game.c src/grid.h src/snake.h
	$(CC) -o $@ -c $< $(LDFLAGS)

bin/grid.o: src/grid.c src/grid.h src/snake.h
	$(CC) -o $@ -c $< $(LDFLAGS)

bin/snake.o: src/snake.c src/grid.h src/snake.h
	$(CC) -o $@ -c $< $(LDFLAGS)

tgz: clean
	rm -f zip/* && tar czf ../../KONATE_makan_snake2022.tgz ../../KONATE_makan_snake2022

.PHONY: clean clear

clean:
	rm -rf bin/*.o

clear:   clean
	rm -rf bin/$(EXEC)
