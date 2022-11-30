#include "Menu.h"
#include <iostream>
#include <istream>
#include <string>

using namespace std;

ControladorReportes controladorReporte;
ControladorRegistro controladorRegistro;


void Menu::menuPrincipaListaCircular() {
    int opcion;
    bool repetir = true;

    do
    {
        system("cls");
        cout << "\t\t\t--------------" << endl;
        cout << "\n\n\t\t\tROL DE PAGOS" << endl;
        cout << "\t\t\t--------------" << endl;
        cout << "\n\t  1. INGRESO DE PERSONAL" << endl;
        cout << "\t  2. CONSULTAR ROL DE PAGOS" << endl;
        cout << "\t  0. REGRESAR" << endl;

        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            menuAdministradorListaCircular();
            break;

        case 2:
            controladorReporte.buscarRolDePago();
            system("pause>nul");
            break;

        case 0:
            repetir = false;
            break;
        }
    } while (repetir);

}
void Menu::menuAdministradorListaCircular() {
    int opcion;
    bool repetir = true;

    do {
        system("cls");
        cout << "\t\t\t--------------" << endl;
        cout << "\n\n\t\t\tMENU DE PERSONAL" << endl;
        cout << "\t\t\t--------------" << endl;
        cout << "\n\t  1. REGISTRO" << endl;
        cout << "\t  2. MOSTRAR EMPLEADOS" << endl;
        cout << "\t  0. REGRESAR" << endl;

        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            menuOPAdminRegistroListaCircular();
            break;

        case 2:
            menuOPAdminReportesListaCircular();
            break;

        case 0:
            repetir = false;
            break;
        }
    } while (repetir);
}
void Menu::menuOPAdminRegistroListaCircular() {
    int opcion;
    bool repetir = true;

    do {
        system("cls");
        cout << "\t\t\t--------------" << endl;
        cout << "\n\n\t\t\tREGISTRO DE PERSONAL" << endl;
        cout << "\t\t\t--------------" << endl;
        cout << "\n\t  1. REGISTRAR EMPLEADO" << endl;
        cout << "\t  2. REGISTRAR ROL DE PAGO" << endl;
        cout << "\t  0. REGRESAR" << endl;

        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            controladorRegistro.registrarEmpleado();
            system("pause>nul");
            break;

        case 2:
            controladorRegistro.registrarRolPago();
            system("pause>nul");
            break;

        case 0:
            repetir = false;
            break;
        }
    } while (repetir);

}
void Menu::menuOPAdminReportesListaCircular() {
    int opcion;
    bool repetir = true;

    do {
        system("cls");
        cout << "\t\t\t--------------" << endl;
        cout << "\n\n\t\t\tRGISTRO DE PERSONAL" << endl;
        cout << "\t\t\t--------------" << endl;
        cout << "\n\t  1. VER EMPLEADOS" << endl;
        cout << "\t  2. BUSCAR EMPLEADO" << endl;
        cout << "\t  0. REGRESAR" << endl;

        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            controladorReporte.mostrarClientes();
            system("pause>nul");
            break;

        case 2:
            controladorReporte.buscarRolDePago();
            system("pause>nul");
            break;

        case 0:
            repetir = false;
            break;
        }
    } while (repetir);
}
