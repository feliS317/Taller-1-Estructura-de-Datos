#pragma once
#include <iostream>

/*
	Nota:
	> Esta clase hace uso de notaci�n o templates gen�ricos,
	por esta misma raz�n (y por razones del compilador), pueden
	existir problemas al utilizar un archivo .cpp para definir los m�todos.
	Simplemente se opt� por definir todo en el header.
*/

template <class T>
class Vector {
private:
	int size; // Tama�o total de la lista
	T* lista; // Lista de elementos
	T* cache; // Puntero hacia el �ltimo objeto trabajado
public:
	int length; // Tama�o ocupado de la lista
	
	Vector(int _size); // Constructor
	T& operator[](int index); // Operador []
	bool isFull(); // Permite saber si una lista est� llena
	int indexOf(T object); // Permite obtener el �ndice de un elemento en la lista
	void add(T object); // A�ade un elemento al final de la lista
	bool remove(T object); // Remueve un elemento de la lista
	bool cacheExists(); // Revisa si el cache existe y es distinto de null
	T& getCache(); // Obtiene el valor del cache
};


template <class T>
Vector<T>::Vector(int _size) {
	size = _size;
	length = 0;
	lista = new T[size];
	cache = nullptr;
};

template <class T>
T& Vector<T>::operator[](int index)
{
	cache = &lista[index]; // Cacheamos el elemento obtenido
	return lista[index]; // Devolvemos el elemento de la lista
};

template <class T>
bool Vector<T>::isFull()
{
	return length == size; // Revisa si la lista est� llena
};

template <class T>
int Vector<T>::indexOf(T object)
{
	for (int i = 0; i < length; i++) { // Por cada elemento
		if (&lista[i] == &object) {
			return i;
		}
	}

	return -1;
};

template <class T>
void Vector<T>::add(T object) {
	lista[length] = object; // A�ade el objeto a la �ltima posici�n disponible
	cache = &lista[length]; // Cachea el elemento a�adido
	length++; // Aumenta la cuenta de objetos en uno
};

template <class T>
bool Vector<T>::remove(T object) {
	int pos = -1;
	for (int i = 0; i < length; i++)
	{
		if (lista[i] == object)
		{
			pos = i;
			break;
		}
	}
	if (pos == -1)
	{
		return false;
	}
	for (int i = pos; i < length-1; i++)
	{
		lista[i] = lista[i + 1];
	}
	// TODO falta probar el codigo de quitar un elemento

	length--; // Reduce la cuenta de objetos en uno
	return true;
};


template <class T>
bool Vector<T>::cacheExists() {
	return !(!cache);
}

template <class T>
T& Vector<T>::getCache() {
	return *cache;
}