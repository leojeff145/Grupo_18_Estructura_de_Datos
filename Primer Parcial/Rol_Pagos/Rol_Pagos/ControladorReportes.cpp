
#include "ControladorReportes.h"
#include "ControladorRegistro.h"
#include "Validacion.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

void ControladorReportes::mostrarPersonal() {
	auto clientes = controladorRegistro.leerClientes();	
	if (clientes.estaVacio()) {
		cout << "No existen empleados registrados";
		return;
	}

	clientes.recorrer([](Empleado cliente) {
	std::cout << "CEDULA    : " << cliente.get_cedula() << std::endl;
	std::cout << "NOMBRES   : " << cliente.get_nombre() << std::endl;
	std::cout << "APELLIDOS : " << cliente.get_apellido() << std::endl;
	std::cout << "CARGO     : " << cliente.get_cargo() << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
		});
}


void ControladorReportes::mostrarRolDePago() {
	auto clientes = controladorRegistro.leerRolDePago();
	clientes.recorrer([](RolDePago cliente) {
		std::cout << "CEDULA    : " << cliente.get_empleado().get_cedula() << std::endl;
	std::cout << "NOMBRES   : " << cliente.get_empleado().get_nombre() << std::endl;
	std::cout << "APELLIDOS : " << cliente.get_empleado().get_apellido() << std::endl;
	std::cout << "CARGO     : " << cliente.get_empleado().get_cargo() << std::endl;
	std::cout << "INFORMACION ROL PAGO:" << std::endl;
	std::cout << "    SALARIO UNIFICADO     :  " << cliente.get_sueldo() << std::endl;
	std::cout << "    SALARIO HORAS EXTRAS  :  " << cliente.get_horasExtra() << std::endl;
	std::cout << "    SALARIO FERIADOS      :  " << cliente.get_feriados() << std::endl;
	std::cout << "    SUB TOTAL             :  " << cliente.get_subTotal() << std::endl;
	std::cout << "    FONDOS DE RESERVA     :  " << cliente.get_fondosReserva() << std::endl;
	std::cout << "    TOTAL DE INGRESOS     :  " << cliente.get_totalIngreso() << std::endl;
	std::cout << "    RETENCION IESS        :  " << cliente.get_retencionIess() << std::endl;
	std::cout << "    PRESTAMO IESS         :  " << cliente.get_prestamoIess() << std::endl;
	std::cout << "    TOTAL DE RETENCION    :  " << cliente.get_totalRetencion() << std::endl;
	std::cout << "    SUELDO NETO A RECIBIR :  " << cliente.get_netoRecibir() << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
		});
}


void ControladorReportes::buscarRolDePago() {
	auto clientes = controladorRegistro.leerRolDePago();
	std::string cedula;
	Nodo_Doble<RolDePago>* encontrado;

	if (clientes.estaVacio()) {		
		cout << "No se encontraron empleados registrados" << endl;
		return;
	}

	do {
		cout << "Ingresar Cedula: ";
		cedula = Validacion::leer_cadena_regex("", "^[0-9]{10}$");
		
		if (!Validacion::cedula_valida(cedula)) {			
			cout << "Cedula invalida" << endl;
			continue;
		}

		encontrado = clientes.buscar([cedula](RolDePago c) {
			return c.get_empleado().get_cedula() == cedula;
			});

		if (!encontrado) {			
			cout << "Cedula no registrada" << endl;
			continue;
		}

		break;
	} while (true);

	RolDePago cliente = encontrado->get_dato();

	std::cout << "CEDULA    : " << cliente.get_empleado().get_cedula() << std::endl;
	std::cout << "NOMBRES   : " << cliente.get_empleado().get_nombre() << std::endl;
	std::cout << "APELLIDOS : " << cliente.get_empleado().get_apellido() << std::endl;
	std::cout << "CARGO     : " << cliente.get_empleado().get_cargo() << std::endl;
	std::cout << "INFORMACION ROL PAGO:" << std::endl;
	std::cout << "    SALARIO UNIFICADO     :  " << cliente.get_sueldo() << std::endl;
	std::cout << "    SALARIO HORAS EXTRAS  :  " << cliente.get_horasExtra() << std::endl;
	std::cout << "    SALARIO FERIADOS      :  " << cliente.get_feriados() << std::endl;
	std::cout << "    SUB TOTAL             :  " << cliente.get_subTotal() << std::endl;
	std::cout << "    FONDOS DE RESERVA     :  " << cliente.get_fondosReserva() << std::endl;
	std::cout << "    TOTAL DE INGRESOS     :  " << cliente.get_totalIngreso() << std::endl;
	std::cout << "    RETENCION IESS        :  " << cliente.get_retencionIess() << std::endl;
	std::cout << "    PRESTAMO IESS         :  " << cliente.get_prestamoIess() << std::endl;
	std::cout << "    TOTAL DE RETENCION    :  " << cliente.get_totalRetencion() << std::endl;
	std::cout << "    SUELDO NETO A RECIBIR :  " << cliente.get_netoRecibir() << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
}

void ControladorReportes::buscarPersonal() {
	auto clientes = controladorRegistro.leerRolDePago();
	std::string cedula;
	Nodo_Doble<RolDePago>* encontrado;

	if (clientes.estaVacio()) {		
		cout << "No se encontraron Empleados" << endl;
		return;
	}

	do {
		cout << "Ingresar Cedula: ";
		cedula = Validacion::leer_cadena_regex("", "^[0-9]{10}$");

		if (!Validacion::cedula_valida(cedula)) {			
			cout << "Cedula invalida" << endl;
			continue;
		}

		encontrado = clientes.buscar([cedula](RolDePago c) {
			return c.get_empleado().get_cedula() == cedula;
			});

		if (!encontrado) {			
			cout << "Cedula no registrada" << endl;
			continue;
		}

		break;
	} while (true);

	RolDePago cliente = encontrado->get_dato();

	std::cout << "CEDULA    : " << cliente.get_empleado().get_cedula() << std::endl;
	std::cout << "NOMBRES   : " << cliente.get_empleado().get_nombre() << std::endl;
	std::cout << "APELLIDOS : " << cliente.get_empleado().get_apellido() << std::endl;
	std::cout << "CARGO     : " << cliente.get_empleado().get_cargo() << std::endl;

}



