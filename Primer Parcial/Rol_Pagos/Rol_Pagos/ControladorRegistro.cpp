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
	guardarEmpleado(cliente);	
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

	
	float salarioR = Validacion::leer_flotante("Ingrese el salario : ", 0.f);		
	float horasR = Validacion::leer_flotante("Ingrese el salario por horas extras: ", 0.f);	
	float feriadoR = Validacion::leer_flotante("Ingrese el salario por feriados: ", 0.f);	
	float prestamoR = Validacion::leer_flotante("Ingrese el descuento por  prestamo realizado al IESS: ", 0.f);

	Empleado trabajador = encontrado->get_dato();
	RolDePago asistencia(trabajador, salarioR, horasR, feriadoR, prestamoR);
	guardarRolDePago(asistencia);	
	cout << "Datos guardados";
}

// LISTA CIRCULARES
ListaCircularDoble<Empleado> ControladorRegistro::leerClientes() {
	
	ListaCircularDoble<Empleado> clientes;

	Validacion::leer_lineas("EmpleadosLC.txt", [&](std::string linea, ListaCircularDoble<std::string> columnas) {
	std::string cedula = columnas.obtenerNodo(0)->get_dato();
	std::string nombres = columnas.obtenerNodo(1)->get_dato();
	std::string apellidos = columnas.obtenerNodo(2)->get_dato();
	std::string cargo = columnas.obtenerNodo(3)->get_dato();

	Empleado cliente(cedula, nombres, apellidos, cargo);
	clientes.insertarFinal(cliente);
		});

	return clientes;
}


