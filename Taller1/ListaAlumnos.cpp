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

bool ListaAlumnos::compare(Alumno alumno1, Alumno alumno2) {

	

}

Alumno ListaAlumnos::findAlumno(ListaAlumnos* &listaAlumnos, Alumno* &alumno) // Cómo comparo las dos weas .-.
{
	for (int i = 0; i < count; i++) {
		if (compare(listaAlumnos.[i],alumno) {
		
			return Alumno();
		}
	}

	return Alumno();
}

