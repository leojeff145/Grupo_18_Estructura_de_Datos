#pragma once
#include "Nodo_Doble.h"
#include <functional>
#include <iostream>

#include <string>
#include <sstream>

using namespace std;





template<typename T>
class ListaCircularDoble
{
private:
	Nodo_Doble<T>* cabeza = nullptr;
	int size = 0;
public:
	ListaCircularDoble();
	//ListaCircularDoble(T dato);
	//~ListaCircularDoble();
	void insertarFinal(T dato);
	void insertarInicio(T dato);
	void insertarPosicion(int pos, T dat);
	void eliminarPosicion(int pos);
	void eliminar(std::function<bool(T dato)>);	
	void recorrer(std::function<void(T dato)>);	
	bool estaVacio();
	int total();
	
	Nodo_Doble<T>* getCabeza();
	Nodo_Doble<T>* getCola();
	Nodo_Doble<T>* obtenerNodo(int pos);
	Nodo_Doble<T>* buscar(std::function<bool(T dato)>);
};

template<typename T>
ListaCircularDoble<T>::ListaCircularDoble()
{
}

template<typename T>
void ListaCircularDoble<T>::insertarFinal(T dato)
{
	Nodo_Doble<T>* nodo = new Nodo_Doble<T>(dato);

	if (cabeza == nullptr) {
		cabeza = nodo;
		cabeza->set_anterior(cabeza);
		cabeza->set_siguiente(cabeza);
		size++;
	}
	else {
		Nodo_Doble<T>* cola = getCola();
		cola->set_siguiente(nodo);
		nodo->set_anterior(cola);
		nodo->set_siguiente(cabeza);
		cabeza->set_anterior(nodo);
		size++;
	}	
}

template<typename T>
void ListaCircularDoble<T>::insertarInicio(T dato)
{
	Nodo_Doble<T>* nodo = new Nodo_Doble<T>(dato);

	if (estaVacio()) {
		insertarFinal(dato);
		return;
	}
	
	Nodo_Doble<T>* aux = cabeza;

	cabeza = nodo;
	cabeza->set_siguiente(aux);
	cabeza->set_anterior(aux->set_anterior());
	aux->set_anterior()->set_siguiente(cabeza);
	aux->set_anterior(cabeza);
	size++;	
}

template<typename T>
void ListaCircularDoble<T>::insertarPosicion(int pos, T dato) 
{
    if (pos < 0 || pos >= size) 
    {
        return;
    }

    if (size == 1) 
    {
        insertarInicio(dato);
    }
    else if (pos == 0) 
    {
        insertarInicio(dato);
    }
    else if (pos == size - 1) 
    {
        insertarFinal(dato);
    }
    else 
    {
        Nodo_Doble<T>* objetivo = obtenerNodo(pos);
        Nodo_Doble<T>* anterior = objetivo->set_anterior();
        Nodo_Doble<T>* siguiente = objetivo->set_siguiente();
        Nodo_Doble<T>* nodo = new Nodo_Doble<T>(dato);

        anterior->set_siguiente(nodo);
        nodo->set_anterior(anterior);
        nodo->set_siguiente(objetivo);
        objetivo->set_anterior(nodo);
        size++;
    }
}

template<typename T>
void ListaCircularDoble<T>::eliminarPosicion(int index) 
{
    if (index < 0 || index >= size) {
        return;
    }

    if (index == 0 || size == 1) {
        if (size > 1) {
            Nodo_Doble<T>* aux = cabeza;
            cabeza = cabeza->get_siguiente();
            cabeza->set_anterior(aux->get_anterior());
            aux->get_anterior()->set_siguiente(cabeza);
            delete aux;
        }
        else {
            delete cabeza;
            cabeza = nullptr;
        }
    }
    else if (index == size - 1) {
        Nodo_Doble<T>* objetivo = cabeza->get_anterior();
        Nodo_Doble<T>* aux = objetivo->get_anterior();
        cabeza->set_anterior(aux);
        aux->set_siguiente(cabeza);
        delete objetivo;
    }
    else {
        Nodo_Doble<T>* objetivo = obtenerNodo(index);
        Nodo_Doble<T>* anterior = objetivo->get_anterior();
        Nodo_Doble<T>* siguiente = objetivo->get_siguiente();

        delete objetivo;
        anterior->set_siguiente(siguiente);
        siguiente->set_anterior(anterior);
    }
    //cout << size << endl;
    size = size - 1;
    //cout << size << endl;
	
}

template<typename T>
void ListaCircularDoble<T>::eliminar(std::function<bool(T dato)> filtro)
{
    Nodo_Doble<T>* nodo = cabeza;
    int indice = 0;

    while (nodo != nullptr) 
    {
        bool eliminar = filtro(nodo->get_dato());

        if (eliminar) {
            //cout << indice << endl;
            eliminarPosicion(indice);
            return;
        }

        nodo = nodo->get_siguiente();
        indice++;
    }
	
	
}

template <typename T>
inline Nodo_Doble<T>* ListaCircularDoble<T>::getCabeza() {
    return cabeza;
}

template<typename T>
Nodo_Doble<T>* ListaCircularDoble<T>::getCola() {
    Nodo_Doble<T>* cola = cabeza;

    if (cola == nullptr) {
        return nullptr;
    }

    while (cola->get_siguiente() != cabeza) {
        cola = cola->get_siguiente();
    }

    return cola;
}

template<typename T>
Nodo_Doble<T>* ListaCircularDoble<T>::obtenerNodo(int indice) 
{
    if (indice < 0 || indice >= size) {
        return nullptr;
    }

    int i = 0;
    Nodo_Doble<T>* nodo = cabeza;

    if (nodo == nullptr)
        return nullptr;

    do {
        if (i == indice) {
            return nodo;
        }

        nodo = nodo->get_siguiente();
        i++;
    } while (nodo != cabeza);

    return nullptr;
}

template<typename T>
Nodo_Doble<T>* ListaCircularDoble<T>::buscar(std::function<bool(T dato)> filtro) {
    Nodo_Doble<T>* nodo = cabeza;

    if (nodo == nullptr) 
    {
        return nullptr;
    }

    do {
        if (filtro(nodo->get_dato())) 
        {
            return nodo;
        }

        nodo = nodo->get_siguiente();
    } while (nodo != cabeza);

    return nullptr;
}

template<typename T>
void ListaCircularDoble<T>::recorrer(std::function<void(T dato)> llamada)
{
    Nodo_Doble<T>* nodo = cabeza;

    if (nodo == nullptr) 
    {
        return;
    }

    do {
        llamada(nodo->get_dato());
        nodo = nodo->get_siguiente();
    } while (nodo != cabeza);
}

template<typename T>
bool ListaCircularDoble<T>::estaVacio() {
    return size == 0;
}

template<typename T>
int ListaCircularDoble<T>::total() {
    return size;
}

