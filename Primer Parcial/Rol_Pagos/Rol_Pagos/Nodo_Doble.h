#pragma once

template <typename T>
class Nodo_Doble 
{
private:
	T dato;
	Nodo_Doble<T>* siguiente = nullptr;
	Nodo_Doble<T>* anterior = nullptr;
public:
	Nodo_Doble(void);
	Nodo_Doble(T nuvDato);
	~Nodo_Doble(void);
	void set_dato(T nuvDato);
	void set_siguiente(Nodo_Doble<T>* sig);
	void set_anterior(Nodo_Doble<T>* ant);
	T get_dato();
	Nodo_Doble<T>* get_siguiente();
	Nodo_Doble<T>* get_anterior();
};

template <typename T>
Nodo_Doble<T>::Nodo_Doble(void)
{
}

template <typename T>
Nodo_Doble<T>::Nodo_Doble(T nuvDato)
{
	dato = nuvDato;
}

template <typename T>
Nodo_Doble<T>::~Nodo_Doble(void)
{
}

template <typename T>
void Nodo_Doble<T>::set_dato(T nuvDato)
{
	dato = nuvDato;
}

template <typename T>
void Nodo_Doble<T>::set_siguiente(Nodo_Doble<T>* sig)
{
	siguiente = sig;
}

template <typename T>
void Nodo_Doble<T>::set_anterior(Nodo_Doble<T>* ant)
{
	anterior = ant;
}

template <typename T>
T Nodo_Doble<T>::get_dato()
{
	return dato;
}

template <typename T>
Nodo_Doble<T>* Nodo_Doble<T>::get_siguiente()
{
	return siguiente;
}

template <typename T>
Nodo_Doble<T>* Nodo_Doble<T>::get_anterior()
{
	return anterior;
}


