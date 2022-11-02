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
#include "operadores.cpp"
using namespace std;

int main(int argc, char** argv) {  

    int O1, O2;
        
    cout<<"\n\t***** Sobrecargar Operador ^ *****\n\n";
    cout<< "Ingrese primer numero: ";
    cin >> O1; 
    cout<<"\n";
    
    cout<< "Ingrese segundo numero: ";
    cin >> O2; 
    cout<<"\n";


    Operador *dat = new Operador(O1,O2);
    Operador *dat1 = new Operador();

    dat1->CalcDat(*dat);
    

}
    
