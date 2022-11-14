/***********************************************************************
 * Module:  Operacion.h
 * Author:  jeffe
 * Modified: domingo, 13 de noviembre de 2022 19:50:55
 * Purpose: Declaration of the class Operacion
 ***********************************************************************/

#if !defined(__Suma_Matrices2_Operacion_h)
#define __Suma_Matrices2_Operacion_h

#include <Matriz.h>

class Operacion
{
public:
   virtual int suma_rec(Matriz matriz)=0;
   virtual int producto_rec(Matriz matriz)=0;

protected:
private:

};

#endif