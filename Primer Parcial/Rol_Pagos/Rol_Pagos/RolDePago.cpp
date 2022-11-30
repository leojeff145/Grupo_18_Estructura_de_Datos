#include "RolDePago.h"
#include <iostream>
#include <string>

using namespace std;
#define porcentajeIes 0.0945;


RolDePago::RolDePago(Empleado empleado, float sueldo, float horasExtras, float feriados, float subTotal, float fondosReserva, float totalIngresos, float retencionIess,float iess, float totalRetencion, float netoRecibir)
{
	this->empleado = empleado;
	this->sueldo = sueldo;
	this->horasExtras = horasExtras;
	this->feriados = feriados;
	this->subTotal = subTotal;
	this->fondosReserva = fondosReserva;
	this->totalIngresos = totalIngresos;
	this->retencionIess = retencionIess;
	this->desPrestamoIess = iess;
	this->totalRetencion = totalRetencion;
	this->netoRecibir = netoRecibir;
}

RolDePago::RolDePago(Empleado empleado, float sueldo, float horasExtras, float feriados,float Iess)
{
	this->empleado = empleado;
	this->sueldo = sueldo;
	this->horasExtras = horasExtras;
	this->feriados = feriados;
	this->desPrestamoIess = Iess;	
	this->subTotal = sueldo + horasExtras + feriados;
	this->fondosReserva = subTotal / 12;
	this->totalIngresos = subTotal + fondosReserva;
	this->retencionIess = subTotal * porcentajeIes;
	this->totalRetencion = retencionIess + Iess ;
	this->netoRecibir = totalIngresos - totalRetencion;
}

Empleado RolDePago::get_empleado()
{
	return empleado;
}

float RolDePago::get_sueldo()
{
	return sueldo;
}

float RolDePago::get_horasExtra()
{
	return horasExtras;
}

float RolDePago::get_feriados()
{
	return feriados;
}

float RolDePago::get_subTotal()
{
	return subTotal;
}

float RolDePago::get_fondosReserva()
{
	return fondosReserva;
}

float RolDePago::get_totalIngreso()
{
	return totalIngresos;
}

float RolDePago::get_retencionIess()
{
	return retencionIess;
}

float RolDePago::get_prestamoIess()
{
	return desPrestamoIess;
}

float RolDePago::get_totalRetencion()
{
	return totalRetencion;
}

float RolDePago::get_netoRecibir()
{
	return netoRecibir;
}

void RolDePago::set_sueldo(float sueldo)
{
	this->sueldo = sueldo;
}

void RolDePago::set_horasExtra(float horasExtras)
{
	this->horasExtras = horasExtras;
}

void RolDePago::set_feriados(float feriados)
{
	this->feriados = feriados;
}

void RolDePago::set_subTotal(float subTotal)
{
	this->subTotal = subTotal;
}

void RolDePago::set_fondosReserva(float fondosReserva)
{
	this->fondosReserva = fondosReserva;
}

void RolDePago::set_totalIngreso(float totalIngresos)
{
	this->totalIngresos = totalIngresos;
}

void RolDePago::set_retencionIess(float retencionIess)
{
	this->retencionIess = retencionIess;
}

void RolDePago::set_prestamoIess(float prestamoIess)
{
	this->desPrestamoIess = prestamoIess;
}

void RolDePago::set_totalRetencion(float totalRetencion)
{
	this->totalRetencion = totalRetencion;
}

void RolDePago::set_netoRecibir(float netoRecibir)
{
	this->netoRecibir = netoRecibir;
}

void RolDePago::imprimirDatos() {
	std::cout << "INFORMACION EMPLEADO" << std::endl;
	std::cout << "NUM CEDULA: " << empleado.get_cedula() << std::endl;
	std::cout << "NOMBRE: " << empleado.get_nombre() << std::endl;
	std::cout << "APELLIDO: " << empleado.get_apellido() << std::endl;
	std::cout << "CARGO: " << empleado.get_cargo() << std::endl;
	std::cout << "   INFORMACION ROL DE PAGO" << std::endl;
	std::cout << "       SUELDO " << sueldo << std::endl;
	std::cout << "       HORAS EXTRAS " << horasExtras << std::endl;
	std::cout << "       FERIADOS " << feriados << std::endl;
	std::cout << "       SUB TOTAL " << subTotal << std::endl;
	std::cout << "       FONDOS RESERVA " << fondosReserva << std::endl;
	std::cout << "       TOTAL INGRESOS " << totalIngresos << std::endl;
	std::cout << "       RETENCION IESS " << retencionIess << std::endl;
	std::cout << "       PRESTAMO IESS " << desPrestamoIess << std::endl;
	std::cout << "       TOTAL RETENCION " << totalRetencion << std::endl;
	std::cout << "       SUELDO NETO A RECIBIR " << netoRecibir << std::endl;
	std::cout << "\n";
}

std::string RolDePago::toString() {
	return empleado.get_cedula() + "," +
		std::to_string(sueldo) + "," +
		std::to_string(horasExtras) + "," +
		std::to_string(feriados) + "," +
		std::to_string(subTotal) + "," +
		std::to_string(fondosReserva) + "," +
		std::to_string(totalIngresos) + "," +
		std::to_string(retencionIess) + "," +
		std::to_string(desPrestamoIess) + "," +
		std::to_string(totalRetencion) + "," +
		std::to_string(netoRecibir);
}