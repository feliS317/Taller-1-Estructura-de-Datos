#include "Alumno.h"

Alumno::Alumno(string _nombre, string _apellido, int _semestre, int _edad) : Persona(_nombre, _apellido)
{
    semestre = _semestre;
    edad = _edad;
}