/*************************
 * UFA-ESPE
 * ALUMNOS:  Leonardo Obando, William Leon
 * FECHA CREACION: jueves, 27 de octubre de 2022 
 * FECHA MODIFICACION: jueves, 27 de octubre de 2022 
 * Enunciado del problema: Realizar un programa basado en tipo 
   de datos abstractos para ingresar datos personales y calcular la edad 
 * Nivel: TERCERO NRC: 7999 
 *************************/

#include "Datos.h"
#include <iostream>
using namespace std;


Datos::Datos(std::string nom, std::string apell, int ano, int mes1, int dia1)
{
   this->nombre=nom;
   this->apellido=apell;
   this->anio=ano;
   this->mes=mes1;  
   this->dia=dia1;
}


//Datos::~Datos()
//{
   //delete[] nom;
   //delete[] apell;
   //delete[] ano;
   //delete[] mes1;
   //delete[] dia1;
//}


Datos::Datos(int anio, int mes, int dia)
{
   this->anio=anio;
   this->mes=mes;  
   this->dia=dia;
}


std::string Datos::getNombre(void)
{
   return nombre;
}



void Datos::setNombre(std::string newNombre)
{
   nombre = newNombre;
}


std::string Datos::getApellido(void)
{
   return apellido;
}


void Datos::setApellido(std::string newApellido)
{
   apellido = newApellido;
}


int Datos::getAnio(void)
{
   return anio;
}



void Datos::setAnio(int newAnio)
{
   anio = newAnio;
}



int Datos::getDia(void)
{
   return dia;
}



void Datos::setDia(int newDia)
{
   dia = newDia;
}


int Datos::getMes(void)
{
   return mes;
}



void Datos::setMes(int newMes)
{
   mes = newMes;
}




//funcion oara calcular la edad

void Datos::CalcEdad(Datos fechaActual, Datos fechaNacimiento)
{
  	int anio1, anio2,mes1,mes2,dia1,dia2,auxDia,auxMes;
  	anio1=fechaActual.getAnio();
  	anio2=fechaNacimiento.getAnio();
  	mes1=fechaActual.getMes();
   mes2=fechaNacimiento.getMes();
   dia1=fechaActual.getDia();
   dia2=fechaNacimiento.getDia();

   if ( dia2 < dia1 )
    {   //En caso de ser menor la fecha actual que el nacimiento
        dia1 =+ 30; 
        mes1 = mes1 - 1; 
        auxDia=dia1 - dia2; 
    }
    else //En caso de ser mayor la fecha actual que el nacimiento
        auxDia =  dia1 - dia2;  
 
    if( mes1 < mes2 )
    {   //En caso de ser menor el mes actual que el nacimiento
        mes1 =+ 12; 
        anio1 = anio1 - 1 ; 
        auxMes = mes1 - mes2; 
    }
    else //En caso de ser mayor el mes actual que el nacimiento
        auxMes = mes1 - mes2; 
 
    cout << " Edad: " <<anio1 - anio2 << endl; 
    cout << " Mes: " << auxMes << endl; 
    cout << " Dia: " << auxDia << endl; 
  	
}

void Datos::PrintDat(Datos datos)
{	
   cout<<"Nombre: "<<datos.getNombre()<<endl;
   cout<<"Apellido: "<<datos.getApellido()<<endl;
   cout<<"*************Su Edad es*************"<<endl;
}
Datos::Datos()
{
}
