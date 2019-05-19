#include<iostream>
#include<ctime>
#include<random>
#include "map.h"
#include "player.h"
#include "monsters.h"
#include "game.h"

using namespace std;

int main(int argc, char const *argv[])
{
	if (argc == 4)
	{
		int filas, columnas, ataque, puntosDeVida, defensa, recuperacion;
		filas = atoi(argv[1]);
		columnas = atoi(argv[2]);
		string clase = argv[3];
		map *mapa = new map(filas, columnas);
		game G;
		if (clase == "Guerrero")
		{
			ataque = 150;
			puntosDeVida = 1000;
			defensa = 450;
			recuperacion = 50;
		}
		else if (clase == "Asesino")
		{
			ataque = 500;
			puntosDeVida = 500;
			defensa = 150;
			recuperacion = 40;
		}
		else
		{
			ataque = 1000;
			puntosDeVida = 300;
			defensa = 50;
			recuperacion = 30;
		}
		player *P = new player(ataque,puntosDeVida,defensa,recuperacion,mapa -> matriz);

		int cantidad_monsters = 10+((filas*columnas)/100);
		monsters arr[cantidad_monsters];

		mt19937 generator;
		generator.seed(time(0));
		uniform_int_distribution<uint32_t> tipo_monster(1,4);

		int puntosDeVidaMons;
		for (int i = 0; i < cantidad_monsters; ++i)
		{
			string tipo;
			int random = tipo_monster(generator);
			if (random == 1)
			{
				ataque = 20;
				puntosDeVidaMons = 150;
				tipo = "Goblin";
			}
			else if (random == 2)
			{
				ataque = 50;
				puntosDeVidaMons = 300;
				tipo = "Elfo";
			}
			else if (random == 3)
			{
				ataque = 100;
				puntosDeVidaMons = 500;
				tipo = "Dragón";
			}
			else if (random == 4)
			{
				ataque = 150;
				puntosDeVidaMons = 1000;
				tipo = "Hydra";
			}
			monsters *M = new monsters(ataque,puntosDeVidaMons,tipo,mapa->matriz);
			arr[i] = *M;
		}

		char input;
		mapa -> mostrar();	
		int pos[2];
		int contador;
		int contadorMons = cantidad_monsters;
		while (contadorMons > 0)
		{
			P -> GetRecuperacion();
			if (P -> GetPuntosDeVida() > puntosDeVida)
			{
				P -> SetPuntosDeVida(puntosDeVida);
			}
			cout << "Elige un movimiento (Presiona 0 para salir): ";
			cin >> input;
			if (input == '0')
			{
				break;
			}
			P -> mover(mapa->matriz,input);
			for (int i = 0; i < cantidad_monsters; ++i)
			{
				if (arr[i].GetPuntosDeVida() != 0)
				{
					uniform_int_distribution<uint32_t> moveY(1,3);
					uniform_int_distribution<uint32_t> moveX(1,3);
					int y = moveY(generator) - 2;
					int x = moveX(generator) - 2;

					int a = arr[i].GetposicionY();
					int b = arr[i].GetposicionX();

					while (mapa->matriz[a+y][b+x] != ' ')
					{
						y = moveY(generator) - 2;
						x = moveX(generator) - 2;
					}
					arr[i].mover(mapa->matriz, y, x);
				}
			}
			G.comprobarMons(mapa->matriz,*P,pos);
			cout << "\nTienes " << P -> GetPuntosDeVida() << " puntos de vida" << endl;
			mapa -> mostrar();
			if ( pos[0] != 0 && pos[1] != 0)
			{
				for (int i = 0; i < cantidad_monsters; ++i)
				{
					if (pos[0] == arr[i].GetposicionY() && pos[1] == arr[i].GetposicionX())
					{
						contador = i;
						break;
					}
				}
				P -> SetPuntosDeVida(G.pelea(*P,arr[contador]));
				if (P -> GetPuntosDeVida() == 0)
				{
					break;
				}
				else
				{
					arr[contador].morir(mapa->matriz);
					contadorMons -= 1;
				}
			}
		}
		cout << "Juego terminado." << endl;
	}
	return 0;
}