#pragma once
#include <iostream>
#include <istream>
#include <string>

#include "Empleado.h"
#include "RolDePago.h"

#include "ListaCircularDoble.h"

#include "ControladorReportes.h"
#include "ControladorRegistro.h"
#include "Validacion.h"
class Menu
{
public:    
    void menuPrincipaListaCircular();
    void menuAdministradorListaCircular();
    void menuOPAdminRegistroListaCircular();
    void menuOPAdminReportesListaCircular();
};

