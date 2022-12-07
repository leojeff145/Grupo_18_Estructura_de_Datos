#pragma once
#include <iostream>
#include <string>
class Provincia
{
private:
	std::string numProvincia;
	std::string nombreProvincia;
public:
	Provincia(void);
	Provincia(std::string, std::string);
	~Provincia(void);
	void set_numProvincia(std::string);
	void set_nombreProvincia(std::string);
	std::string get_numProvincia();
	std::string get_nombreProvincia();
	void imprimirDatos();
	std::string	toString();
};

