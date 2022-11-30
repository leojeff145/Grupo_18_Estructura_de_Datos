#pragma once
#include <iostream>
#include <string>

class Persona
{
private:
	std::string nombre;
	std::string apellido;
	std::string cedula;
	
public:
	Persona(void);
	Persona(std::string, std::string, std::string);
	~Persona(void);
	void set_nombre(std::string);
	void set_apellido(std::string);
	void set_cedula(std::string);
	std::string get_nombre();
	std::string get_apellido();
	std::string get_cedula();
	void imprimirDatos();
	std::string	toString();
};

