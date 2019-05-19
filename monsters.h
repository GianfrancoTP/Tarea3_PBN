#ifndef _MONSTERS
#define _MONSTERS

#include<iostream>
using namespace std;

class monsters{

private:
	string tipo;
	int ataque;
	int puntosDeVida;
	int posicion[2];

public: 
	monsters(int ataque,int puntosDeVida, string tipo, char matriz[100][100]);
	monsters() {};
	string Gettipo();
	int GetposicionX();
	int GetposicionY();
	int GetAtaque();
	int GetPuntosDeVida();
	void mover(char matriz[100][100], int y, int x);
	void morir(char matriz[100][100]);
};

#endif