/*************************
 * UFA-ESPE
 * ALUMNOS:  Leonardo Obando, William Leon
 * FECHA CREACION: Marte, 1 de noviembre de 2022 
 * FECHA MODIFICACION: Miercoles, 2 de noviembre de 2022 
 * Enunciado del problema: Realizar 2 ejercicios, uno por cada 
 * integrante del grupo. Donde se debe sobrecargar 2 operadores
 * Nivel: TERCERO NRC: 7999 
 *************************/
#include <iostream>
#include "operadores.h"
#include <string>
using namespace std;


Operador::Operador(const int a,const int b)
{    
    this->A1 = a;
    this->B2 = b;
}

void Operador::setA(int a)
{    
    A1 = a; 
}

void Operador::setB(int b)
{    
    B2 = b; 
}

int Operador::getA(void)
{    
    return A1; 
}

int Operador::getB(void)
{    
    return B2; 
}

void Operador::CalcDat(Operador D1){
    int n1,n2,o;
    //try{
    n1=D1.getA();
  	n2=D1.getB();
      
      //  if((n1,n2) == (n1,n2)<0||" ")
       //     throw "Los digitos ingresado debe ser numero entero";
       
        
        o = n1^n2;
        cout << "Resultado = "<< o << endl;

     // }catch(const char* error){
      //  cout<< error<<endl;
     // }
        
   
}
    
Operador :: Operador(){

}

int Operador::operator ^ (Operador O)
{    
    return (A1^O.getA(), B2^O.getB()); 
}
