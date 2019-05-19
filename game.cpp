#include "game.h"
#include <iterator>
#include <random>
#include<ctime>

using namespace std;

int game::pelea(player P, monsters M){ 

	puntosDeVidaPlayer = P.GetPuntosDeVida();
	puntosDeVidaMons = M.GetPuntosDeVida();

	mt19937 generator;
	generator.seed(time(0));
	uniform_int_distribution<uint32_t> ataqueM(0,M.GetAtaque());
	uniform_int_distribution<uint32_t> ataqueP(0,P.GetAtaque());

	int danio;
	cout << "Batalla!!" << endl;
	if ((M.Gettipo() == "Dragón") | (M.Gettipo() == "Elfo") | (M.Gettipo() == "Goblin"))
	{
		cout << "Encontraste un " << M.Gettipo() << endl;

		while ((puntosDeVidaMons > 0) & (puntosDeVidaPlayer > 0))
		{
			ataqueMons = ataqueM(generator);
			ataquePlayer = ataqueP(generator);
			puntosDeVidaMons -= ataquePlayer;
			if (puntosDeVidaMons <= 0)
			{
				puntosDeVidaMons = 0;
				cout << "El " << M.Gettipo() << " recibió " << ataquePlayer << " de daño, le quedan " << puntosDeVidaMons << " puntos de vida" << endl;
				cout << "Mataste al "<< M.Gettipo() << endl;
				return puntosDeVidaPlayer;
			}
			cout << "El " << M.Gettipo() << " recibió " << ataquePlayer << " de daño, le quedan " << puntosDeVidaMons << " puntos de vida" << endl;
			danio = ataqueMons - (P.GetDefensa()/2);
			puntosDeVidaPlayer -= danio;
			if (puntosDeVidaPlayer <= 0)
			{
				puntosDeVidaPlayer = 0;
				cout << "Recibiste " << danio << " de daño, te quedan " << puntosDeVidaPlayer << " de vida" << endl;
				cout << "Te moriste." << endl;
				return puntosDeVidaPlayer;
			}
			cout << "Recibiste " << danio << " de daño, te quedan " << puntosDeVidaPlayer << " de vida" << endl;
		}
	}
	else
	{
		cout << "Encontraste una " << M.Gettipo() << endl;

		while ((puntosDeVidaMons > 0) & (puntosDeVidaPlayer > 0))
		{
			ataqueMons = ataqueM(generator);
			ataquePlayer = ataqueP(generator);
			puntosDeVidaMons -= ataquePlayer;
			if (puntosDeVidaMons <= 0)
			{
				puntosDeVidaMons = 0;
				cout << "La " << M.Gettipo() << " recibió " << ataquePlayer << " de daño, le quedan " << puntosDeVidaMons << " puntos de vida" << endl;
				cout << "Mataste a la "<< M.Gettipo() << endl;
				return puntosDeVidaPlayer;
			}
			cout << "La " << M.Gettipo() << " recibió " << ataquePlayer << " de daño, le quedan " << puntosDeVidaMons << " puntos de vida" << endl;
			danio = ataqueMons - (P.GetDefensa()/2);
			puntosDeVidaPlayer -= danio;
			if (puntosDeVidaPlayer <= 0)
			{
				puntosDeVidaPlayer = 0;
				cout << "Recibiste " << danio << " de daño, te quedan " << puntosDeVidaPlayer << " de vida" << endl;
				cout << "Te moriste." << endl;
				return puntosDeVidaPlayer;
			}
			cout << "Recibiste " << danio << " de daño, te quedan " << puntosDeVidaPlayer << " de vida" << endl;
		}
	}
	return puntosDeVidaPlayer;
}

