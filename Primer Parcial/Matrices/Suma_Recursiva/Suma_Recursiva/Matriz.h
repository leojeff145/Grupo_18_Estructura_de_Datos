#pragma once

template <class T>
class Matriz
{
public:
	Matriz(int filas, int columnas);
	Matriz();
	~Matriz();	
	int getMatriz(void);
	void setMatriz(int newMatriz);
	void llenar_matriz();
	void mostrar_matriz();
	int valInt(char* input);
	Matriz<T> operator+(Matriz<T> &mat);
	Matriz<T> operator*(Matriz<T> &mat1);
	//int suma_rec(Matriz<T> &matrix);
	//void suma_rec(Matriz<T> &m, Matriz<T> &m1, Matriz<T> &m2, int i ,int j);

protected:
private:
	int fila;
	int columna;
	T **matriz;
};

