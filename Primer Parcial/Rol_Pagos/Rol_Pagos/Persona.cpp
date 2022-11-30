#include "Persona.h"
#include <iostream>
#include <string>

using namespace std;

// Costructores
Persona::Persona(void)
{
	nombre = "";
	apellido = "";
	cedula = "";	
}

Persona::Persona(string ced, string nom, string apell)
{
	this->cedula = ced;
	this->nombre = nom;
	this->apellido = apell;
}

Persona::~Persona(void)
{
}

// Setters
void Persona::set_cedula(string cedula)
{
	this->cedula = cedula;
}

void Persona::set_nombre(string nombre)
{
	this->nombre = nombre;
}

void Persona::set_apellido(string apellido)
{
	this->apellido = apellido;
}

// Getters
string Persona::get_cedula()
{
	return this->cedula;
}

string Persona::get_nombre()
{
	return this->nombre;
}

string Persona::get_apellido()
{
	return this->apellido;
}

void Persona::imprimirDatos()
{
	cout << "Nombre: " << this->nombre << endl;
	cout << "Apellido: " << this->apellido << endl;
	cout << "Cedula: " << this->cedula << endl;
}

std::string	Persona::toString()
{
	return this->nombre + " " + this->apellido + " " + this->cedula;
}



