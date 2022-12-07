#include "Provincia.h"

Provincia::Provincia(void)
{
}

Provincia::Provincia(std::string numProvincia, std::string nombreProvincia)
{
	this->numProvincia = numProvincia;
	this->nombreProvincia = nombreProvincia;
}

Provincia::~Provincia(void)
{
}

void Provincia::set_numProvincia(std::string numProvincia)
{
	this->numProvincia = numProvincia;
}

void Provincia::set_nombreProvincia(std::string nombreProvincia)
{
	this->nombreProvincia = nombreProvincia;
}

std::string Provincia::get_numProvincia()
{
	return numProvincia;
}

std::string Provincia::get_nombreProvincia()
{
	return nombreProvincia;
}

void Provincia::imprimirDatos()
{
	std::cout << "Numero de Provincia: " << numProvincia << std::endl;
	std::cout << "Nombre de Provincia: " << nombreProvincia << std::endl;
}

std::string Provincia::toString()
{
	return this->get_numProvincia() + "," + this->get_nombreProvincia();
}