#include<iostream>
#include<ctime>
#include<random>
#include "map.h" 

using namespace std;


map::map(int filas, int columnas){
	float q;
	q = (filas*columnas)/100;
	Obstaculos = q;
	Filas = filas;
	Columnas = columnas;

	mt19937 generator;
	generator.seed(time(0));
	uniform_int_distribution<uint32_t> mon1(1,filas-4);
	uniform_int_distribution<uint32_t> mon2(2,columnas-5);
	uniform_int_distribution<uint32_t> Lav1(1,filas-3);
	uniform_int_distribution<uint32_t> Lav2(1,columnas-3);
	uniform_int_distribution<uint32_t> agu1(1,Filas-3);
	uniform_int_distribution<uint32_t> agu2(1,columnas-4);

	int random1 = mon1(generator);
	int random2 = mon2(generator);
	int random3 = Lav1(generator);
	int random4 = Lav2(generator);
	int random5 = agu1(generator);
	int random6 = agu2(generator);

	int arr1[Obstaculos][2];
	int arr2[Obstaculos][2];
	int arr3[Obstaculos][2];

	for (int i = 0; i < Obstaculos; ++i)
	{
		random1 = mon1(generator);
		random2 = mon2(generator);
		random3 = Lav1(generator);
		random4 = Lav2(generator);
		random5 = agu1(generator);
		random6 = agu2(generator);
		arr1[i][0] = random1;
		arr1[i][1] = random2;
		arr2[i][0] = random3;
		arr2[i][1] = random4;
		arr3[i][0] = random5;
		arr3[i][1] = random6;
	}
	for (int i = 0; i < Filas; ++i)
	{
		for (int j = 0; j < Columnas; ++j)
		{
			matriz[i][j] = ' ';
		}
	}
	for (int i = 0; i < Filas; ++i)
	{
		for (int j = 0; j < Columnas; ++j)
		{
			for (int k = 0; k < Obstaculos; ++k)
			{
				if ((i == 0) | (j == 0) | (i == Filas - 1) | (j == Columnas - 1))
				{
					matriz[i][j] = 'X';
				}
				if ((arr1[k][0] == i) && (arr1[k][1] == j))
				{
					matriz[i][j] = 'X';
					matriz[i][j+1] = 'X';
					matriz[i][j+2] ='X';
					matriz[i+1][j-1] = 'X';
					matriz[i+1][j] ='X';
					matriz[i+1][j+1] ='X';
					matriz[i+1][j+2] ='X';
					matriz[i+1][j+3] ='X';
					matriz[i+2][j] ='X';
					matriz[i+2][j+1] ='X';
					matriz[i+2][j+2] ='X';
				}
				if ((arr2[k][0] == i) && (arr2[k][1] == j))
				{
					matriz[i][j] = 'L';
					matriz[i+1][j] ='L';
					matriz[i][j+1] = 'L';
					matriz[i+1][j+1] ='L';
				}
				if ((arr3[k][0] == i) && (arr3[k][1] == j))
				{
					matriz[i][j] = 'A';
					matriz[i+1][j] ='A';
					matriz[i][j+1] = 'A';
					matriz[i][j+2] ='A';
					matriz[i+1][j+1] ='A';
					matriz[i+1][j+2] ='A';
				}
			}
		}
	}
}

void map::mostrar(){
	for (int i = 0; i < Filas; ++i)
	{
		for (int j = 0; j < Columnas; ++j)
		{
			cout << matriz[i][j];
			if (j == Columnas - 1)
			{
				cout << endl;
			}
		}
	}
}
