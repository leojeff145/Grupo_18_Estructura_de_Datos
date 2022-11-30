#pragma once
#include "ListaCircularDoble.h"
#include "Empleado.h"
#include "RolDePago.h"
class ControladorRegistro
{
public:
	void registrarEmpleado();
	void registrarRolPago();

	ListaCircularDoble<Empleado> leerClientes();
	void guardarCliente(Empleado empleadoLC);
	//void mostrarClientes();

	ListaCircularDoble<RolDePago> leerRolDePago();
	void guardarRolDePago(RolDePago roldepagoLC);
	//void mostrarRolDePago();
	
};

