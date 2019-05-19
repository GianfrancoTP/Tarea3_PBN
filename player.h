#ifndef _PLAYER
#define _PLAYER

class player{

private:
	int ataque;
	int puntosDeVida;
	int defensa;
	int recuperacion;
	int posicion[2];

public: 
	player(int ataque,int puntosDeVida,int defensa, int recuperacion, char matriz[100][100]);
	int GetAtaque();
	int GetposicionX();
	int GetposicionY();
	void SetPuntosDeVida(int nuevosPuntosDeVida);
	int GetPuntosDeVida();
	int GetDefensa();
	void GetRecuperacion();
	void mover(char matriz[100][100], char direccion);
};

#endif