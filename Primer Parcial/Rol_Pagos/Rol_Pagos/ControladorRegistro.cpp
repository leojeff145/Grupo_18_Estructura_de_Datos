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

	apellidos = Validacion::leer_cadena_regex("Ingrese los apellidos: ", "^[a-zA-Z]{2,}(\\s[a-zA-Z]{2,})?$");
	nombres = Validacion::leer_cadena_regex("Ingrese los nombres: ", "^[a-zA-Z]{2,}(\\s[a-zA-Z]{2,})?$");
	cargo = Validacion::leer_cadena_regex("Ingrese el cargo: ", "^[a-zA-Z]{2,}(\\s[a-zA-Z]{2,})?$");

	auto clientes = leerClientes();

	do {
		cedula = Validacion::leer_cadena_regex("Ingrese la cedula: ", "^[0-9]{10}$");

		if (!Validacion::cedula_valida(cedula)) {
			//Validacion::mostrar_mensaje("Cedula invalida", TipoMensaje::Error);
			cout << "Cedula invalida";
			continue;
		}

		auto encontrado = clientes.buscar([cedula](Empleado c) {
			return c.get_cedula() == cedula;
			});

		if (encontrado) {
			//Validacion::mostrar_mensaje("Cedula ya registrada", TipoMensaje::Error);
			cout << "Cedula ya registrada";
			continue;
		}

		break;
	} while (true);
	
	Empleado cliente(cedula,nombres,apellidos,cargo);
	guardarCliente(cliente);
	//guardarEmpleadoLD(cliente);
	//guardarEmpleadoLS(cliente);
	//Validacion::mostrar_mensaje("Datos guardados", TipoMensaje::Correcto);
	cout << "Datos guardados";
}
void ControladorRegistro::registrarRolPago() {
	std::string cedula;
	auto clientes = leerClientes(); // Lista tipo Empleado
	Nodo_Doble<Empleado>* encontrado;

	if (clientes.estaVacio()) {
		//Validacion::mostrar_mensaje("No existen empleados registrados", TipoMensaje::Error);
		cout << "No existen empleados registrados";
		return;
	}

	do {
		cedula = Validacion::leer_cadena_regex("Ingrese la cedula: ", "^[0-9]{10}$");

		if (!Validacion::cedula_valida(cedula)) {
			//Validacion::mostrar_mensaje("Cedula invalida", TipoMensaje::Error);
			cout << "Cedula invalida";
			continue;
		}

		encontrado = clientes.buscar([cedula](Empleado c) {
			return c.get_cedula() == cedula;
			});

		if (!encontrado) {
			//Validacion::mostrar_mensaje("Cedula no registrada", TipoMensaje::Error);
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
	//guardarRolDePagoLD(asistencia);
	//guardarRolDePagoLS(asistencia);
	//Validacion::mostrar_mensaje("Datos guardados", TipoMensaje::Correcto);
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

// LISTAS DOBLES
/*
ListaDoble<Empleado> ControladorRegistro::leerEmpleadoLD() {
	ListaDoble<Empleado> clientes;

	Utileria::leer_lineasLD("EmpleadosLD.txt", [&](std::string linea, ListaDoble<std::string> columnas) {
		std::string cedula = columnas.obtenerNodoLD(0)->getValor();
	std::string nombres = columnas.obtenerNodoLD(1)->getValor();
	std::string apellidos = columnas.obtenerNodoLD(2)->getValor();
	std::string cargo = columnas.obtenerNodoLD(3)->getValor();

	Empleado cliente(nombres, apellidos, cedula, cargo);
	clientes.insertarFinalLD(cliente);
		});

	return clientes;
}
void ControladorRegistro::guardarEmpleadoLD(Empleado cliente) {
	auto clientes = leerEmpleadoLD();
	std::ofstream archivo("EmpleadosLD.txt", std::ios::trunc);

	clientes.recorrerLD([&](Empleado c) {
		archivo << c.toString() << std::endl;
		});

	archivo << cliente.toString() << std::endl;
	archivo.close();
}
ListaDoble<RolDePago> ControladorRegistro::leerRolDePagoLD() {
	ListaDoble<RolDePago> rolP;
	auto clientes = leerEmpleadoLD();

	Utileria::leer_lineasLD("RoldePagoLD.txt", [&](std::string linea, ListaDoble<std::string> columnas) {
		std::string cedula = columnas.obtenerNodoLD(0)->getValor();
	std::string salarioU = columnas.obtenerNodoLD(1)->getValor();
	std::string salarioH = columnas.obtenerNodoLD(2)->getValor();
	std::string feriadosU = columnas.obtenerNodoLD(3)->getValor();
	std::string prestamoI = columnas.obtenerNodoLD(4)->getValor();
	std::string total = columnas.obtenerNodoLD(5)->getValor();
	float salarioU1 = std::stof(salarioU);
	float salarioH1 = std::stof(salarioH);
	float feriadosU1 = std::stof(feriadosU);
	float prestamoI1 = std::stof(prestamoI);

	auto encontrado = clientes.buscarLD([&](Empleado cliente) {
		return cliente.getCedula() == cedula;
		});

	if (!encontrado) {
		return;
	}

	Empleado cliente = encontrado->getValor();
	RolDePago rolPago(cliente, salarioU1, salarioH1, feriadosU1, prestamoI1);
	rolP.insertarFinalLD(rolPago);
		});

	return rolP;
}
void ControladorRegistro::guardarRolDePagoLD(RolDePago rolpagos) {
	auto asistencias = leerRolDePagoLD();
	std::ofstream archivo("RoldePagoLD.txt", std::ios::trunc);

	asistencias.recorrerLD([&](RolDePago a) {
		archivo << a.toString() << std::endl;
		});

	archivo << rolpagos.toString() << std::endl;
	archivo.close();
}

// LISTAS SIMPLES
ListaSimple<Empleado> ControladorRegistro::leerEmpleadoLS() {
	ListaSimple<Empleado> clientes;

	Utileria::leer_lineasLS("EmpleadosLS.txt", [&](std::string linea, ListaSimple<std::string> columnas) {
		std::string cedula = columnas.obtenerNodoLS(0)->getValor();
	std::string nombres = columnas.obtenerNodoLS(1)->getValor();
	std::string apellidos = columnas.obtenerNodoLS(2)->getValor();
	std::string cargo = columnas.obtenerNodoLS(3)->getValor();

	Empleado cliente(nombres, apellidos, cedula, cargo);
	clientes.insertarFinalLS(cliente);
		});

	return clientes;
}
void ControladorRegistro::guardarEmpleadoLS(Empleado cliente) {
	auto clientes = leerEmpleadoLS();
	std::ofstream archivo("EmpleadosLS.txt", std::ios::trunc);

	clientes.recorrerLS([&](Empleado c) {
		archivo << c.toString() << std::endl;
		});

	archivo << cliente.toString() << std::endl;
	archivo.close();
}
ListaSimple<RolDePago> ControladorRegistro::leerRolDePagoLS() {
	ListaSimple<RolDePago> rolP;
	auto clientes = leerEmpleadoLS();

	Utileria::leer_lineasLS("RoldePagoLS.txt", [&](std::string linea, ListaSimple<std::string> columnas) {
		std::string cedula = columnas.obtenerNodoLS(0)->getValor();
	std::string salarioU = columnas.obtenerNodoLS(1)->getValor();
	std::string salarioH = columnas.obtenerNodoLS(2)->getValor();
	std::string feriadosU = columnas.obtenerNodoLS(3)->getValor();
	std::string prestamoI = columnas.obtenerNodoLS(4)->getValor();
	std::string total = columnas.obtenerNodoLS(5)->getValor();
	float salarioU1 = std::stof(salarioU);
	float salarioH1 = std::stof(salarioH);
	float feriadosU1 = std::stof(feriadosU);
	float prestamoI1 = std::stof(prestamoI);

	auto encontrado = clientes.buscarLS([&](Empleado cliente) {
		return cliente.getCedula() == cedula;
		});

	if (!encontrado) {
		return;
	}

	Empleado cliente = encontrado->getValor();
	RolDePago rolPago(cliente, salarioU1, salarioH1, feriadosU1, prestamoI1);
	rolP.insertarFinalLS(rolPago);
		});

	return rolP;
}
void ControladorRegistro::guardarRolDePagoLS(RolDePago rolpagos) {
	auto asistencias = leerRolDePagoLS();
	std::ofstream archivo("RoldePagoLS.txt", std::ios::trunc);

	asistencias.recorrerLS([&](RolDePago a) {
		archivo << a.toString() << std::endl;
		});

	archivo << rolpagos.toString() << std::endl;
	archivo.close();
}*/