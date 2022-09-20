#pragma once
#include <iostream>
#include "string"
#include "Ramo.h"

using std::string;

class Persona
{
protected:
	string nombre;
	string apellido;
	int ramosTomados;
public:
	Persona() = default;
	Persona(string, string);
	string getNombre();
	void setNombre(string);
	string getApellido();
	void setApellido(string);
	string getNombreCompleto();
	int getRamosTomados();
	void setRamosTomados(int);
	virtual bool addRamo(Ramo);
};