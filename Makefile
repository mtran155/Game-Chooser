all:

game: game.c
	gcc -Wall -g -std=c99 game.c -o game
	./game

clean:
	rm game
