#pragma once
#include <iostream>
#include <string>

#include "Persona.h"
#include "Ramo.h"
#include "../Sistema/Vector.h"

using std::string;

class Alumno : public Persona
{
private:
	int semestre;
	int edad;
	Vector<Ramo*> ramos = Vector<Ramo*>(5);
public:
	Alumno() = default;
	Alumno(string, string, int, int);
	int getSemestre();
	void setSemestre(int);
	int getEdad();
	void setEdad(int);
	Vector<Ramo*> getRamos();
	bool addRamo(Ramo*);
};