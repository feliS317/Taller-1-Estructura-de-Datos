#pragma once
#include "Alumno.h"
#include <iostream>

using namespace std;
class ListaAlumnos
{
private:
	Alumno alumnos[100];
	int count;
public:
	ListaAlumnos();
	bool addAlumno(Alumno);
	bool compare(Alumno, Alumno);
	Alumno findAlumno(ListaAlumnos*& listaAlumnos, Alumno*& alumno);
};