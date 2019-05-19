#include "monsters.h"
#include <random>
#include<ctime>

using namespace std;

monsters::monsters(int ataque, int puntosDeVida, string tipo, char matriz[100][100]){

	this->puntosDeVida = puntosDeVida;
	this->ataque = ataque;
	this->tipo = tipo;

	mt19937 generator;								// --
	generator.seed(time(0));						//     |
	uniform_int_distribution<uint32_t> ejey(1,99);  // 
	uniform_int_distribution<uint32_t> ejex(1,99);  //	   |
             										//	   
	int y = ejey(generator);						//     |
	int x = ejex(generator);						//      > En esta parte se genera una posicion inicial aleatoria para el monstruo
													//	   |
	while (matriz[y][x] != ' ')						//	   
	{												//	   |					
		y = ejey(generator);						// 						
		x = ejex(generator);						//     |
	}												// --

	posicion[0] = y;
	posicion[1] = x;
	matriz[y][x] = 'M';
}

string monsters::Gettipo(){
	return tipo;
}

int monsters::GetPuntosDeVida(){
	return puntosDeVida;
}

int monsters::GetAtaque(){
	return ataque;
}

int monsters::GetposicionX(){
	return posicion[1];
}

int monsters::GetposicionY(){
	return posicion[0];
}

void monsters::morir(char matriz[100][100]){
	tipo = " ";
	matriz[posicion[0]][posicion[1]] = ' ';
	puntosDeVida = 0;
	posicion[0] = 0;
	posicion[1] = 0;
}

void monsters::mover(char matriz[100][100], int y, int x){

	matriz[posicion[0]][posicion[1]] = ' ';
	posicion[0] += y;
	posicion[1] += x;
	matriz[posicion[0]][posicion[1]] = tipo[0];

}
