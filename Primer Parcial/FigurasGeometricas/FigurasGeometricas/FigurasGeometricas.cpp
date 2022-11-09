#include "Circulo.h"
#include "Rectangulo.h"
#include "Triangulo.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool esEntero(string);

int main() {
	int opcion, radio, base, altura;
	string linea,r,b,a;
	bool rep = true;
	bool repite = true;
	bool repetir = true;

	Circulo circulo;
	Retangulo rectangulo;
	Triangulo triangulo;



	do {
		system("cls");
		cout << "\n****************** Menu *******************\n";
		cout << "\n**** Seleccione una figura geometrica: ****\n";
		cout << "1> Circulo\n";
		cout << "2> Rectangulo\n";
		cout << "3> Triangulo\n";
		cout << "4> Salir\n";
		cout << "\n\nDigite una opcion para calcular area del 1 al 4: \n";
		do {

			getline(cin, linea);

			if (esEntero(linea)) {
				repite = false;
				opcion = atoi(linea.c_str());
				if (opcion > 4 || opcion < 1) {
					repetir = true;
				}
			}
			else {
				cout << "No has ingresado un valor entero. Intentalo nuevamente" << endl;
			}
		} while (repite);

		opcion = atoi(linea.c_str());
				
		switch (opcion) {
		case 1:
			cout << "Ingrese el radio del circulo: \n";
			do {
				getline(cin, r);

				if (esEntero(r)) {
					rep = false;
					radio = atoi(r.c_str());
				}
				else {
					cout << "No has ingresado un valor entero. Intentalo nuevamente" << endl;
				}
			} while (rep);

			
			
			cout << "Area del Circulo es: " << circulo.getArea(radio, 0) << "\n\n\n\n\n\n\n";
			system("pause>nul");
			break;

		case 2:

			cout << "Ingrese la base del rectangulo: \n";
			do {
				getline(cin, b);

				if (esEntero(b)) {
					rep = false;
					base = atoi(b.c_str());
				}
				else {
					cout << "No has ingresado un valor entero. Intentalo nuevamente" << endl;
				}
			} while (rep);

			
			
			cout << "Ingrese la altura del rectangulo: \n";
			do {
				
				getline(cin, a);

				if (esEntero(a)) {
					rep = false;
					altura = atoi(a.c_str());
				}
				else {
					cout << "No has ingresado un valor entero. Intentalo nuevamente" << endl;
				}
			} while (rep);

			
			cout << "Area del Rectangulo es: " << rectangulo.getArea(base, altura) << "\n\n\n\n\n\n\n";
			system("pause>nul");
			break;
		case 3:
			cout << "Ingrese la base del triangulo: \n";

			do {
				getline(cin, b);

				if (esEntero(b)) {
					rep = false;
					base = atoi(b.c_str());
				}
				else {
					cout << "No has ingresado un valor entero. Intentalo nuevamente" << endl;
				}
			} while (rep);

			
			cout << "Ingrese la altura retangulo: \n";
			do {
				getline(cin, a);

				if (esEntero(a)) {
					rep = false;
					altura = atoi(a.c_str());
				}
				else {
					cout << "No has ingresado un valor entero. Intentalo nuevamente" << endl;
				}
			} while (rep);

			
			cout << "Area del Triangulo es: " << triangulo.getArea(base, altura) << "\n\n\n\n\n\n\n";
			system("pause>nul");
			break;
		case 4:
			repetir = false;
			break;

		}

	} while (repetir);


	return (0);
}


bool esEntero(string linea) {
	bool esEntero = true;
	int longitud = linea.size();

	if (longitud == 0) {
		esEntero = false;
	}
	else if (longitud == 1 && !isdigit(linea[0])) {
		esEntero = false;
	}
	else {
		int indice = 0;
		if (linea[0] == '+' || linea[0] == '-') {
			indice = 1;
		}
		else {
			indice = 0;
		}

		while (indice < longitud) {
			if (!isdigit(linea[indice])) {
				esEntero = false;
				break;
			}
			indice++;
		}
	}


	return esEntero;
}
