/***********************************************************************
 * Module:  Matriz.h
 * Author:  jeffe
 * Modified: domingo, 13 de noviembre de 2022 19:50:55
 * Purpose: Declaration of the class Matriz
 ***********************************************************************/

#if !defined(__Suma_Matrices2_Matriz_h)
#define __Suma_Matrices2_Matriz_h

#include <Operacion.h>

class Matriz : public Operacion
{
public:
   Matriz();
   ~Matriz();
   int getMatriz(void);
   void setMatriz(int newMatriz);
   int suma_rec(Matriz matriz);
   int producto_rec(Matriz matriz);

protected:
private:
   int matriz;


};

#endif