void ControladorRegistro::guardarEmpleado(Empleado cliente) {
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
	std::string cedula = columnas.obtenerNodo(0)->get_dato();
	std::string salarioU = columnas.obtenerNodo(1)->get_dato();
	std::string salarioH = columnas.obtenerNodo(2)->get_dato();
	std::string feriadosU = columnas.obtenerNodo(3)->get_dato();
	std::string prestamoI = columnas.obtenerNodo(8)->get_dato();
	std::string total = columnas.obtenerNodo(5)->get_dato();
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
	RolDePago asistencia(cliente, salarioU1, salarioH1, feriadosU1,prestamoI1);
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

void ControladorRegistro::eliminarPorApellido()
{
	std::string apellidos;
	auto clientes=leerClientes();	
	Nodo_Doble<Empleado>* encontrado;
	
	
	if (clientes.estaVacio()) {
		cout << "No existen empleados registrados";
		return;
	}	
	
	do {
		cout << "Ingresar Apellido: ";
		apellidos = Validacion::leer_cadena_regex("", "^[a-zA-Z]{2,}(\\s[a-zA-Z]{2,})?$");		

		encontrado = clientes.buscar([apellidos](Empleado empleado) {
			return empleado.get_apellido() == apellidos;
			});

		if (!encontrado) {
			cout << "Apellido no registrado"<<endl;
			continue;
		}

		while (encontrado) {
			
			clientes.eliminar([apellidos](Empleado c) {
				return c.get_apellido() == apellidos;
				});

			std::ofstream archivo("EmpleadosLC.txt", std::ios::trunc);

			clientes.recorrer([&](Empleado c) {
				archivo << c.toString() << std::endl;
				});
			archivo.close();

			encontrado = clientes.buscar([apellidos](Empleado c) {
				return c.get_apellido() == apellidos;
				});
		};

		if (!encontrado) {
			cout << " SE HA BORRADO CORRECTAMENTE" << endl;
		}

		break;
	} while (true);

	
}

//--------------------------------------------------------------------------------------------

int ControladorRegistro::contadorPorProvincia(string numProvincia) {	
	auto clientes = leerClientes(); // Lista tipo Empleado
	
	int contador = 0;
				
	
	clientes.recorrer([&](Empleado c) {		
		if (c.get_cedula().substr(0,2) == numProvincia) {
			contador++;		
		}
		});
		
	
	return contador;
	
}


void ControladorRegistro::empleadosPorProvincia() {
	
	//01	Azuay
	ControladorRegistro::contadorPorProvincia("01");
	if (contadorPorProvincia("01") > 0) {
		cout << "Azuay: " << contadorPorProvincia("01") << endl;
	}
	//02	Bolivar
	ControladorRegistro::contadorPorProvincia("02");
	if (contadorPorProvincia("02") > 0) {
		cout << "Bolivar:   " << contadorPorProvincia(" 0 2") << endl;
	}	
	//03	Cañar
	ControladorRegistro::contadorPorProvincia("03");
	if (contadorPorProvincia("03") > 0) {
		cout << "Cañar:    " << contadorPorProvincia("03") << endl;
	}
	//04	Carchi
	ControladorRegistro::contadorPorProvincia("04");
	if (contadorPorProvincia("04") > 0) {
		cout << "Carchi:    " << contadorPorProvincia("04") << endl;
	}
	//05	Cotopaxi
	ControladorRegistro::contadorPorProvincia("05");
	if (contadorPorProvincia("05") > 0) {
		cout << "Cotopaxi:    " << contadorPorProvincia("05") << endl;
	}
	//06	Chimborazo
	ControladorRegistro::contadorPorProvincia("06");
	if (contadorPorProvincia("06") > 0) {
		cout << "Chimborazo:    " << contadorPorProvincia("06") << endl;
	}
	//07	El Oro
	ControladorRegistro::contadorPorProvincia("07");
	if (contadorPorProvincia("07") > 0) {
		cout << "El Oro:    " << contadorPorProvincia("07") << endl;
	}
	//08	Esmeraldas
	ControladorRegistro::contadorPorProvincia("08");
	if (contadorPorProvincia("08") > 0) {
		cout << "Esmeraldas:    " << contadorPorProvincia("08") << endl;
	}
	//09	Guayas
	ControladorRegistro::contadorPorProvincia("09");
	if (contadorPorProvincia("09") > 0) {
		cout << "Guayas:    " << contadorPorProvincia("09") << endl;
	}
	//10	Imbabura
	ControladorRegistro::contadorPorProvincia("10");
	if (contadorPorProvincia("10") > 0) {
		cout << "Imbabura:    " << contadorPorProvincia("10") << endl;
	}
	//11	Loja
	ControladorRegistro::contadorPorProvincia("11");
	if (contadorPorProvincia("11") > 0) {
		cout << "Loja:    " << contadorPorProvincia("11") << endl;
	}
	//12	Los Ríos
	ControladorRegistro::contadorPorProvincia("12");
	if (contadorPorProvincia("12") > 0) {
		cout << "Los Ríos:    " << contadorPorProvincia("12") << endl;
	}
	//13	Manabí
	ControladorRegistro::contadorPorProvincia("13");
	if (contadorPorProvincia("13") > 0) {
		cout << "Manabí:    " << contadorPorProvincia("13") << endl;
	}
	//14	Morona Santiago
	ControladorRegistro::contadorPorProvincia("14");
	if (contadorPorProvincia("14") > 0) {
		cout << "Morona Santiago:    " << contadorPorProvincia("14") << endl;
	}
	//15	Napo
	ControladorRegistro::contadorPorProvincia("15");
	if (contadorPorProvincia("15") > 0) {
		cout << "Napo:    " << contadorPorProvincia("15") << endl;
	}
	//16	Pastaza
	ControladorRegistro::contadorPorProvincia("16");
	if (contadorPorProvincia("16") > 0) {
		cout << "Pastaza:    " << contadorPorProvincia("16") << endl;
	}
	//17	Pichincha
	ControladorRegistro::contadorPorProvincia("17");
	if (contadorPorProvincia("17") > 0) {
		cout << "Pichincha:    " << contadorPorProvincia("17") << endl;
	}
	//18	Tungurahua
	ControladorRegistro::contadorPorProvincia("18");
	if (contadorPorProvincia("18") > 0) {
		cout << "Tungurahua:    " << contadorPorProvincia("18") << endl;
	}
	//19	Zamora Chinchipe
	ControladorRegistro::contadorPorProvincia("19");
	if (contadorPorProvincia("19") > 0) {
		cout << "Zamora Chinchipe:    " << contadorPorProvincia("19") << endl;
	}	
	//20	Galápagos
	ControladorRegistro::contadorPorProvincia("20");
	if (contadorPorProvincia("20") > 0) {
		cout << "Galápagos:    " << contadorPorProvincia("20") << endl;
	}
	//21	Sucumbíos
	ControladorRegistro::contadorPorProvincia("21");
	if (contadorPorProvincia("21") > 0) {
		cout << "Sucumbíos:    " << contadorPorProvincia("21") << endl;
	}
	//22	Orellana
	ControladorRegistro::contadorPorProvincia("22");
	if (contadorPorProvincia("22") > 0) {
		cout << "Orellana:    " << contadorPorProvincia("22") << endl;
	}
	//23	Santo Domingo de los Tsáchilas
	ControladorRegistro::contadorPorProvincia("23");
	if (contadorPorProvincia("23") > 0) {
		cout << "Santo Domingo de los Tsáchilas:    " << contadorPorProvincia("23") << endl;
	}
	//24	Santa Elena
	ControladorRegistro::contadorPorProvincia("24");
	if (contadorPorProvincia("24") > 0) {
		cout << "Santa Elena:    " << contadorPorProvincia("24") << endl;
	}	
}

//------------------------CORRECCION----------------------

//Funcion que crea la lista de provincias
ListaCircularDoble<Provincia> ControladorRegistro::generarListaProvincias() {
	ListaCircularDoble<Provincia>* listaProvincias = new ListaCircularDoble<Provincia>();
	Provincia provincia;
	provincia.set_numProvincia("01");
	provincia.set_nombreProvincia("Azuay");
	listaProvincias->insertarFinal(provincia);
	provincia.set_numProvincia("02");
	provincia.set_nombreProvincia("Bolivar");
	listaProvincias->insertarFinal(provincia);
	provincia.set_numProvincia("03");
	provincia.set_nombreProvincia("Cañar");
	listaProvincias->insertarFinal(provincia);
	provincia.set_numProvincia("04");
	provincia.set_nombreProvincia("Carchi");
	listaProvincias->insertarFinal(provincia);
	provincia.set_numProvincia("05");
	provincia.set_nombreProvincia("Cotopaxi");
	listaProvincias->insertarFinal(provincia);
	provincia.set_numProvincia("06");
	provincia.set_nombreProvincia("Chimborazo");
	listaProvincias->insertarFinal(provincia);
	provincia.set_numProvincia("07");
	provincia.set_nombreProvincia("El Oro");
	listaProvincias->insertarFinal(provincia);
	provincia.set_numProvincia("08");
	provincia.set_nombreProvincia("Esmeraldas");
	listaProvincias->insertarFinal(provincia);
	provincia.set_numProvincia("09");
	provincia.set_nombreProvincia("Guayas");
	listaProvincias->insertarFinal(provincia);
	provincia.set_numProvincia("10");
	provincia.set_nombreProvincia("Imbabura");
	listaProvincias->insertarFinal(provincia);
	provincia.set_numProvincia("11");
	provincia.set_nombreProvincia("Loja");
	listaProvincias->insertarFinal(provincia);
	provincia.set_numProvincia("12");
	provincia.set_nombreProvincia("Los Rios");
	listaProvincias->insertarFinal(provincia);
	provincia.set_numProvincia("13");
	provincia.set_nombreProvincia("Manabi");
	listaProvincias->insertarFinal(provincia);
	provincia.set_numProvincia("14");
	provincia.set_nombreProvincia("Morona Santiago");
	listaProvincias->insertarFinal(provincia);
	provincia.set_numProvincia("15");
	provincia.set_nombreProvincia("Napo");
	listaProvincias->insertarFinal(provincia);
	provincia.set_numProvincia("16");
	provincia.set_nombreProvincia("Pastaza");
	listaProvincias->insertarFinal(provincia);
	provincia.set_numProvincia("17");
	provincia.set_nombreProvincia("Pichincha");
	listaProvincias->insertarFinal(provincia);
	provincia.set_numProvincia("18");
	provincia.set_nombreProvincia("Tungurahua");
	listaProvincias->insertarFinal(provincia);
	provincia.set_numProvincia("19");
	provincia.set_nombreProvincia("Zamora Chinchipe");
	listaProvincias->insertarFinal(provincia);
	provincia.set_numProvincia("20");
	provincia.set_nombreProvincia("Galapagos");
	listaProvincias->insertarFinal(provincia);
	provincia.set_numProvincia("21");
	provincia.set_nombreProvincia("Sucumbios");
	listaProvincias->insertarFinal(provincia);
	provincia.set_numProvincia("22");
	provincia.set_nombreProvincia("Orellana");
	listaProvincias->insertarFinal(provincia);
	provincia.set_numProvincia("23");
	provincia.set_nombreProvincia("Santo Domingo de los Tsachilas");
	listaProvincias->insertarFinal(provincia);
	provincia.set_numProvincia("24");
	provincia.set_nombreProvincia("Santa Elena");
	listaProvincias->insertarFinal(provincia);
	return *listaProvincias;
}

//Funcion que cuenta los registros por provincia
void ControladorRegistro::numEmpleadosPorProvincia() {
	ListaCircularDoble<Empleado> listaEmpleado;	
	listaEmpleado = ControladorRegistro::leerClientes();	
	
	if (listaEmpleado.estaVacio()) {
		cout << "No existen empleados registrados";
		return;
	}
	
	for (int i = 0; i < ControladorRegistro::generarListaProvincias().total(); i++) {
		int contador = 0;
		for (int j = 0; j < listaEmpleado.total(); j++) {
			if (listaEmpleado.obtenerNodo(j)->get_dato().get_cedula().substr(0,2) == ControladorRegistro::generarListaProvincias().obtenerNodo(i)->get_dato().get_numProvincia()) {
				contador++;
			}
		}
		if (contador > 0) {
			cout << "----------------------------------------------------------" << endl;
			cout << "Provincia: " << ControladorRegistro::generarListaProvincias().obtenerNodo(i)->get_dato().get_nombreProvincia() << endl;
			cout << "Numero de empleados: " << contador << endl;
		}		
	}	
}

//Usando Lambdas

void ControladorRegistro::numEmpleadosEnProvinciasLambda() {
	auto listaEmpleado = leerClientes();
	auto listaProvincias = generarListaProvincias();
	if (listaEmpleado.estaVacio()) {
		cout << "No existen empleados registrados";
		return;
	}
	listaProvincias.recorrer([&](Provincia prov) {
		int contador = 0;
	listaEmpleado.recorrer([&](Empleado emp) {
		if (emp.get_cedula().substr(0,2) == prov.get_numProvincia()) {
			contador++;
		}	
			});
	if (contador > 0) {
		cout << "----------------------------------------------------------" << endl;
		cout << "Provincia: " << prov.get_nombreProvincia() << endl;
		cout << "Numero de empleados: " << contador << endl;
	}
		});
	
}
