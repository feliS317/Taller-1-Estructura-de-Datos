#pragma once
#include <iostream>
#include <string>

#include "Persona.h"
#include "Ramo.h"
#include "../Sistema/Vector.h"

using std::string;

class Profesor : public Persona
{
private:
	Vector<Ramo*> ramos = Vector<Ramo*>(3);
public:
	Profesor() = default;
	Profesor(string, string);
	Vector<Ramo*> getRamos();
	bool addRamo(Ramo*);
	bool removeRamo(Ramo*);
};