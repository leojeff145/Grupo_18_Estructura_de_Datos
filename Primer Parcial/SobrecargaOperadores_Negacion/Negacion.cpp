
#include "Negacion.h"
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
using namespace std;
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

void Negacion::operator!()
{
   bool a=true,b=false,c,d;
   Negacion *objOp = new Negacion(a,b);
   cout<<"val1: "<<a<<endl;
   cout<<"val2: "<<b<<endl; 
   cout<<"***********************************************"<<endl;
   c=!objOp->getVal1();
   d=!objOp->getVal2();
   cout<<"val1: "<<c<<endl;
   cout<<"val2: "<<d<<endl;   
}

/*void Negacion::imprimir(Negacion *objOp)
{
   
}*/