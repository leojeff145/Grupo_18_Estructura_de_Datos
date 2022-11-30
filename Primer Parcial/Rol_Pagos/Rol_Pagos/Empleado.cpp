#include "Empleado.h"
#include <iostream>
#include <string>


using namespace std;

// Costructores
Empleado::Empleado(void)
{
	cargo = "";
}

Empleado::Empleado(string ced, string nom, string apell, string carg) : Persona(ced, nom, apell)
{
	this->cargo = carg;
}

Empleado::~Empleado(void)
{
}

// Setters
void Empleado::set_cargo(string cargo)
{
	this->cargo = cargo;
}

// Getters
string Empleado::get_cargo()
{
	return this->cargo;
}

void Empleado::imprimirDatos()
{
	cout << "Nombre: " << this->get_nombre() << endl;
	cout << "Apellido: " << this->get_apellido() << endl;
	cout << "Cedula: " << this->get_cedula() << endl;
	cout << "Cargo: " << this->cargo << endl;
}

std::string	Empleado::toString()
{
	return this->get_cedula() + "," + this->get_nombre() + "," + this->get_apellido() + "," + this->cargo;
		
}