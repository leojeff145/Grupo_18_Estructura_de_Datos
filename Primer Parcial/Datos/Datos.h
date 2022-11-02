/***********************************************************************
 * Module:  Datos.h
 * Author:  jeffe
 * Modified: viernes, 28 de octubre de 2022
 * Purpose: Declaration of the class Datos
 ***********************************************************************/

#if !defined(__EdadPersona2_Datos_h)
#define __EdadPersona2_Datos_h
#include <iostream>
#include <string.h>

class Datos
{
public:
   Datos(std::string nombre, std::string apellido, int ano, int mes, int dia);
   //~Datos();
   Datos(int anio, int mes, int dia);
   std::string getNombre(void);
   void setNombre(std::string newNombre);
   std::string getApellido(void);
   void setApellido(std::string newApellido);
   int getAnio(void);
   void setAnio(int newAnio);
   int getDia(void);
   void setDia(int newDia);
   int getMes(void);
   void setMes(int newMes);
   void PrintDat(Datos datos);
   void CalcEdad(Datos fechaActual, Datos fechaNacimiento);
   Datos();

protected:
private:
   std::string nombre;
   std::string apellido;
   int anio;
   int dia;
   int mes;


};

#endif