void game::comprobarMons(char matriz[100][100], player p, int arr1[2]){ // Este metodo lo uso para comprobar si un monstruo esta cerca o no. 
// El arr[2] lo uso para guardar la poscicion del monstruo que esta cerca. En caso de que el jugador no tenga ninguna mosntruo cerca el arr[2] vale {0,0}.

	arr1[0] = 0;
	arr1[1] = 0;
	if ( (matriz[p.GetposicionY()-1][p.GetposicionX()-1] == 'G') | (matriz[p.GetposicionY()-1][p.GetposicionX()-1] == 'E') | ( matriz[p.GetposicionY()-1][p.GetposicionX()-1] == 'D') | ( matriz[p.GetposicionY()-1][p.GetposicionX()-1] == 'H') )
	{
		arr1[0] = p.GetposicionY()-1;
		arr1[1] = p.GetposicionX()-1;
	}
	else if ( (matriz[p.GetposicionY()-1][p.GetposicionX()] == 'G') | ( matriz[p.GetposicionY()-1][p.GetposicionX()] == 'E') | ( matriz[p.GetposicionY()-1][p.GetposicionX()] == 'D') | ( matriz[p.GetposicionY()-1][p.GetposicionX()] == 'H') )
	{
		arr1[0] = p.GetposicionY()-1;
		arr1[1] = p.GetposicionX();
	}
	else if ( (matriz[p.GetposicionY()-1][p.GetposicionX()+1] == 'G') | ( matriz[p.GetposicionY()-1][p.GetposicionX()+1] == 'E') | ( matriz[p.GetposicionY()-1][p.GetposicionX()+1] == 'D') | ( matriz[p.GetposicionY()-1][p.GetposicionX()+1] == 'H') )
	{
		arr1[0] = p.GetposicionY()-1;
		arr1[1] = p.GetposicionX()+1;
	}
	else if ( (matriz[p.GetposicionY()][p.GetposicionX()-1] == 'G') | ( matriz[p.GetposicionY()][p.GetposicionX()-1] == 'E') | ( matriz[p.GetposicionY()][p.GetposicionX()-1] == 'D') | ( matriz[p.GetposicionY()][p.GetposicionX()-1] == 'H') )
	{
		arr1[0] = p.GetposicionY();
		arr1[1] = p.GetposicionX()-1;
	}
	else if ( (matriz[p.GetposicionY()][p.GetposicionX()+1] == 'G') | ( matriz[p.GetposicionY()][p.GetposicionX()+1] == 'E') | ( matriz[p.GetposicionY()][p.GetposicionX()+1] == 'D') | ( matriz[p.GetposicionY()][p.GetposicionX()+1] == 'H') )
	{
		arr1[0] = p.GetposicionY();
		arr1[1] = p.GetposicionX()+1;
	}
	else if ( (matriz[p.GetposicionY()+1][p.GetposicionX()-1] == 'G') | ( matriz[p.GetposicionY()+1][p.GetposicionX()-1] == 'E') | ( matriz[p.GetposicionY()+1][p.GetposicionX()-1] == 'D') | ( matriz[p.GetposicionY()+1][p.GetposicionX()-1] == 'H') )
	{
		arr1[0] = p.GetposicionY()+1;
		arr1[1] = p.GetposicionX()-1;
	}
	else if ( (matriz[p.GetposicionY()+1][p.GetposicionX()] == 'G') | ( matriz[p.GetposicionY()+1][p.GetposicionX()] == 'E') | ( matriz[p.GetposicionY()+1][p.GetposicionX()] == 'D') | ( matriz[p.GetposicionY()+1][p.GetposicionX()] == 'H') )
	{
		arr1[0] = p.GetposicionY()+1;
		arr1[1] = p.GetposicionX();
	}
	else if ( (matriz[p.GetposicionY()+1][p.GetposicionX()+1] == 'G') | ( matriz[p.GetposicionY()+1][p.GetposicionX()+1] == 'E') | ( matriz[p.GetposicionY()+1][p.GetposicionX()+1] == 'D') | ( matriz[p.GetposicionY()+1][p.GetposicionX()+1] == 'H') )
	{
		arr1[0] = p.GetposicionY()+1;
		arr1[1] = p.GetposicionX()+1;
	}
}
