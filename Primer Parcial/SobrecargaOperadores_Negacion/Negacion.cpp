
#include "Negacion.h"
#include <stdint.h>
using namespace std;

Negacion::Negacion(bool val_a, bool val_b)
{
  this->val1=val_a;
  this->val2=val_b; 
}

Negacion::Negacion()
{
   
}

Negacion::~Negacion()
{   

}


bool Negacion::getVal2(void)
{
   return val2;
}


void Negacion::setVal2(bool newVal2)
{
   val2 = newVal2;
}


bool Negacion::getVal1(void)
{
   return val1;
}


void Negacion::setVal1(bool newVal1)
{
   val1 = newVal1;
}

Negacion Negacion::operator!()
{
   bool a=true,b=false;
   Negacion *objOp = new Negacion(a,b);
   
   return objOp->operator!();
}

void Negacion::imprimir(Negacion *objOp)
{
   
}