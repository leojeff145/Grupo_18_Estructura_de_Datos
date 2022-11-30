#pragma once
#include "ControladorRegistro.h"
class ControladorReportes	
{
private:
	ControladorRegistro controladorRegistro;

public:
	void mostrarPersonal();
	void mostrarRolDePago();
	void buscarRolDePago();
	void buscarPersonal();
};

