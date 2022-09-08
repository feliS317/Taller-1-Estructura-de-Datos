#pragma once
#include "Profesor.h"
#include <iostream>

using namespace std;



class ListaProfesores
{
private:
	Profesor profesores[5];
	int count;
public:
	ListaProfesores();
	bool addProfesor(Profesor);
	Profesor findProfesor();

};