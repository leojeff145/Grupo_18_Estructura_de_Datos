#pragma once
#include <iostream>
#include <string>
#include "Persona.h"

class Empleado : public Persona
{
private:
	std::string cargo;
	
public:
	Empleado(void);
	Empleado(std::string, std::string, std::string, std::string);
	~Empleado(void);
	void set_cargo(std::string);
	std::string get_cargo();
	void imprimirDatos();
	std::string	toString();
};


