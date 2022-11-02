#include "Negacion.cpp"
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
using namespace std;

int main()
{
    Negacion *objOp = new Negacion();
    objOp->operator!();
    //cout<<objOp->getVal1()<<"   "<<objOp->getVal2()<<endl;

    return 0;
}

