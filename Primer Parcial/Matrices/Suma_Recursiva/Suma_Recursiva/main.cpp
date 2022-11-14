#include "Matriz.cpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int validacionInt(char* input)
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

int main()
{
	int filas, columnas; 
	char* input = new char[10];
    bool rep = true;
	while (rep)
	{
		cout << "Ingrese el numero de filas: ";
		cin >> input;
		filas = validacionInt(input);
		if (filas != 0)
		{
			rep = false;
		}
	}
	rep = true;	
	while (rep)
	{
		cout << "Ingrese el numero de columnas: ";
		cin >> input;
		columnas = validacionInt(input);
		if (columnas != 0)
		{
			rep = false;
		}
	}	
    Matriz<int> m1(filas, columnas);
    Matriz<int> m2(filas, columnas);		
    cout << "Matriz 1" << endl;
    cout << "\n";
    m1.llenar_matriz();
    cout << "Matriz 2" << endl;
    cout << "\n";
    m2.llenar_matriz();
    cout << "Matriz 1" << endl;
    cout << "\n";
    m1.mostrar_matriz();
    cout << "\n";
    cout << "Matriz 2" << endl;
    cout << "\n";
    m2.mostrar_matriz();
    cout << "\n";
    Matriz<int> m3 = m1 + m2;
    cout << "Matriz 1 + Matriz 2" << endl;
    cout << "\n";
    m3.mostrar_matriz();
    cout << "\n";
    Matriz<int> m4 = m1 * m2;
    cout << "Matriz 1 * Matriz 2" << endl;
    cout << "\n";
    m4.mostrar_matriz();
	return 0;
}