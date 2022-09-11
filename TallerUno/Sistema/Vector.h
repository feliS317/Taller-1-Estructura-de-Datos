#pragma once
#include <iostream>

/*
	Nota:
	> Esta clase hace uso de notación o templates genéricos,
	por esta misma razón (y por razones del compilador), pueden
	existir problemas al utilizar un archivo .cpp para definir los métodos.
	Simplemente se optó por definir todo en el header.
*/

template <class T>
class Vector {
private:
	int size; // Tamaño total de la lista
	T* lista; // Lista de elementos
	T* cache; // Puntero hacia el último objeto trabajado
public:
	int length; // Tamaño ocupado de la lista
	
	Vector(int _size); // Constructor
	T& operator[](int index); // Operador []
	bool isFull(); // Permite saber si una lista está llena
	int indexOf(T object); // Permite obtener el índice de un elemento en la lista
	void add(T object); // Añade un elemento al final de la lista
	void remove(T object); // Remueve un elemento de la lista
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
	return length == size; // Revisa si la lista está llena
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
	lista[length] = object; // Añade el objeto a la última posición disponible
	cache = &lista[length]; // Cachea el elemento añadido
	length++; // Aumenta la cuenta de objetos en uno
};

template <class T>
void Vector<T>::remove(T object) {
	if (cache == &lista[length - 1]) { // Si el cache apuntaba al objeto que se eliminará
		cache = nullptr; // El cache apuntará a null
	}

	// TODO falta añadir el codigo de quitar un elemento

	length--; // Reduce la cuenta de objetos en uno
};


template <class T>
bool Vector<T>::cacheExists() {
	return !(!cache);
}

template <class T>
T& Vector<T>::getCache() {
	return *cache;
}