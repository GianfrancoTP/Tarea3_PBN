CC = g++
flags = -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self

Tarea_3: main.o game.o monsters.o player.o map.o
	$(CC) $(flags) -o Tarea_3 main.o game.o monsters.o player.o map.o

main.o: main.cpp game.h monsters.h player.h map.h
	$(CC) $(flags) -o main.o -c main.cpp

game.o: game.cpp game.h monsters.h player.h
	$(CC) $(flags) -o game.o -c game.cpp

monsters.o: monsters.cpp monsters.h
	$(CC) $(flags) -o monsters.o -c monsters.cpp

player.o: player.cpp player.h
	$(CC) $(flags) -o player.o -c player.cpp

map.o: map.cpp map.h
	$(CC) $(flags) -o map.o -c map.cpp

run: Tarea_3
	./Tarea_3 25 50 Mago

all: clean run

clean:
	rm -f *.o
	rm -f Tarea_3
