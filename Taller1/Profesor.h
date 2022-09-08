#pragma once
#include <iostream>
#include <string>
#include "Persona.h"
#include "Ramo.h"
using namespace std;

class Profesor:public Persona
{
private:
	Ramo ramos[3];
public:
	Profesor() = default;
	Profesor(string, string);

};
