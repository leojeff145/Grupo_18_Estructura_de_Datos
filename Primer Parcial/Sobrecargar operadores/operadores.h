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

class Operador
{    int A1;
     int B2;
   public:
     Operador(int a, int b);
     void setA(int);
     void setB(int);
     int getA(void);
     int getB(void);
     Operador();
     void CalcDat(Operador D1);
     int operator ^ (Operador);
};