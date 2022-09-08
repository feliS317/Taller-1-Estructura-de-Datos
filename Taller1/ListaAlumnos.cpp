#include "ListaAlumnos.h"

ListaAlumnos::ListaAlumnos()
{
	count = 0;
}

bool ListaAlumnos::addAlumno(Alumno alumno)
{
	if (count < 100)
	{
		alumnos[count] = alumno;
		count++;
		return true;
	}
	return false;

}

Alumno ListaAlumnos::findAlumno()
{
	return Alumno();
}
