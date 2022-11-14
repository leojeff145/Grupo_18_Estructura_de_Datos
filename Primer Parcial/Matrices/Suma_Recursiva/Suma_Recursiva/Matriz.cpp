#include "Matriz.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

template <class T>
Matriz<T>::Matriz(int filas, int columnas)
{
	fila = filas;
	columna = columnas;
	matriz = new T * [fila];
	for (int i = 0; i < fila; i++)
	{
		matriz[i] = new T[columna];
	}
}

template <class T>
Matriz<T>::Matriz()
{

}

template <class T>
Matriz<T>::~Matriz()
{
	for (int i = 0; i < fila; i++)
	{
		delete[] matriz[i];
	}
	delete[] matriz;
}

template <class T>
int Matriz<T>::getMatriz(void)
{
	return matriz;
}

template <class T>
void Matriz<T>::setMatriz(int newMatriz)
{
	matriz = newMatriz;
}

template<class T>
int Matriz<T>::valInt(char* input)
{
	int num;
	char* endptr;
	num = strtol(input, &endptr, 10);
	if (endptr == input || *endptr != '\0')
	{
		cout << "ERROR!....Ingresar Entero....." << endl;
		return 0;
	}
	else
	{
		return num;
	}
}

template <class T>
void Matriz<T>::llenar_matriz()
{
	char* input = new char[10];
	bool rep = true;
	for (int i = 0; i < fila; i++)
	{
		for (int j = 0; j < columna; j++)
		{
			rep = true;
			while (rep)
			{
				cout << "Ingrese el valor de la posicion [" << i << "][" << j << "]: ";
				cin >> input;
				matriz[i][j] = valInt(input);
				if (matriz[i][j] != 0)
				{
					rep = false;
				}
			}
		}
	}
}
	
	/*int i, j;
	for (i = 0; i < fila; i++)
	{
		for (j = 0; j < columna; j++)
		{
			cout << "Ingrese el valor de la posicion [" << i << "][" << j << "]: ";			
			cin >> matriz[i][j];
		}
	}
}*/

template <class T>
void Matriz<T>::mostrar_matriz()
{
	
	for (int i = 0; i < fila; i++)
	{
		for (int j = 0; j < columna; j++)
			cout <<setw(4)<< matriz[i][j];
		cout << endl;
	}	
}

template <class T>
Matriz<T> Matriz<T>::operator+(Matriz<T> &mat)
{
	//int i, j;
	Matriz<T> resultado(fila, columna);
	for (int i = 0; i < fila; i++)
	{
		for (int j = 0; j < columna; j++)
		{
			resultado.matriz[i][j] = matriz[i][j] + mat.matriz[i][j];
		}
	}
	return resultado;
}

template <class T>
Matriz<T> Matriz<T>::operator*(Matriz<T>& mat1)
{
	int i, j, k;
	Matriz<T> resultado(fila, columna);
	for (i = 0; i < fila; i++)
	{
		for (j = 0; j < columna; j++)
		{
			resultado.matriz[i][j] = 0;
			for (k = 0; k < columna; k++)
			{
				resultado.matriz[i][j] += matriz[i][k] * mat1.matriz[i][j];
			}
		}
	}
	return resultado;
}


/*void suma_rec(Matriz<T>& m, Matriz<T>& m1, Matriz<T>& m2, int i, int j) {

	if (i < 3) {
		if (j < 3) {
			m2[i][j] = m[i][j] + m1[i][j];
			suma_rec(m, m1, m2, i, j + 1);
		}
		else {
			suma_rec(m, m1, m2, i + 1, 0);
		}
	}
}*/

/*template <class T>
int Matriz<T>::suma_rec(Matriz<T>& matrix)
{
	int fila, columna;	
	Matriz<T> mat1(fila, columna), mat2(fila, columna);
	mat1.llenar_matriz();
	mat2.llenar_matriz();
	
	if ((fila == 0) && (columna == 0))
		return mat1[fila][columna] + mat2[fila][columna];
	else {
		if (fila > -1) {
			columna--;
			if (columna >= -1)
				return mat1[fila][columna + 1] + mat2[fila][columna + 1] + suma_rec( matrix, fila, columna);
			else
				return suma_rec(matrix, fila - 1, 2);
		}
	}
	//return;
}*/


