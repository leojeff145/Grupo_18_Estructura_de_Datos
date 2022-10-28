/*************************
 * UFA-ESPE
 * ALUMNOS:  Leonardo Obando, William Leon
 * FECHA CREACION: jueves, 27 de octubre de 2022 
 * FECHA MODIFICACION: jueves, 27 de octubre de 2022 
 * Enunciado del problema: Realizar un programa basado en tipo 
   de datos abstractos para ingresar datos personales y calcular la edad 
 * Nivel: TERCERO NRC: 7999 
 *************************/

#include <iostream>
#include <string>
#include "Datos.cpp"
using namespace std;

int main(int argc, char** argv){
	std::string nombre;
	std::string apellido;	
	int dia,dia1;
	int mes,mes1;
	int anio,anio1;

    

    cout<<"\n\t*****Programa para calcular la Edad*****\n\n";
    cout<< "Ingrese Anio Actual: ";
    cin >> anio1;    
    cout<< "Ingrese Mes Actual: ";
    cin >> mes1;  
    cout<< "Ingrese Dia Actual: ";
    cin >> dia1;   
    cout<< "Ingrese su Nombre: ";
    cin >> nombre;    
    cout<< "Ingrese su Apellido: ";
    cin >> apellido;    
    cout<<"\n"<<endl;
    cout<< "-----------------------A continuacion ingrese su fecha de nacimiento----------------- \n";

    cout<< "Ingrese su Anio de nacimiento: ";
    cin >> anio;    
    cout<< "Ingrese su Mes de nacimiento: ";
    cin >> mes;   
    cout<< "Ingrese su Dia de nacimiento: ";
    cin >> dia;
    
    
     cout<<"\n"<<endl;
    cout<<"***************DATOS*********************************"<<endl;
    Datos *fNac = new Datos(nombre, apellido, anio, mes,dia);
    Datos *fAct = new Datos(anio1,mes1,dia1);
    Datos *dat1 = new Datos();
    
    dat1->PrintDat(*fNac);
    dat1->CalcEdad(*fAct,*fNac);
   
	
	return 0;
}