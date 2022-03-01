CC = gcc
FLAGS = -c -Wall  

connect4: game.o AI.o connect4.o
	$(CC)   game.o AI.o connect4.o -o connect4

game.o: ./src/game.c 
	$(CC) $(FLAGS) -I ./header/ ./src/game.c

AI.o: ./src/AI.c
	$(CC) $(FLAGS) -I ./header/ ./src/AI.c 

connect4.o: ./src/connect4.c
	$(CC) $(FLAGS) -I ./header/ ./src/connect4.c
clean:
	rm -f game.o AI.o connect4.o
