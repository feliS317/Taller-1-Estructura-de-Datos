#pragma once
#include <iostream>
#include "string"
#include "Ramo.h"
#include "../Sistema/Vector.h"

using std::string;

class Persona
{
protected:
	string nombre;
	string apellido;
public:
	Persona() = default;
	Persona(string, string);
	string getNombre();
	void setNombre(string);
	string getApellido();
	void setApellido(string);
	string getNombreCompleto();
	virtual Vector<Ramo*> getRamos();
};