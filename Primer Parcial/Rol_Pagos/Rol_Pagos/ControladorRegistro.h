#pragma once
#include "ListaCircularDoble.h"
#include "Empleado.h"
#include "RolDePago.h"
#include "Provincia.h"
class ControladorRegistro
{
public:
	void registrarEmpleado();
	void registrarRolPago();
	void eliminarPorApellido();
	int contadorPorProvincia(string numProvincia);
	void empleadosPorProvincia();
	void numEmpleadosPorProvincia();
	void numEmpleadosEnProvinciasLambda();

	ListaCircularDoble<Empleado> leerClientes();
	void guardarEmpleado(Empleado empleadoLC);
	
	//void mostrarClientes();

	ListaCircularDoble<RolDePago> leerRolDePago();
	void guardarRolDePago(RolDePago roldepagoLC);
	//void mostrarRolDePago();	
	
	ListaCircularDoble<Provincia> generarListaProvincias();
	
	
	
	};


