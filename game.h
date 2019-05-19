#define _GAME
#ifdef _GAME

#include "player.h"
#include "monsters.h"

class game{
	int ataqueMons;
	int puntosDeVidaMons;
	int ataquePlayer;
	int puntosDeVidaPlayer;

public:
	void comprobarMons(char matriz[100][100], player p, int arr[2]);
	int pelea(player P, monsters M);
};

#endif