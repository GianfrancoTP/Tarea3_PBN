#define _MAP
#ifdef _MAP

using namespace std;

class map{

public:
	int Obstaculos;
	int Filas;
	int Columnas;

public:
	
	char matriz[100][100];
	void mostrar();
	map(int filas, int columnas);

};
#endif