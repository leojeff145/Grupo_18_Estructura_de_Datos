#pragma once
#include "ControladorRegistro.h"
class ControladorReportes	
{
private:
	ControladorRegistro controladorRegistro;

public:
	void mostrarClientes();
	void mostrarRolDePago();
	void buscarRolDePago();

	void mostrarClientesLD();
	void mostrarRolDePagoLD();
	void buscarRolDePagoLD();

	void mostrarClientesLS();
	void mostrarRolDePagoLS();
	void buscarRolDePagoLS();
};

