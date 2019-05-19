#include<iostream>
#include<ctime>
#include<random>
#include "player.h"

using namespace std;

player::player(int ataque,int puntosDeVida,int defensa, int recuperacion, char matriz[100][100]){
	this->ataque = ataque;
	this->puntosDeVida = puntosDeVida;
	this->defensa = defensa;
	this->recuperacion = recuperacion;

	mt19937 generator;
	generator.seed(time(0));
	uniform_int_distribution<uint32_t> ejey(1,99);
	uniform_int_distribution<uint32_t> ejex(1,99);

	int y = ejey(generator);
	int x = ejex(generator);

	while (matriz[y][x] != ' ')
	{
		y = ejey(generator);
		x = ejex(generator);
	}
	posicion[0] = y;
	posicion[1] = x;
	matriz[y][x] = 'U';
}

int player::GetposicionX(){
	return posicion[1];
}

int player::GetposicionY(){
	return posicion[0];
}

int player::GetAtaque(){
	return ataque;
}

void player::SetPuntosDeVida(int nuevosPuntosDeVida){
	puntosDeVida = nuevosPuntosDeVida;
}

int  player::GetPuntosDeVida(){
	return puntosDeVida;
}
int player::GetDefensa(){
	return defensa;
}

void player::GetRecuperacion(){
	puntosDeVida += recuperacion;
}

void player::mover(char matriz[100][100], char direccion){
	if (direccion == '7' && matriz[posicion[0]-1][posicion[1]-1] == ' ')
	{
		matriz[posicion[0]][posicion[1]] = ' ';
		posicion[0] += -1;
		posicion[1] += -1;
		matriz[posicion[0]][posicion[1]] = 'U';

	}
	else if (direccion == '8' && matriz[posicion[0]-1][posicion[1]] == ' ')
	{
		matriz[posicion[0]][posicion[1]] = ' ';
		posicion[0] += -1;
		matriz[posicion[0]][posicion[1]] = 'U';
	}
	else if (direccion == '9' && matriz[posicion[0]-1][posicion[1]+1] == ' ')
	{
		matriz[posicion[0]][posicion[1]] = ' ';
		posicion[0] += -1;
		posicion[1] += 1;
		matriz[posicion[0]][posicion[1]] = 'U';
	}
	else if (direccion == '4' && matriz[posicion[0]][posicion[1]-1] == ' ')
	{
		matriz[posicion[0]][posicion[1]] = ' ';
		posicion[1] += -1;
		matriz[posicion[0]][posicion[1]] = 'U';
	}
	else if (direccion == '6' && matriz[posicion[0]][posicion[1]+1] == ' ')
	{
		matriz[posicion[0]][posicion[1]] = ' ';
		posicion[1] += 1;
		matriz[posicion[0]][posicion[1]] = 'U';
	}
	else if (direccion == '1' && matriz[posicion[0]+1][posicion[1]-1] == ' ')
	{
		matriz[posicion[0]][posicion[1]] = ' ';
		posicion[0] += 1;
		posicion[1] += -1;
		matriz[posicion[0]][posicion[1]] = 'U';
	}
	else if (direccion == '2' && matriz[posicion[0]+1][posicion[1]] == ' ')
	{
		matriz[posicion[0]][posicion[1]] = ' ';
		posicion[0] += 1;
		matriz[posicion[0]][posicion[1]] = 'U';
	}
	else if (direccion == '3' && matriz[posicion[0]+1][posicion[1]+1] == ' ')
	{
		matriz[posicion[0]][posicion[1]] = ' ';
		posicion[0] += 1;
		posicion[1] += 1;
		matriz[posicion[0]][posicion[1]] = 'U';
	}
	else
	{
		cout << "movimiento no permitido." << endl;
	}
}