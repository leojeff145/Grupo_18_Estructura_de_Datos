#pragma once
#include "Empleado.h"
class RolDePago
{
private:
	Empleado empleado;
	float sueldo;
	float horasExtras;
	float feriados;
	float subTotal;
	float fondosReserva;
	float totalIngresos;
	float retencionIess;
	float desPrestamoIess;
	float totalRetencion;
	float netoRecibir;
	
public:
	RolDePago(Empleado, float, float, float, float, float, float, float, float, float,float);
	RolDePago(Empleado, float, float, float,float);
	RolDePago() = default;
	Empleado get_empleado();
	float get_sueldo();
	float get_horasExtra();
	float get_feriados();
	float get_subTotal();
	float get_fondosReserva();
	float get_totalIngreso();
	float get_retencionIess();
	float get_prestamoIess();
	float get_totalRetencion();
	float get_netoRecibir();
	void set_sueldo(float);
	void set_horasExtra(float);
	void set_feriados(float);
	void set_subTotal(float);
	void set_fondosReserva(float);
	void set_totalIngreso(float);
	void set_retencionIess(float);
	void set_prestamoIess(float);
	void set_totalRetencion(float);
	void set_netoRecibir(float);	
	void imprimirDatos();
	std::string toString();
};

