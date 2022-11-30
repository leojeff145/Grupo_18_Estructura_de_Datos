#include "ControladorRegistro.h"
#include "Validacion.h"

#include <string>
#include <sstream>

using namespace std;

// INGRESO GENERAL
void ControladorRegistro::registrarEmpleado() {
	std::string cedula;
	std::string nombres;
	std::string apellidos;
	std::string cargo;

	std::cout << "Registrar cliente:" << std::endl << std::endl;
	cout << "Ingrese Apellidos: ";
	apellidos = Validacion::leer_cadena_regex("", "^[a-zA-Z]{2,}(\\s[a-zA-Z]{2,})?$");
	cout << "Ingrese Nombres: ";
	nombres = Validacion::leer_cadena_regex("", "^[a-zA-Z]{2,}(\\s[a-zA-Z]{2,})?$");
	cout << "Ingrese Cargo: ";
	cargo = Validacion::leer_cadena_regex("", "^[a-zA-Z]{2,}(\\s[a-zA-Z]{2,})?$");

	auto clientes = leerClientes();

	do {
		cout << "Ingresar Cedula: ";
		cedula = Validacion::leer_cadena_regex("", "^[0-9]{10}$");

		if (!Validacion::cedula_valida(cedula)) {			
			cout << "Cedula invalida"<<endl;
			continue;
		}

		auto encontrado = clientes.buscar([cedula](Empleado c) {
			return c.get_cedula() == cedula;
			});

		if (encontrado) {			
			cout << "Cedula ya registrada"<<endl;
			continue;
		}

		break;
	} while (true);
	
	Empleado cliente(cedula,nombres,apellidos,cargo);
	guardarCliente(cliente);	
	cout << "Datos guardados";
}


void ControladorRegistro::registrarRolPago() {
	std::string cedula;
	auto clientes = leerClientes(); // Lista tipo Empleado
	Nodo_Doble<Empleado>* encontrado;

	if (clientes.estaVacio()) {		
		cout << "No existen empleados registrados";
		return;
	}

	do {
		cout << "Ingresar Cedula: ";
		cedula = Validacion::leer_cadena_regex("", "^[0-9]{10}$");

		if (!Validacion::cedula_valida(cedula)) {			
			cout << "Cedula invalida"<<endl;
			continue;
		}

		encontrado = clientes.buscar([cedula](Empleado c) {
			return c.get_cedula() == cedula;
			});

		if (!encontrado) {			
			cout << "Cedula no registrada";
			continue;
		}

		break;
	} while (true);

	float salarioR = Validacion::leer_flotante("Ingrese el salario unificado: ", 0.f);
	float horasR = Validacion::leer_flotante("Ingrese el salario horas extras: ", 0.f);
	float feriadoR = Validacion::leer_flotante("Ingrese el salario por feriados: ", 0.f);
	float prestamoR = Validacion::leer_flotante("Ingrese el prestamo realizado al IESS: ", 0.f);

	Empleado cliente = encontrado->get_dato();
	RolDePago asistencia(cliente, salarioR, horasR, feriadoR, prestamoR);
	guardarRolDePago(asistencia);	
	cout << "Datos guardados";
}

// LISTA CIRCULARES
ListaCircularDoble<Empleado> ControladorRegistro::leerClientes() {
	
	ListaCircularDoble<Empleado> clientes;

	Validacion::leer_lineas("EmpleadosLC.txt", [&](std::string linea, ListaCircularDoble<std::string> columnas) {
	std::string cedula = columnas.getPosicion(0)->get_dato();
	std::string nombres = columnas.getPosicion(1)->get_dato();
	std::string apellidos = columnas.getPosicion(2)->get_dato();
	std::string cargo = columnas.getPosicion(3)->get_dato();

	Empleado cliente(cedula, nombres, apellidos, cargo);
	clientes.insertarFinal(cliente);
		});

	return clientes;
}


void ControladorRegistro::guardarCliente(Empleado cliente) {
	auto clientes = leerClientes();
	std::ofstream archivo("EmpleadosLC.txt", std::ios::trunc);

	clientes.recorrer([&](Empleado c) {
		archivo << c.toString() << std::endl;
		});

	archivo << cliente.toString() << std::endl;
	archivo.close();
}


ListaCircularDoble<RolDePago> ControladorRegistro::leerRolDePago() {
	ListaCircularDoble<RolDePago> asistencias;
	auto clientes = leerClientes();

	Validacion::leer_lineas("RoldePagoLC.txt", [&](std::string linea, ListaCircularDoble<std::string> columnas) {
		std::string cedula = columnas.getPosicion(0)->get_dato();
	std::string salarioU = columnas.getPosicion(1)->get_dato();
	std::string salarioH = columnas.getPosicion(2)->get_dato();
	std::string feriadosU = columnas.getPosicion(3)->get_dato();
	std::string prestamoI = columnas.getPosicion(4)->get_dato();
	std::string total = columnas.getPosicion(5)->get_dato();
	float salarioU1 = std::stof(salarioU);
	float salarioH1 = std::stof(salarioH);
	float feriadosU1 = std::stof(feriadosU);
	float prestamoI1 = std::stof(prestamoI);

	auto encontrado = clientes.buscar([&](Empleado cliente) {
		return cliente.get_cedula() == cedula;
		});

	if (!encontrado) {
		return;
	}

	Empleado cliente = encontrado->get_dato();
	RolDePago asistencia(cliente, salarioU1, salarioH1, feriadosU1, prestamoI1);
	asistencias.insertarFinal(asistencia);
		});

	return asistencias;
}


void ControladorRegistro::guardarRolDePago(RolDePago asistencia) {
	auto asistencias = leerRolDePago();
	std::ofstream archivo("RoldePagoLC.txt", std::ios::trunc);

	asistencias.recorrer([&](RolDePago a) {
		archivo << a.toString() << std::endl;
		});

	archivo << asistencia.toString() << std::endl;
	archivo.close();
}

